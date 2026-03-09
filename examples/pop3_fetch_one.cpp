#include <mailio/message.hpp>
#include <mailio/pop3.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
using namespace mailio;

int main() {
	std::string server = "pop.163.com";
	uint16_t port = 995;
	std::string username = "w163testwlh@163.com";
	std::string password = "FJKUVZPEOMEGUGKG"; // 替换为您的授权码
	std::string save_path = "./emails/";
	std::filesystem::create_directories(save_path);

	//try {
		// 创建 POP3 SSL 客户端
		pop3s conn(server, port);
		conn.authenticate(username, password, pop3s::auth_method_t::LOGIN);

		// 获取统计信息（邮件总数和总大小）
		auto stats = conn.statistics();  // 使用 auto 避免类型问题
		std::cout << "Total emails: " << stats.messages_no << std::endl;

		// 遍历所有邮件
		for (size_t i = 1; i <= stats.messages_no; ++i) {
			message msg;
			// 获取第 i 封邮件原始内容（RFC 822）
			conn.fetch(i, msg);  // 两个参数版本

			// 保存为 .eml 文件
			std::string filename = save_path + "email_" + std::to_string(i) + ".eml";
			std::ofstream outfile(filename, std::ios::binary);
			if (!outfile.is_open()) {
				std::cerr << "无法创建文件: " << filename << std::endl;
				continue;
			}

			std::string fmtStr;
			msg.format(fmtStr);
			outfile.write(fmtStr.data(), fmtStr.size());
			outfile.close();

			std::cout << "邮件 " << i << " 已保存至 " << filename << std::endl;

			// 可选：标记删除
			// conn.dele(i);
		}

		// 可选：退出并提交删除
		// conn.quit();

//	}
//	catch (const std::exception& e) {
//		std::cerr << "错误: " << e.what() << std::endl;
//		return -1;
//	}

	return 0;
}
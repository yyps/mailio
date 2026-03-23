#ifndef MAILIO_HELPER_HPP
#define MAILIO_HELPER_HPP

#include <mailio/message.hpp>
#include <mailio/pop3.hpp>
#include <mailio/imap.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <regex>
#include <sstream>

using namespace mailio;

/**
 * 邮箱协议枚举类型
 */
enum EmailProtocol
{
	EP_POP3,
	EP_IMAP
};

/**
 * Mailio 邮件操作助手类
 *
 * 功能：
 * - 支持 POP3 和 IMAP 协议
 * - 支持 SSL/TLS 加密连接
 * - 将邮箱所有邮件保存为 .eml 文件
 * - 完善的异常处理和错误信息传递
 */
class MailioHelper
{
public:
	/**
	 * 拉取远程邮箱所有邮件并保存为本地 eml 文件
	 *
	 * @param mailAddr   邮箱地址 (例如: user@example.com)
	 * @param authCode   邮箱授权码/密码
	 * @param ep         协议类型 (见EmailProtocol)
	 * @param savePath   保存路径，不存在则创建
	 * @param withSSL    是否使用 SSL 连接
	 * @param errorMsg   [输出] 异常信息，如果操作成功则为空字符串
	 *
	 * @return 成功返回 true，失败返回 false
	 */
	static bool fetchMailsToEmlFiles(
		const std::string& mailAddr,
		const std::string& authCode,
		const EmailProtocol& ep,
		const std::string& savePath,
		bool withSSL,
		std::string& errorMsg)
	{
		try
		{
			// 从邮箱地址中提取服务器地址
			std::string server = extractServer(ep, mailAddr);
			if (server.empty())
			{
				errorMsg = "Can not extract mail sever: " + mailAddr;
				return false;
			}

			// 确定端口号
			uint16_t port = determinePort(ep, withSSL);
			if (port == 0)
			{
				//errorMsg = "无效的协议类型";
				return false;
			}

			// 创建保存目录
			std::error_code ec;
			if (!std::filesystem::exists(savePath, ec))
			{
				if (!std::filesystem::create_directories(savePath, ec))
				{
					errorMsg = "Create directoriy failed: " + savePath + ", ec: " + ec.message();
					return false;
				}
			}

			// 根据协议类型处理
			if (ep == EP_POP3)
			{
				return fetchWithPOP3(server, port, mailAddr, authCode, savePath, withSSL, errorMsg);
			}
			else if (ep == EP_IMAP)
			{
				return fetchWithIMAP(server, port, mailAddr, authCode, savePath, withSSL, errorMsg);
			}
			else
			{
				errorMsg = "unkown email protocol";
				return false;
			}
		}
		catch (const pop3_error& e)
		{
			errorMsg = std::string("POP3 error: ") + e.what();
			return false;
		}
		catch (const imap_error& e)
		{
			errorMsg = std::string("IMAP error: ") + e.what();
			return false;
		}
		catch (const dialog_error& e)
		{
			errorMsg = std::string("net error: ") + e.what();
			return false;
		}
		catch (const std::filesystem::filesystem_error& e)
		{
			errorMsg = std::string("filesystem: ") + e.what();
			return false;
		}
		catch (const std::exception& e)
		{
			errorMsg = std::string("other error: ") + e.what();
			return false;
		}
	}

private:
	/**
	 * 从邮箱地址提取服务器地址
	 *
	 * @param mailAddr 邮箱地址
	 * @return 服务器地址，如果提取失败返回空字符串
	 */
	static std::string extractServer(EmailProtocol ep, const std::string& mailAddr)
	{
		// 从邮箱地址中提取域名部分
		size_t atPos = mailAddr.find('@');
		if (atPos == std::string::npos)
		{
			return "";
		}

		std::string domain = mailAddr.substr(atPos + 1);
		if (!domain.empty())
		{
			if (EP_POP3 == ep)
			{
				return "pop." + domain;
			}
			else if (EP_IMAP == ep)
			{
				return "imap." + domain;
			}
		}
		return "";
	}

	/**
	 * 确定端口号
	 *
	 * @param ep     协议类型
	 * @param withSSL 是否使用 SSL
	 * @return 端口号，如果无效返回 0
	 */
	static uint16_t determinePort(const EmailProtocol& ep, bool withSSL)
	{
		if (ep == EP_POP3)
		{
			return withSSL ? 995 : 110;
		}
		else if (ep == EP_IMAP)
		{
			return withSSL ? 993 : 143;
		}
		return 0;
	}

	/**
	 * 使用 POP3 协议获取邮件
	 */
	static bool fetchWithPOP3(
		const std::string& server,
		uint16_t port,
		const std::string& mailAddr,
		const std::string& authCode,
		const std::string& savePath,
		bool withSSL,
		std::string& errorMsg)
	{
		try
		{
			if (withSSL)
			{
				pop3s conn(server, port);
				conn.authenticate(mailAddr, authCode, pop3s::auth_method_t::LOGIN);
				return savePOP3Mails(conn, savePath);
			}
			else
			{
				pop3 conn(server, port);
				conn.authenticate(mailAddr, authCode, pop3::auth_method_t::LOGIN);
				return savePOP3Mails(conn, savePath);
			}
		}
		catch (const pop3_error& e)
		{
			errorMsg = std::string("POP3 operate error: ") + e.what();
			return false;
		}
		catch (const std::exception& e)
		{
			errorMsg = std::string("POP3 other error: ") + e.what();
			return false;
		}
	}

	/**
	 * 保存 POP3 邮件到文件
	 */
	template<typename POP3Type>
	static bool savePOP3Mails(POP3Type& conn, const std::string& savePath)
	{
		// 获取统计信息（邮件总数和总大小）
		auto stats = conn.statistics();
		unsigned int totalMails = stats.messages_no;

		if (totalMails == 0)
		{
			return true;  // 没有邮件也算成功
		}

		// 遍历所有邮件
		int saveCnt = 0;
		for (unsigned int i = 1; i <= totalMails; ++i)
		{
			message msg;
			conn.fetch(i, msg);

			// 保存为 .eml 文件
			std::string filename = savePath + "email_" + std::to_string(i) + ".eml";
			std::ofstream outfile(filename, std::ios::binary);
			if (!outfile.is_open())
			{
				throw std::runtime_error("Can not create eml file: " + filename);
			}

			std::string fmtStr;
			msg.format(fmtStr);
			outfile.write(fmtStr.data(), fmtStr.size());
			outfile.close();
		}
		if (saveCnt == 0)
		{
			return false;
		}
		return true;
	}

	/**
	 * 使用 IMAP 协议获取邮件
	 */
	static bool fetchWithIMAP(
		const std::string& server,
		uint16_t port,
		const std::string& mailAddr,
		const std::string& authCode,
		const std::string& savePath,
		bool withSSL,
		std::string& errorMsg)
	{
		try
		{
			if (withSSL)
			{
				imaps conn(server, port);
				conn.authenticate(mailAddr, authCode, imaps::auth_method_t::LOGIN);
				conn.regist_client("mail-check-mod", "1.0");// IMAP协议需要多这一步
				return saveIMAPMails(conn, savePath);
			}
			else
			{
				imap conn(server, port);
				conn.authenticate(mailAddr, authCode, imap::auth_method_t::LOGIN);
				conn.regist_client("mail-check-mod", "1.0");// IMAP协议需要多这一步
				return saveIMAPMails(conn, savePath);
			}
		}
		catch (const imap_error& e)
		{
			errorMsg = std::string("IMAP operate error: ") + e.what();
			return false;
		}
		catch (const std::exception& e)
		{
			errorMsg = std::string("IMAP other error: ") + e.what();
			return false;
		}
	}

	/**
	 * 保存 IMAP 邮件到文件
	 */
	template<typename IMAPType>
	static bool saveIMAPMails(IMAPType& conn, const std::string& savePath)
	{
		// 选择收件箱
		auto stats = conn.select("INBOX", true);
		auto dirs = conn.list_folders("INBOX");
		unsigned int totalMails = stats.messages_no;

		if (totalMails == 0)
		{
			return true;  // 没有邮件也算成功
		}

		// 遍历所有邮件
		int saveCnt = 0;
		for (unsigned int i = 1; i <= totalMails; ++i)
		{

			message msg;
			msg.line_policy(codec::line_len_policy_t::NONE);
			conn.fetch(i, msg);

			// 保存为 .eml 文件
			std::string filename = savePath + "email_" + std::to_string(i) + ".eml";
			std::ofstream outfile(filename, std::ios::binary);
			if (!outfile.is_open())
			{
				throw std::runtime_error("Can not create eml file: : " + filename);
			}

			std::string fmtStr;
			msg.format(fmtStr);
			outfile.write(fmtStr.data(), fmtStr.size());
			outfile.close();

			saveCnt++;
		}

		if (saveCnt == 0)
		{
			return false;
		}
		return true;
	}
};

#endif // MAILIO_HELPER_HPP

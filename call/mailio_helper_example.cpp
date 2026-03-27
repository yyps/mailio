#include "mailio/mailio_helper.hpp"
#include <iostream>

int main()
{
    {
		// 配置参数
		std::string mailAddr = "test163wlh1@163.com";  // 替换为你的邮箱地址
		std::string authCode = "CNOWUTNBDKBKIMGR";          // 替换为你的授权码/密码
		EmailProtocol protocol = EP_IMAP;                  // EP_POP3 或 EP_IMAP
		bool useSSL = true;                                // 是否使用 SSL
		std::string savePath = "./test163wlh1_imap_ssl/";                // 保存路径

		// 用于接收错误信息
		std::string errorMsg;
		std::cout << "start obtain emails..." << std::endl;
		std::cout << "mailAddr: " << mailAddr << std::endl;
		std::cout << "protocol: " << (protocol == EP_POP3 ? "POP3" : "IMAP") << std::endl;
		std::cout << "useSSL: " << (useSSL ? "yes" : "no") << std::endl;
		std::cout << "savePath: " << savePath << std::endl;
		std::cout << std::endl;

		// 调用 helper 类获取邮件
		bool success = MailioHelper::fetchMailsToEmlFiles(
			mailAddr,
			authCode,
			protocol,
			savePath,
			useSSL,
			errorMsg
		);

		if (success)
		{
			std::cout << "========================================" << std::endl;
			std::cout << "email obtain success!" << std::endl;
			std::cout << "========================================" << std::endl;
		}
		else
		{
			std::cout << "========================================" << std::endl;
			std::cout << "email obtain failed!" << std::endl;
			std::cout << "error message: " << errorMsg << std::endl;
			std::cout << "========================================" << std::endl;
		}
    }

	{
		// 配置参数
		std::string mailAddr = "test163wlh1@163.com";  // 替换为你的邮箱地址
		std::string authCode = "CNOWUTNBDKBKIMGR";          // 替换为你的授权码/密码
		EmailProtocol protocol = EP_IMAP;                  // EP_POP3 或 EP_IMAP
		bool useSSL = false;                                // 是否使用 SSL
		std::string savePath = "./test163wlh1_imap/";                // 保存路径

		// 用于接收错误信息
		std::string errorMsg;
		std::cout << "start obtain emails..." << std::endl;
		std::cout << "mailAddr: " << mailAddr << std::endl;
		std::cout << "protocol: " << (protocol == EP_POP3 ? "POP3" : "IMAP") << std::endl;
		std::cout << "useSSL: " << (useSSL ? "yes" : "no") << std::endl;
		std::cout << "savePath: " << savePath << std::endl;
		std::cout << std::endl;

		// 调用 helper 类获取邮件
		bool success = MailioHelper::fetchMailsToEmlFiles(
			mailAddr,
			authCode,
			protocol,
			savePath,
			useSSL,
			errorMsg
		);

		if (success)
		{
			std::cout << "========================================" << std::endl;
			std::cout << "email obtain success!" << std::endl;
			std::cout << "========================================" << std::endl;
		}
		else
		{
			std::cout << "========================================" << std::endl;
			std::cout << "email obtain failed!" << std::endl;
			std::cout << "error message: " << errorMsg << std::endl;
			std::cout << "========================================" << std::endl;
		}
	}

	{
		// 配置参数
		std::string mailAddr = "test163wlh1@163.com";  // 替换为你的邮箱地址
		std::string authCode = "CNOWUTNBDKBKIMGR";          // 替换为你的授权码/密码
		EmailProtocol protocol = EP_POP3;                  // EP_POP3 或 EP_IMAP
		bool useSSL = false;                                // 是否使用 SSL
		std::string savePath = "./test163wlh1_pop/";                // 保存路径

		// 用于接收错误信息
		std::string errorMsg;
		std::cout << "start obtain emails..." << std::endl;
		std::cout << "mailAddr: " << mailAddr << std::endl;
		std::cout << "protocol: " << (protocol == EP_POP3 ? "POP3" : "IMAP") << std::endl;
		std::cout << "useSSL: " << (useSSL ? "yes" : "no") << std::endl;
		std::cout << "savePath: " << savePath << std::endl;
		std::cout << std::endl;

		// 调用 helper 类获取邮件
		bool success = MailioHelper::fetchMailsToEmlFiles(
			mailAddr,
			authCode,
			protocol,
			savePath,
			useSSL,
			errorMsg
		);

		if (success)
		{
			std::cout << "========================================" << std::endl;
			std::cout << "email obtain success!" << std::endl;
			std::cout << "========================================" << std::endl;
		}
		else
		{
			std::cout << "========================================" << std::endl;
			std::cout << "email obtain failed!" << std::endl;
			std::cout << "error message: " << errorMsg << std::endl;
			std::cout << "========================================" << std::endl;
		}
	}

	{
		// 配置参数
		std::string mailAddr = "test163wlh1@163.com";  // 替换为你的邮箱地址
		std::string authCode = "CNOWUTNBDKBKIMGR";          // 替换为你的授权码/密码
		EmailProtocol protocol = EP_POP3;                  // EP_POP3 或 EP_IMAP
		bool useSSL = true;                                // 是否使用 SSL
		std::string savePath = "./test163wlh1_pop_ssl/";                // 保存路径

		// 用于接收错误信息
		std::string errorMsg;
		std::cout << "start obtain emails..." << std::endl;
		std::cout << "mailAddr: " << mailAddr << std::endl;
		std::cout << "protocol: " << (protocol == EP_POP3 ? "POP3" : "IMAP") << std::endl;
		std::cout << "useSSL: " << (useSSL ? "yes" : "no") << std::endl;
		std::cout << "savePath: " << savePath << std::endl;
		std::cout << std::endl;

		// 调用 helper 类获取邮件
		bool success = MailioHelper::fetchMailsToEmlFiles(
			mailAddr,
			authCode,
			protocol,
			savePath,
			useSSL,
			errorMsg
		);

		if (success)
		{
			std::cout << "========================================" << std::endl;
			std::cout << "email obtain success!" << std::endl;
			std::cout << "========================================" << std::endl;
		}
		else
		{
			std::cout << "========================================" << std::endl;
			std::cout << "email obtain failed!" << std::endl;
			std::cout << "error message: " << errorMsg << std::endl;
			std::cout << "========================================" << std::endl;
		}
	}

	{
		// 配置参数
		std::string mailAddr = "w126testwlh@126.com";  // 替换为你的邮箱地址
		std::string authCode = "PPWNEBXSTPPVIKWS";          // 替换为你的授权码/密码
		EmailProtocol protocol = EP_IMAP;                  // EP_POP3 或 EP_IMAP
		bool useSSL = true;                                // 是否使用 SSL
		std::string savePath = "./w126testwlh_imap_ssl/";                // 保存路径

		// 用于接收错误信息
		std::string errorMsg;
		std::cout << "start obtain emails..." << std::endl;
		std::cout << "mailAddr: " << mailAddr << std::endl;
		std::cout << "protocol: " << (protocol == EP_POP3 ? "POP3" : "IMAP") << std::endl;
		std::cout << "useSSL: " << (useSSL ? "yes" : "no") << std::endl;
		std::cout << "savePath: " << savePath << std::endl;
		std::cout << std::endl;

		// 调用 helper 类获取邮件
		bool success = MailioHelper::fetchMailsToEmlFiles(
			mailAddr,
			authCode,
			protocol,
			savePath,
			useSSL,
			errorMsg
		);

		if (success)
		{
			std::cout << "========================================" << std::endl;
			std::cout << "email obtain success!" << std::endl;
			std::cout << "========================================" << std::endl;
		}
		else
		{
			std::cout << "========================================" << std::endl;
			std::cout << "email obtain failed!" << std::endl;
			std::cout << "error message: " << errorMsg << std::endl;
			std::cout << "========================================" << std::endl;
		}
	}

	{
		// 配置参数
		std::string mailAddr = "w126testwlh@126.com";  // 替换为你的邮箱地址
		std::string authCode = "PPWNEBXSTPPVIKWS";          // 替换为你的授权码/密码
		EmailProtocol protocol = EP_IMAP;                  // EP_POP3 或 EP_IMAP
		bool useSSL = false;                                // 是否使用 SSL
		std::string savePath = "./w126testwlh_imap/";                // 保存路径

		// 用于接收错误信息
		std::string errorMsg;
		std::cout << "start obtain emails..." << std::endl;
		std::cout << "mailAddr: " << mailAddr << std::endl;
		std::cout << "protocol: " << (protocol == EP_POP3 ? "POP3" : "IMAP") << std::endl;
		std::cout << "useSSL: " << (useSSL ? "yes" : "no") << std::endl;
		std::cout << "savePath: " << savePath << std::endl;
		std::cout << std::endl;

		// 调用 helper 类获取邮件
		bool success = MailioHelper::fetchMailsToEmlFiles(
			mailAddr,
			authCode,
			protocol,
			savePath,
			useSSL,
			errorMsg
		);

		if (success)
		{
			std::cout << "========================================" << std::endl;
			std::cout << "email obtain success!" << std::endl;
			std::cout << "========================================" << std::endl;
		}
		else
		{
			std::cout << "========================================" << std::endl;
			std::cout << "email obtain failed!" << std::endl;
			std::cout << "error message: " << errorMsg << std::endl;
			std::cout << "========================================" << std::endl;
		}
	}

	{
		// 配置参数
		std::string mailAddr = "w126testwlh@126.com";  // 替换为你的邮箱地址
		std::string authCode = "PPWNEBXSTPPVIKWS";          // 替换为你的授权码/密码
		EmailProtocol protocol = EP_POP3;                  // EP_POP3 或 EP_IMAP
		bool useSSL = true;                                // 是否使用 SSL
		std::string savePath = "./w126testwlh_pop_ssl/";                // 保存路径

		// 用于接收错误信息
		std::string errorMsg;
		std::cout << "start obtain emails..." << std::endl;
		std::cout << "mailAddr: " << mailAddr << std::endl;
		std::cout << "protocol: " << (protocol == EP_POP3 ? "POP3" : "IMAP") << std::endl;
		std::cout << "useSSL: " << (useSSL ? "yes" : "no") << std::endl;
		std::cout << "savePath: " << savePath << std::endl;
		std::cout << std::endl;

		// 调用 helper 类获取邮件
		bool success = MailioHelper::fetchMailsToEmlFiles(
			mailAddr,
			authCode,
			protocol,
			savePath,
			useSSL,
			errorMsg
		);

		if (success)
		{
			std::cout << "========================================" << std::endl;
			std::cout << "email obtain success!" << std::endl;
			std::cout << "========================================" << std::endl;
		}
		else
		{
			std::cout << "========================================" << std::endl;
			std::cout << "email obtain failed!" << std::endl;
			std::cout << "error message: " << errorMsg << std::endl;
			std::cout << "========================================" << std::endl;
		}
	}

	{
		// 配置参数
		std::string mailAddr = "w126testwlh@126.com";  // 替换为你的邮箱地址
		std::string authCode = "PPWNEBXSTPPVIKWS";          // 替换为你的授权码/密码
		EmailProtocol protocol = EP_POP3;                  // EP_POP3 或 EP_IMAP
		bool useSSL = false;                                // 是否使用 SSL
		std::string savePath = "./w126testwlh_pop/";                // 保存路径

		// 用于接收错误信息
		std::string errorMsg;
		std::cout << "start obtain emails..." << std::endl;
		std::cout << "mailAddr: " << mailAddr << std::endl;
		std::cout << "protocol: " << (protocol == EP_POP3 ? "POP3" : "IMAP") << std::endl;
		std::cout << "useSSL: " << (useSSL ? "yes" : "no") << std::endl;
		std::cout << "savePath: " << savePath << std::endl;
		std::cout << std::endl;

		// 调用 helper 类获取邮件
		bool success = MailioHelper::fetchMailsToEmlFiles(
			mailAddr,
			authCode,
			protocol,
			savePath,
			useSSL,
			errorMsg
		);

		if (success)
		{
			std::cout << "========================================" << std::endl;
			std::cout << "email obtain success!" << std::endl;
			std::cout << "========================================" << std::endl;
		}
		else
		{
			std::cout << "========================================" << std::endl;
			std::cout << "email obtain failed!" << std::endl;
			std::cout << "error message: " << errorMsg << std::endl;
			std::cout << "========================================" << std::endl;
		}
	}
   
    return 0;
}

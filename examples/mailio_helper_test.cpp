#include "mailio/mailio_helper.hpp"
#include <iostream>
#include <vector>
#include <iomanip>

/**
 * 测试用例结构
 */
struct TestCase
{
    std::string name;
    std::string mailAddr;
    std::string authCode;
    EmailProtocol protocol;
    bool useSSL;
    std::string savePath;
};

/**
 * 打印测试用例信息
 */
void printTestCase(const TestCase& testCase)
{
    std::cout << "========================================" << std::endl;
    std::cout << "case name: " << testCase.name << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "mailAddr: " << testCase.mailAddr << std::endl;
    std::cout << "protocol: " << (testCase.protocol == EP_POP3 ? "POP3" : "IMAP") << std::endl;
    std::cout << "useSSL: " << (testCase.useSSL ? "yes" : "no") << std::endl;
    std::cout << "savePath: " << testCase.savePath << std::endl;
    std::cout << std::endl;
}

/**
 * 运行单个测试用例
 */
void runTestCase(const TestCase& testCase)
{
    printTestCase(testCase);

    std::string errorMsg;
    bool success = MailioHelper::fetchMailsToEmlFiles(
        testCase.mailAddr,
        testCase.authCode,
        testCase.protocol,
        testCase.savePath,
        testCase.useSSL,
        errorMsg
    );

    std::cout << "----------------------------------------" << std::endl;
    if (success)
    {
        std::cout << "emails obtain success!" << std::endl;
    }
    else
    {
        std::cout << "emails obtain failed!" << std::endl;
        std::cout << "errorMsg: " << errorMsg << std::endl;
    }
    std::cout << "----------------------------------------" << std::endl;
    std::cout << std::endl;
}

int main()
{
    std::cout << std::endl;
    std::cout << "╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║    Mailio Helper test cases" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
    std::cout << std::endl;

    // 测试用例 1: QQ 邮箱 + POP3 + SSL
    TestCase test1 = {
        "QQ POP3 SSL",
        "your_qq@qq.com",  // 替换为你的QQ邮箱
        "your_auth_code",   // 替换为你的授权码
        EP_POP3,
        true,
        "./emails/qq_pop3_ssl/"
    };

    // 测试用例 2: 163 邮箱 + POP3 + SSL
    TestCase test2 = {
        "163 POP3 SSL",
        "your_163@163.com",  // 替换为你的163邮箱
        "your_auth_code",     // 替换为你的授权码
        EP_POP3,
        true,
        "./emails/163_pop3_ssl/"
    };

    // 测试用例 3: QQ 邮箱 + IMAP + SSL
    TestCase test3 = {
        "QQ IMAP SSL",
        "your_qq@qq.com",  // 替换为你的QQ邮箱
        "your_auth_code",   // 替换为你的授权码
        EP_IMAP,
        true,
        "./emails/qq_imap_ssl/"
    };

    // 测试用例 4: 无效邮箱地址测试
    TestCase test4 = {
        "invalid addr",
        "invalid_email",
        "any_password",
        EP_IMAP,
        true,
        "./emails/invalid/"
    };

    // 测试用例集合
    std::vector<TestCase> testCases = {
        test1,
        test2,
        test3,
        test4
    };

    std::cout << "select test case (1-" << testCases.size() << ", 0=all): ";
    int choice;
    std::cin >> choice;

    if (choice == 0)
    {
        // 运行所有测试用例
        for (const auto& testCase : testCases)
        {
            runTestCase(testCase);
        }
    }
    else if (choice >= 1 && choice <= static_cast<int>(testCases.size()))
    {
        // 运行指定测试用例
        runTestCase(testCases[choice - 1]);
    }
    else
    {
        std::cout << "invalid choice!" << std::endl;
        return -1;
    }

    std::cout << std::endl;
    std::cout << "test over" << std::endl;
    std::cout << std::endl;

    return 0;
}

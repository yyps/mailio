# Mailio Helper 类使用指南

## 概述

`MailioHelper` 是一个封装了 mailio 库功能的辅助类，用于简化邮件获取操作。该类支持 POP3 和 IMAP 协议，支持 SSL/TLS 加密连接，可以将邮箱中的所有邮件保存为 .eml 文件。

## 主要功能

- ✅ 支持 POP3 和 IMAP 协议
- ✅ 支持 SSL/TLS 加密连接
- ✅ 自动识别常见邮箱服务器地址
- ✅ 将邮件保存为 .eml 格式文件
- ✅ 完善的异常处理机制
- ✅ 详细的错误信息反馈


## 使用方法

### 1. 基础使用

```cpp
#include "mailio/mailio_helper.hpp"

int main()
{
    std::string mailAddr = "your_email@example.com";  // 邮箱地址
    std::string authCode = "your_auth_code";          // 授权码/密码
    EmailProtocol protocol = EP_POP3;                  // 协议类型
    bool useSSL = true;                                // 是否使用 SSL
    std::string savePath = "./emails/";                // 保存路径

    std::string errorMsg;

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
        std::cout << "邮件获取成功！" << std::endl;
    }
    else
    {
        std::cout << "邮件获取失败: " << errorMsg << std::endl;
    }

    return 0;
}
```

### 2. 参数说明

#### fetchMailsToEmlFiles 方法参数

| 参数 | 类型 | 说明 | 示例 |
|------|------|------|------|
| `mailAddr` | `std::string` | 邮箱地址 | `"user@qq.com"` |
| `authCode` | `std::string` | 邮箱授权码/密码 | `"ABCD1234EFGH5678"` |
| `ep` | `EmailProtocol` | 协议类型 | `EP_POP3` 或 `EP_IMAP` |
| `savePath` | `std::string` | 保存路径 | `"./emails/"` |
| `withSSL` | `bool` | 是否使用 SSL | `true` 或 `false` |
| `errorMsg` | `std::string&` | [输出] 错误信息 | - |

#### 返回值

- `true`: 成功获取邮件
- `false`: 获取失败，错误信息保存在 `errorMsg` 中

### 3. 协议类型

```cpp
enum EmailProtocol
{
    EP_POP3,  // POP3 协议
    EP_IMAP   // IMAP 协议
};
```

### 4. 支持的邮箱服务商

Helper 类会自动识别以下常见邮箱服务商的服务器地址：

| 邮箱服务商 | 域名 | 自动识别的服务器 |
|----------|------|----------------|
| QQ邮箱 | qq.com | imap.qq.com |
| 163邮箱 | 163.com | pop.163.com |
| 126邮箱 | 126.com | pop.126.com |
| 网易邮箱 | yeah.net | pop.yeah.net |
| Gmail | gmail.com | imap.gmail.com |
| Outlook | outlook.com | outlook.office365.com |
| 新浪邮箱 | sina.com | pop.sina.com.cn |
| 搜狐邮箱 | sohu.com | pop.sohu.com |
| 139邮箱 | 139.com | pop.139.com |
| 天翼邮箱 | 189.cn | imap.189.cn |
| 阿里云邮箱 | aliyun.com | imap.aliyun.com |
| Foxmail | foxmail.com | imap.qq.com |

### 5. 端口号配置

Helper 类会根据协议和 SSL 设置自动选择正确的端口号：

| 协议 | 不使用 SSL | 使用 SSL |
|------|-----------|---------|
| POP3 | 110 | 995 |
| IMAP | 143 | 993 |

## 常见使用场景

### 场景 1: QQ 邮箱 + POP3 + SSL

```cpp
std::string mailAddr = "your_qq@qq.com";
std::string authCode = "your_qq_auth_code";  // QQ邮箱需要使用授权码
EmailProtocol protocol = EP_POP3;
bool useSSL = true;
std::string savePath = "./emails/qq/";

MailioHelper::fetchMailsToEmlFiles(mailAddr, authCode, protocol, savePath, useSSL, errorMsg);
```

### 场景 2: 163 邮箱 + POP3 + SSL

```cpp
std::string mailAddr = "your_163@163.com";
std::string authCode = "your_163_auth_code";  // 163邮箱需要使用授权码
EmailProtocol protocol = EP_POP3;
bool useSSL = true;
std::string savePath = "./emails/163/";

MailioHelper::fetchMailsToEmlFiles(mailAddr, authCode, protocol, savePath, useSSL, errorMsg);
```

### 场景 3: QQ 邮箱 + IMAP + SSL

```cpp
std::string mailAddr = "your_qq@qq.com";
std::string authCode = "your_qq_auth_code";
EmailProtocol protocol = EP_IMAP;  // 使用 IMAP 协议
bool useSSL = true;
std::string savePath = "./emails/qq_imap/";

MailioHelper::fetchMailsToEmlFiles(mailAddr, authCode, protocol, savePath, useSSL, errorMsg);
```

### 场景 4: 本地测试邮件服务器

```cpp
std::string mailAddr = "user@localdomain";
std::string authCode = "password";
EmailProtocol protocol = EP_POP3;
bool useSSL = false;  // 本地服务器不使用 SSL
std::string savePath = "./emails/local/";

MailioHelper::fetchMailsToEmlFiles(mailAddr, authCode, protocol, savePath, useSSL, errorMsg);
```

## 错误处理

Helper 类会捕获所有可能的异常，并通过 `errorMsg` 参数返回详细的错误信息：

### 常见错误类型

1. **网络连接错误**: 无法连接到邮件服务器
2. **认证错误**: 邮箱地址或授权码错误
3. **协议错误**: 邮件服务器不支持该协议或配置
4. **文件系统错误**: 无法创建保存目录或写入文件
5. **邮箱地址错误**: 无法从邮箱地址提取服务器信息

```cpp

```

## 编译示例

### 使用 g++ 编译

```bash
# 编译示例程序
g++ -std=c++17 -I../include -o mailio_helper_example \
    examples/mailio_helper_example.cpp \
    -L../lib -lmailio \
    -lboost_date_time -lboost_regex -lssl -lcrypto -lpthread

# 运行
./mailio_helper_example
```

### 使用 CMake

在 `CMakeLists.txt` 中添加：

```cmake
# 添加示例可执行文件
add_executable(mailio_helper_example examples/mailio_helper_example.cpp)
target_link_libraries(mailio_helper_example mailio)
```

然后编译：

```bash
mkdir build && cd build
cmake ..
make mailio_helper_example
./mailio_helper_example
```

## 注意事项

1. **授权码**: 大多数邮箱服务商（如QQ、163）需要使用授权码而不是登录密码
2. **SSL/TLS**: 生产环境建议始终使用 SSL/TLS 加密连接
3. **网络环境**: 确保网络可以访问邮件服务器，注意防火墙设置
4. **文件夹权限**: 确保保存路径有写入权限
5. **邮箱服务器**: 部分邮箱服务商可能需要手动配置服务器地址

## 常见邮箱授权码获取方式

### QQ 邮箱
1. 登录 QQ 邮箱网页版
2. 点击设置 -> 账户
3. 开启 POP3/IMAP/SMTP 服务
4. 生成授权码

### 163 邮箱
1. 登录 163 邮箱网页版
2. 点击设置 -> POP3/SMTP/IMAP
3. 开启服务
4. 生成授权码

### Gmail
1. 登录 Google 账户
2. 安全设置 -> 两步验证
3. 生成应用专用密码

## 输出文件格式

所有邮件将以 `.eml` 格式保存在指定目录下，文件命名格式为：

```
email_1.eml
email_2.eml
email_3.eml
...
```

这些文件符合 RFC 822 标准，可以被大多数邮件客户端（如 Outlook、Thunderbird）打开。

## 扩展功能建议

如需扩展功能，可以考虑：

1. 添加进度回调函数
2. 支持按日期范围筛选邮件
3. 支持增量下载（只下载新邮件）
4. 添加邮件解析和附件提取功能
5. 支持多线程下载提高性能

## 技术支持

如遇到问题，请检查：
1. 邮箱地址和授权码是否正确
2. 网络连接是否正常
3. 邮箱服务商是否启用了相应的服务
4. 防火墙是否阻止了连接
5. 保存路径是否有写入权限

## 许可证

本代码遵循 mailio 项目的许可证（FreeBSD license）。

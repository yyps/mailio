# Mailio Helper 快速开始指南

## 最简使用示例

```cpp
#include "mailio/mailio_helper.hpp"

int main()
{
    std::string errorMsg;
    bool success = MailioHelper::fetchMailsToEmlFiles(
        "your_email@qq.com",  // 邮箱地址
        "your_auth_code",      // 授权码
        EP_POP3,              // 协议类型
        "./emails/",          // 保存路径
        true,                 // 使用SSL
        errorMsg              // 错误信息
    );

    if (!success)
    {
        std::cout << "错误: " << errorMsg << std::endl;
        return -1;
    }

    std::cout << "邮件获取成功！" << std::endl;
    return 0;
}
```

## 三步快速上手

### 1. 准备邮箱信息

- 邮箱地址（例如：`user@qq.com`）
- 邮箱授权码（不是登录密码）
- 协议类型（POP3 或 IMAP）
- 是否使用 SSL（推荐 true）

### 2. 选择保存路径

创建一个目录用于保存邮件，例如：`./emails/`

### 3. 调用接口

```cpp
std::string errorMsg;
bool success = MailioHelper::fetchMailsToEmlFiles(
    mailAddr,
    authCode,
    protocol,
    savePath,
    useSSL,
    errorMsg
);
```

## 常见配置

### QQ 邮箱配置

```cpp
MailioHelper::fetchMailsToEmlFiles(
    "your_qq@qq.com",      // QQ邮箱
    "ABCD1234EFGH5678",    // QQ邮箱授权码
    EP_POP3,                // POP3 协议
    "./emails/qq/",         // 保存路径
    true,                   // 使用 SSL（端口 995）
    errorMsg
);
```

### 163 邮箱配置

```cpp
MailioHelper::fetchMailsToEmlFiles(
    "your_163@163.com",    // 163邮箱
    "ABCD1234EFGH5678",    // 163邮箱授权码
    EP_POP3,                // POP3 协议
    "./emails/163/",        // 保存路径
    true,                   // 使用 SSL（端口 995）
    errorMsg
);
```

### IMAP 配置

```cpp
MailioHelper::fetchMailsToEmlFiles(
    "your_qq@qq.com",      // QQ邮箱
    "ABCD1234EFGH5678",    // QQ邮箱授权码
    EP_IMAP,                // IMAP 协议
    "./emails/qq_imap/",    // 保存路径
    true,                   // 使用 SSL（端口 993）
    errorMsg
);
```

## 获取授权码

### QQ 邮箱

1. 登录 QQ 邮箱网页版
2. 设置 → 账户 → POP3/IMAP/SMTP 服务
3. 开启服务 → 生成授权码

### 163 邮箱

1. 登录 163 邮箱网页版
2. 设置 → POP3/SMTP/IMAP
3. 开启服务 → 生成授权码

### Gmail

1. 登录 Google 账户
2. 安全 → 两步验证 → 应用专用密码
3. 生成应用密码

## 编译和运行

### 方法 1: 使用 CMake

```bash
cd mailio
mkdir build && cd build
cmake ..
make mailio_helper_example
./mailio_helper_example
```

### 方法 2: 直接编译

```bash
g++ -std=c++17 -I../include -o mailio_helper_example \
    examples/mailio_helper_example.cpp \
    -L../lib -lmailio \
    -lboost_date_time -lboost_regex -lssl -lcrypto -lpthread
./mailio_helper_example
```

```cpp

```

## 输出结果

成功后，指定目录下会生成：

```
emails/
├── email_1.eml
├── email_2.eml
├── email_3.eml
└── ...
```

这些 `.eml` 文件可以被：
- Outlook 打开
- Thunderbird 打开
- Apple Mail 打开
- 任何支持 RFC 822 的邮件客户端打开

## 常见问题

### Q: 为什么连接失败？

A: 检查：
1. 网络连接是否正常
2. 服务器地址是否正确
3. 防火墙是否阻止连接

### Q: 为什么认证失败？

A: 检查：
1. 邮箱地址是否正确
2. 是否使用授权码（不是登录密码）
3. 授权码是否已过期

### Q: 为什么没有邮件？

A: 检查：
1. 邮箱中是否有邮件
2. 邮件是否已被客户端删除
3. 是否选择了正确的收件箱（IMAP）

### Q: POP3 和 IMAP 有什么区别？

A:
- **POP3**: 简单，只下载收件箱邮件
- **IMAP**: 功能丰富，支持文件夹、标记等

## 更多示例

查看完整示例：
- `examples/mailio_helper_example.cpp` - 基础示例
- `examples/mailio_helper_test.cpp` - 完整测试

查看详细文档：
- `MailioHelper_README.md` - 完整使用指南

## 技术支持

遇到问题？
1. 检查错误信息
2. 参考常见问题
3. 查看详细文档
4. 检查网络和配置

/*

imaps_stat.cpp
--------------
  
Connects to an IMAP server over SSL and gets the first message from the inbox.


Copyright (C) 2016, Tomislav Karastojkovic (http://www.alepho.com).

Distributed under the FreeBSD license, see the accompanying file LICENSE or
copy at http://www.freebsd.org/copyright/freebsd-license.html.

*/


#include <iostream>
#include <mailio/imap.hpp>
#include <mailio/pop3.hpp>


using mailio::message;
using mailio::codec;
using mailio::imap;
using mailio::imaps;
using mailio::pop3s;
using mailio::imap_error;
using mailio::dialog_error;
using std::cout;
using std::endl;


int main()
{
    try
    {
        pop3s conn("imap.126.com", 993);
        conn.authenticate("w126testwlh@126.com", "PPWNEBXSTPPVIKWS", imaps::auth_method_t::LOGIN);
        //conn.authenticate("w126testwlh@126.com", "PPWNEBXSTPPVIKWS", imaps::auth_method_t::LOGIN);
        //imaps conn("imap.126.com", 993);
        //conn.authenticate("w126testwlh@126.com", "PPWNEBXSTPPVIKWS", imaps::auth_method_t::LOGIN);
        //conn.regist_client("mail_check_mod", "1.0");
        //message msg;
        //msg.line_policy(codec::line_len_policy_t::NONE);
        //imap::mailbox_folder_t fld = conn.list_folders("INBOX");
        //conn.select("INBOX");
        //auto stat = conn.statistics("INBOX");
        ////auto dirs = conn.list_folders("");
        //conn.fetch(1, msg);
        //cout << "msg.content()=" << msg.content() << endl;
    }
    catch (imap_error& exc)
    {
        cout << exc.what() << endl;
    }
    catch (dialog_error& exc)
    {
        cout << exc.what() << endl;
    }

    return EXIT_SUCCESS;
}

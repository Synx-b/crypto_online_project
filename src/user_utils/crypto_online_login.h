/*
 * File: crypto_online_home.cc
 * Created: 20/12/2017 22:07
 * Finished:
 *
 * Description:
 *
 * Author: Jacob Powell
 */

#ifndef CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_LOGIN_H
#define CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_LOGIN_H

#include <Wt/WTable.h>
#include <Wt/WText.h>
#include <Wt/WAnchor.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include "../db/db_interface.h"


class crypto_online_login : public Wt::WTable{
public:
    crypto_online_login(Session& session);
private:

    void load_login_page();
    void process_login();

    std::unique_ptr<Wt::WText> username_label;
    std::unique_ptr<Wt::WText> password_label;

    Wt::WText *login_error;

    Wt::WLineEdit *username_entry;
    Wt::WLineEdit *password_entry;

    std::unique_ptr<Wt::WAnchor> register_button;
    std::unique_ptr<Wt::WPushButton> login_button;

    db_interface database_interface;
    Session& session;

};


#endif //CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_LOGIN_H

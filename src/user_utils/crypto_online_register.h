/*
 * File: crypto_online_register.cc
 * Created: 20/12/2017 22:08
 * Finished:
 *
 * Description:
 *
 * Author: Jacob Powell
 */

#ifndef CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_REGISTER_H
#define CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_REGISTER_H

#include "../db/db_interface.h"
#include "validation.h"

#include <Wt/WTable.h>
#include <Wt/WAnchor.h>
#include <Wt/WText.h>
#include <Wt/WLineEdit.h>


class crypto_online_register : public Wt::WTable{
public:
    crypto_online_register();
private:

    void load_register_page();
    void process_register();

    std::unique_ptr<Wt::WText> username_label;
    std::unique_ptr<Wt::WText> password_label;
    std::unique_ptr<Wt::WText> email_label;

    Wt::WText* username_label_error;
    Wt::WText* password_label_error;
    Wt::WText* email_label_error;

    Wt::WLineEdit *username_entry;
    Wt::WLineEdit *password_entry;
    Wt::WLineEdit *email_entry;

    std::unique_ptr<Wt::WPushButton> register_button;

    db_interface database_interface;
    validation validation_interface;

};


#endif //CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_REGISTER_H

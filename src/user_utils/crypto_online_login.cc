/*
 * File: crypto_online_home.cc
 * Created: 20/12/2017 22:07
 * Finished:
 *
 * Description:
 *
 * Author: Jacob Powell
 */

#include "crypto_online_login.h"
#include "../hashing/sha3_hash.h"
#include "../layout/crypto_online_home.h"

#include <Wt/WApplication.h>


crypto_online_login::crypto_online_login() {
    this->load_login_page();
    this->database_interface.connect_database();
}

void crypto_online_login::load_login_page() {

    this->setStyleClass("login_table");

    this->username_label = Wt::cpp14::make_unique<Wt::WText>(Wt::WString::tr("form.login.username"));
    this->username_label->setStyleClass("login_credentials");
    this->elementAt(0,0)->addWidget(std::move(this->username_label));

    this->username_entry = this->elementAt(0,1)->addWidget(Wt::cpp14::make_unique<Wt::WLineEdit>());
    this->username_entry->setMinimumSize(400, Wt::WLength::Auto);
    this->username_entry->enterPressed().connect(this, &crypto_online_login::process_login);

    this->password_label = Wt::cpp14::make_unique<Wt::WText>(Wt::WString::tr("form.login.password"));
    this->password_label->setStyleClass("login_credentials");
    this->elementAt(1,0)->addWidget(std::move(this->password_label));

    this->password_entry = this->elementAt(1,1)->addWidget(Wt::cpp14::make_unique<Wt::WLineEdit>());
    this->password_entry->setMinimumSize(400, Wt::WLength::Auto);
    this->password_entry->setEchoMode(Wt::EchoMode::Password);
    this->password_entry->enterPressed().connect(this, &crypto_online_login::process_login);

    this->login_button = Wt::cpp14::make_unique<Wt::WPushButton>(Wt::WString::tr("form.login.submit"));
    this->login_button->setStyleClass("login_buttons");
    this->login_button->clicked().connect(this, &crypto_online_login::process_login);
    this->elementAt(3,0)->addWidget(std::move(this->login_button));
    this->elementAt(3,0)->setContentAlignment(Wt::AlignmentFlag::Right);

    this->register_button = Wt::cpp14::make_unique<Wt::WAnchor>();
    auto register_button_add = Wt::cpp14::make_unique<Wt::WPushButton>(Wt::WString::tr("form.register.submit"));
    register_button_add->setStyleClass("login_buttons");
    this->register_button->addWidget(std::move(register_button_add));
    this->register_button->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/register"));
    this->elementAt(3,1)->addWidget(std::move(register_button));
    this->elementAt(3,1)->setContentAlignment(Wt::AlignmentFlag::Left);

    this->login_error = this->elementAt(2,1)->addWidget(Wt::cpp14::make_unique<Wt::WText>(""));
    this->login_error->setStyleClass("login_error");

}

void crypto_online_login::process_login() {
    Wt::WApplication* app = Wt::WApplication::instance();

    auto username = this->username_entry->text().toUTF8();
    auto password = this->password_entry->text().toUTF8();

    std::string hashed_password_string;
    SHA3_512 sha3;
    hashed_password_string = sha3.compute_hash(password);


    if(database_interface.check_user_pass(username, hashed_password_string)){
        app->setInternalPath("/home", true);
    }
    else{
        this->login_error->setText("Username/Password Error");
    }

}
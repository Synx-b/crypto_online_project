/*
 * File: crypto_online_register.cc
 * Created: 19/12/2017 22:08
 * Finished:
 *
 * Description:
 *
 * Author: Jacob Powell
 */

#include "crypto_online_register.h"
#include "../hashing/sha3_hash.h"

#include <Wt/WPushButton.h>
#include <Wt/WApplication.h>

crypto_online_register::crypto_online_register() {
    this->load_register_page();
    this->database_interface.connect_database();
}

void crypto_online_register::load_register_page() {

    this->setStyleClass("login-table");

    this->username_label = Wt::cpp14::make_unique<Wt::WText>(Wt::WString::tr("form.login.username"));
    this->username_label->setStyleClass("login_credentials");
    this->elementAt(0,0)->addWidget(std::move(this->username_label));

    this->username_entry = this->elementAt(0,1)->addWidget(Wt::cpp14::make_unique<Wt::WLineEdit>());
    this->username_entry->setMinimumSize(400, Wt::WLength::Auto);
    this->username_entry->enterPressed().connect(this, &crypto_online_register::process_register);

    this->username_label_error = this->elementAt(0,2)->addWidget(Wt::cpp14::make_unique<Wt::WText>());
    this->username_label_error->setStyleClass("login_error");

    this->password_label = Wt::cpp14::make_unique<Wt::WText>(Wt::WString::tr("form.login.password"));
    this->password_label->setStyleClass("login_credentials");
    this->elementAt(1,0)->addWidget(std::move(this->password_label));

    this->password_entry = this->elementAt(1,1)->addWidget(Wt::cpp14::make_unique<Wt::WLineEdit>());
    this->password_entry->setMinimumSize(400, Wt::WLength::Auto);
    this->password_entry->setEchoMode(Wt::EchoMode::Password);
    this->password_entry->enterPressed().connect(this, &crypto_online_register::process_register);

    this->password_label_error = this->elementAt(1,2)->addWidget(Wt::cpp14::make_unique<Wt::WText>());
    this->password_label_error->setStyleClass("login_error");

    this->email_label = Wt::cpp14::make_unique<Wt::WText>(Wt::WString::tr("form.login.email"));
    this->email_label->setStyleClass("login_credentials");
    this->elementAt(2,0)->addWidget(std::move(this->email_label));
    this->elementAt(2,0)->setContentAlignment(Wt::AlignmentFlag::Right);

    this->email_entry = this->elementAt(2,1)->addWidget(Wt::cpp14::make_unique<Wt::WLineEdit>());
    this->email_entry->setMinimumSize(400, Wt::WLength::Auto);
    this->email_entry->enterPressed().connect(this, &crypto_online_register::process_register);

    this->email_label_error = this->elementAt(2,2)->addWidget(Wt::cpp14::make_unique<Wt::WText>());
    this->email_label_error->setStyleClass("login_error");
    this->email_label_error->setTextAlignment(Wt::AlignmentFlag::Center);

    this->register_button = Wt::cpp14::make_unique<Wt::WPushButton>(Wt::WString::tr("form.register.submit"));
    this->register_button->setStyleClass("login_buttons");
    this->register_button->clicked().connect(this, &crypto_online_register::process_register);
    this->elementAt(3,1)->addWidget(std::move(this->register_button));
    this->elementAt(3,1)->setContentAlignment(Wt::AlignmentFlag::Left);

}

void crypto_online_register::process_register() {

    Wt::WApplication* app = Wt::WApplication::instance();

    auto username = this->username_entry->text().toUTF8();
    auto password = this->password_entry->text().toUTF8();
    auto email = this->email_entry->text().toUTF8();

    if(username.length() < 5) {
        this->username_label_error->setText("Username Not Long Enough");
    }else if(!validation_interface.password_complexity_is_good(password)){
        this->username_label_error->setText("");
        this->password_label_error->setText("Password is not Complex Enough");
    }else if(!validation_interface.is_valid_email(email)){
        this->password_label_error->setText("");
        this->email_label_error->setText("Invalid Email Address");
    }else {
        std::string hashed_password_string;
        sha3_512_hash sha3;
        hashed_password_string = sha3.compute_hash(password);


        if (this->database_interface.check_user_does_not_exist(username)) {
            this->database_interface.add_user(username, hashed_password_string, email, Role::User);
            app->setInternalPath("/login", true);
        } else {

        }
    }


}

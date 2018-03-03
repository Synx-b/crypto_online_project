/*
 * File: crypto_online_home.cc
 * Created: 19/12/2017 13:25
 * Finished:
 *
 * Description:
 *
 * Author: Jacob Powell
 */

#include "CryptoOnlineHeader.h"
#include "../crypto_online_home.h"


CryptoOnlineHeader::CryptoOnlineHeader(Session& session) : _current_session(session) {
    
    if(session.login().loggedIn()){
        create_user_navigation_bar();
    }else{
        create_navigation_bar();
    }

}

void CryptoOnlineHeader::create_navigation_bar() {
    this->navigation_bar = Wt::cpp14::make_unique<Wt::WNavigationBar>();
    this->navigation_bar->setTitle("Crypto Online", Wt::WLink(Wt::LinkType::InternalPath, "/home"));
    this->navigation_bar->setResponsive(true);
    this->navigation_bar->setStyleClass("navigation_bar_things");
    this->navigation_bar->setMaximumSize(Wt::WLength::Auto, 50);

    this->navigation_bar_contents_stack = this->addWidget(Wt::cpp14::make_unique<Wt::WStackedWidget>());
    navigation_bar_contents_stack->addStyleClass("contents");

    this->left_menu = Wt::cpp14::make_unique<Wt::WMenu>(this->navigation_bar_contents_stack);
    auto left_menu_ = this->navigation_bar->addMenu(std::move(this->left_menu));
    left_menu_->addItem("Home")->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/home"));
    left_menu_->addItem("Symmetric");
    left_menu_->addItem("Asymmetric");

    this->right_menu = Wt::cpp14::make_unique<Wt::WMenu>();
    auto right_menu_ = this->navigation_bar->addMenu(std::move(this->right_menu), Wt::AlignmentFlag::Right);
    right_menu_->addItem("Login")->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/login"));
    right_menu_->addItem("Register")->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/register"));

    this->addWidget(std::move(this->navigation_bar),1);

}

void CryptoOnlineHeader::create_user_navigation_bar() {
    this->navigation_bar = Wt::cpp14::make_unique<Wt::WNavigationBar>();
    this->navigation_bar->setTitle("Crypto Online", Wt::WLink(Wt::LinkType::InternalPath, "/home"));
    this->navigation_bar->setResponsive(true);
    this->navigation_bar->setStyleClass("navigation_bar_things");
    this->navigation_bar->setMaximumSize(Wt::WLength::Auto, 50);

    this->navigation_bar_contents_stack = this->addWidget(Wt::cpp14::make_unique<Wt::WStackedWidget>());
    navigation_bar_contents_stack->addStyleClass("contents");

    this->left_menu = Wt::cpp14::make_unique<Wt::WMenu>(this->navigation_bar_contents_stack);
    auto left_menu_ = this->navigation_bar->addMenu(std::move(this->left_menu));
    left_menu_->addItem("Home")->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/home"));

    const Wt::Auth::User& u = _current_session.login().user();

    auto username = left_menu_->addItem("User Logged In: " + u.identity(Wt::Auth::Identity::LoginName));
    username->disable();

    this->right_menu = Wt::cpp14::make_unique<Wt::WMenu>();
    auto right_menu_ = this->navigation_bar->addMenu(std::move(this->right_menu), Wt::AlignmentFlag::Right);
    right_menu_->addItem("Profile")->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/profile"));
    right_menu_->addItem("Sign Out")->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/signout"));



    this->addWidget(std::move(this->navigation_bar),1);
}



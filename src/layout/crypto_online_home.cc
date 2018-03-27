/**
 * @file crypto_online_home.cc
 * @date 19/12/2017
 *
 * @brief This file contains the base structure for how the website looks and how the user interacts with it.
 * @version 0.01
 * @author Jacob Powell
 */

#include "crypto_online_home.h"
#include "information_content/modular_arithmetic.h"
#include "information_content/intro_to_cryptography.h"

#include <Wt/WApplication.h>
#include <Wt/Dbo/backend/Sqlite3.h>


/**
 * @brief Constructor for the CryptoOnlineHome class.
 * The constructor handles the initial loading of the home page. It first calls the home page which contains the
 * navigation grid to all the internal pages plus the profile stats and user information.
 *
 * It also handles the behaviour of the website when the internal path changes and correctly navigates to the
 * appropriate page that the user has requested to navigate to.
 */
CryptoOnlineHome::CryptoOnlineHome(Session& session) : _current_session(session) {

    load_home_page();
    load_database();

    this->handleInternalPath(Wt::WApplication::instance()->internalPath());


    Wt::WApplication::instance()->internalPathChanged()
            .connect(this, &CryptoOnlineHome::handleInternalPath);
}

/**
 * @brief This method handles any internal path changes to the application.
 * It monitors for any change in the internal path and when it does change it calls the appropriate method to deal with
 * internal path change.
 *
 * @param path The new internal path the application has changed to
 */
void CryptoOnlineHome::handleInternalPath(const std::string &path) {
    /*
     * TODO: Add authentication checking, eg whether or not a user is logged in
     *
     */
    Wt::WApplication* app = Wt::WApplication::instance();

    std::cout << "PATH CHANGED: " + path << std::endl;

    if(path == "/home")
        load_home_page();
    else if(path == "/signout"){
        _current_session.login().logout();
        load_home_page();
        app->setInternalPath("/home", true);
    }else if(path == "/profile")
        load_profile_page();
    else if(path == "/login") {
        load_login_page();
        app->setInternalPath("/login", true);
    } else if(path == "/register")
        load_register_page();
    else if(path == "/symmetric/modular-arithmetic")
        load_modular_arithmetic_page();
    else if(path == "/basics/concepts")
        load_intro_to_cryptography_page();
        /*
         * TODO: Add navigation to all parts of the website
         */
    else
        Wt::WApplication::instance()->setInternalPath("/home", true);
}

/**
 * @brief This method loads the home page of the website
 */
void CryptoOnlineHome::load_home_page() {
    this->clear();
    this->setHeight(1770);

    this->_grid = Wt::cpp14::make_unique<Wt::WGridLayout>();

    this->_header = Wt::cpp14::make_unique<CryptoOnlineHeader>(_current_session);
    this->_navigation_grid = Wt::cpp14::make_unique<crypto_online_navigation_grid>();
    this->_footer = Wt::cpp14::make_unique<crypto_online_footer>();

    this->_grid->addItem(std::move(this->_header), 0, 0);
    this->_grid->addItem(std::move(this->_navigation_grid), 1, 0);
    this->_grid->addItem(std::move(this->_footer), 2, 0);

    this->setLayout(std::move(this->_grid));
}

/**
 * @brief This method loads the login page of the website
 */
void CryptoOnlineHome::load_login_page() {
    this->clear();
    this->setHeight(400);

    this->_grid = Wt::cpp14::make_unique<Wt::WGridLayout>();

    this->_header = Wt::cpp14::make_unique<CryptoOnlineHeader>(_current_session);
    this->_login = Wt::cpp14::make_unique<CryptoOnlineAuthWidget>(Session::auth(), _current_session.users(), _current_session.login());
    this->_footer = Wt::cpp14::make_unique<crypto_online_footer>();

    this->_grid->addItem(std::move(this->_header), 0, 0);
    this->_grid->addWidget(std::move(this->_login), 1, 0);
    this->_grid->addItem(std::move(this->_footer), 2, 0);

    this->setLayout(std::move(this->_grid));
}

/**
 * @brief This method loads the register page of the website
 */
void CryptoOnlineHome::load_register_page() {
    this->clear();
    this->setHeight(400);

    this->_grid = Wt::cpp14::make_unique<Wt::WGridLayout>();

    this->_header = Wt::cpp14::make_unique<CryptoOnlineHeader>(_current_session);
    this->_register = Wt::cpp14::make_unique<crypto_online_register>();
    this->_footer = Wt::cpp14::make_unique<crypto_online_footer>();

    this->_grid->addItem(std::move(this->_header), 0, 0);
    this->_grid->addWidget(std::move(this->_register), 1, 0, Wt::AlignmentFlag::Center);
    this->_grid->addItem(std::move(this->_footer), 2, 0);

    this->setLayout(std::move(this->_grid));
}

/**
 * @brief This method creates a live connection between the web application of the website
 */
void CryptoOnlineHome::load_database() {
    database_interface.connect_database();
}

/**
 * @brief This method loads the profile page of the website
 */
void CryptoOnlineHome::load_profile_page() {
    this->clear();
    this->setHeight(400);

    this->_grid = Wt::cpp14::make_unique<Wt::WGridLayout>();

    this->_header = Wt::cpp14::make_unique<CryptoOnlineHeader>(_current_session);
    this->_profile = Wt::cpp14::make_unique<CryptoOnlineProfile>(_current_session);
    this->_footer = Wt::cpp14::make_unique<crypto_online_footer>();

    this->_grid->addItem(std::move(this->_header), 0, 0);
    this->_grid->addWidget(std::move(this->_profile), 1, 0, Wt::AlignmentFlag::Center);
    this->_grid->addItem(std::move(this->_footer), 2, 0);

    this->setLayout(std::move(this->_grid));
}

/**
 * @brief This methods loads the Basic Concepts page
 */
void CryptoOnlineHome::load_intro_to_cryptography_page(){
    this->clear();
    this->setHeight(4500);

    std::string title_link = "learning.intro-to-cryptography.title";
    std::string content_link = "learning.intro-to-cryptography.content";

    this->_grid = Wt::cpp14::make_unique<Wt::WGridLayout>();

    this->_header = Wt::cpp14::make_unique<CryptoOnlineHeader>(_current_session);
    this->_footer = Wt::cpp14::make_unique<crypto_online_footer>();

    this->_grid->addItem(std::move(this->_header), 0, 0);
    this->_grid->addWidget(Wt::cpp14::make_unique<intro_to_cryptography>(title_link, content_link), 1, 0, Wt::AlignmentFlag::Center);
    this->_grid->addItem(std::move(this->_footer), 2, 0);

    this->setLayout(std::move(this->_grid));
}

/**
 * @brief This method loads the modular arithmetic of the website
 */
void CryptoOnlineHome::load_modular_arithmetic_page() {
    this->clear();
    this->setHeight(1600);

    std::string title_link = "learning.modular-arithmetic.title";
    std::string content_link = "learning.modular-arithmetic.content";

    this->_grid = Wt::cpp14::make_unique<Wt::WGridLayout>();

    this->_header = Wt::cpp14::make_unique<CryptoOnlineHeader>(_current_session);
    this->_footer = Wt::cpp14::make_unique<crypto_online_footer>();

    this->_grid->addItem(std::move(this->_header), 0, 0);
    this->_grid->addWidget(Wt::cpp14::make_unique<modular_arithmetic>(title_link, content_link), 1, 0, Wt::AlignmentFlag::Center);
    this->_grid->addItem(std::move(this->_footer), 2, 0);

    this->setLayout(std::move(this->_grid));

}



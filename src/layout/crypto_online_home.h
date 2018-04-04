/**
 * @file crypto_online_home.cc
 * @date 19/12/2017
 *
 * @brief This file contains the class and method definitions for the CryptoOnlineHome class
 * @version 0.01
 * @author Jacob Powell
 */

#ifndef CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_HOME_H
#define CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_HOME_H

#include "header/crypto_online_header.h"
#include "crypto_online_navigation_grid.h"
#include "crypto_online_footer.h"
#include "../db/db_interface.h"
#include "crypto_online_profile.h"
#include "../db/session.h"
#include "../auth/crypto_online_auth_widget.h"

#include <Wt/WContainerWidget.h>
#include <Wt/WNavigationBar.h>
#include <Wt/WMenu.h>
#include <Wt/WText.h>
#include <Wt/WGridLayout.h>
#include <Wt/WTable.h>
#include <Wt/WStackedWidget.h>

#include <string>

/**
 * @class CryptoOnlineHome
 *
 * @brief This class serves for the purpose of controlling the main state of the application. All changes that the user makes
 * while on the website will first start here and then propagate down through the related classes and methods
 */
class CryptoOnlineHome : public Wt::WContainerWidget{
public:
    explicit CryptoOnlineHome(Session& session); /**< Constructor for the CryptoOnlineHome Class */

private:
    void load_home_page(); /**< Loads the Home Page */
    void load_login_page(); /**< Loads the Login Page */
    void load_profile_page(); /**< Loads the Profile Page */

    void load_intro_to_cryptography_page(); /**< Loads the Intro to Cryptography Page */
    void load_modular_arithmetic_page(); /**< Loads the Modular Arithmetic Page */

    void load_database(); /**< Loads and Connects to the Database */
    void handleInternalPath(const std::string& string); /**< Handles the change in the internal path of the application */

    Session& _current_session;

    std::unique_ptr<Wt::WGridLayout> _grid; /**< Holds the state of the front-end display of the website */

    std::unique_ptr<CryptoOnlineHeader> _header; /**< Holds the state of the header of the website */
    std::unique_ptr<crypto_online_navigation_grid> _navigation_grid; /**< Holds the state of the navigation grid of the website */
    std::unique_ptr<crypto_online_footer> _footer; /**< Holds the state of the footer of the website */
    std::unique_ptr<CryptoOnlineProfile> _profile; /**< Holds the state of the profile page of the website */

    std::unique_ptr<CryptoOnlineAuthWidget> _login; /**< Holds the state of the login / register page of the website */


    db_interface database_interface; /**< Allows the interaction between the application and the database */

};

#endif //CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_HOME_H

/**
 * @file crypto_online_home.cc
 * @date 19/12/2017
 *
 * This file contains the class definitions for the CryptoOnlineHeader Class
 *
 * @version 0.01
 * @author Jacob Powell
 */

#ifndef CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_HEADER_H
#define CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_HEADER_H


#include "../../db/db_interface.h"
#include "../../db/db_user.h"
#include "../../db/session.h"

#include <Wt/WHBoxLayout.h>
#include <Wt/WNavigationBar.h>
#include <Wt/WStackedWidget.h>
#include <Wt/WMenu.h>


/**
 * @class CryptoOnlineHeader
 *
 * @brief This Class handles what the appearance and functionality of the website header
 */
class CryptoOnlineHeader : public Wt::WHBoxLayout{
public:
    explicit CryptoOnlineHeader(Session& session); /**< Constructor for the CryptoOnlineHeader Class */

private:
    void create_navigation_bar(); /**< Creates the Inital Navigation Bar that appears in the header */
    void create_user_navigation_bar();

    Session& _current_session; /**< Holds the current session */
    db_interface database_interface; /**< Interface to interact with the database from */
    Wt::Dbo::ptr<DbUser> current_user; /**< Holds information on the currently logged in user */

    std::unique_ptr<Wt::WNavigationBar> navigation_bar; /**< Holds the current state of the navigation bar */
    std::unique_ptr<Wt::WMenu> left_menu; /**< Holds the state of the left menu in the navigation bar */
    std::unique_ptr<Wt::WMenu> right_menu; /**< Holds the state of the Right menu in the navigation bar */

    Wt::WStackedWidget *navigation_bar_contents_stack; /**< Holds the contents of the bar in the form a stack */

};

#endif //CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_HEADER_H

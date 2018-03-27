/**
 * @file crypto_online_profile.h
 * @date 11/01/2017
 *
 * @brief This file contains the class and method definitions for the CryptoOnlineProfile class
 *
 * @author Jacob Powell
 */

#ifndef CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_PROFILE_H
#define CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_PROFILE_H

#include "../db/db_interface.h"
#include "../db/session.h"

#include <Wt/WTable.h>
#include <Wt/WText.h>

/**
 * @class CryptoOnlineProfile
 *
 * @brief This class handles the display and data flow for the profile page of the website.
 *
 */
class CryptoOnlineProfile : public Wt::WTable {
public:
    CryptoOnlineProfile() = delete;
    CryptoOnlineProfile(Session& session);

private:
    void load_profile_page();

    Wt::WText* _username_label; /**< A WText instance to load the username tag into, not the actual username. */
    Wt::WText* _username; /**< A WText instance that holds the username that is loaded into from the database */

    Session& _current_session;

    db_interface database_interface; /**< A database_interface instance that allows data to be read from the database*/
    Wt::Dbo::ptr<db_user> database_user; /**< This is where the database information about the user will be loaded into */

};


#endif //CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_PROFILE_H

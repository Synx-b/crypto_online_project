/**
 * @file session.h
 * @date 30/01/2018
 *
 * @brief This file contains the definition for the Session class
 * @version 0.02
 *
 * @author Jacob Powell
 */

#ifndef CRYPTO_ONLINE_PROJECT_SESSION_H
#define CRYPTO_ONLINE_PROJECT_SESSION_H

#include "db_user.h"

#include <Wt/Auth/Login.h>
#include <Wt/Auth/Dbo/UserDatabase.h>

#include <Wt/Dbo/Session.h>
#include <Wt/Dbo/ptr.h>

using UserDatabase = Wt::Auth::Dbo::UserDatabase<Wt::Auth::Dbo::AuthInfo<DbUser>>;

/**
 * @class Session
 * @inherit Wt::Dbo::Session
 *
 * @version 0.1
 *
 * @brief This class deals with how we deal with the conept of sessions on the website. It deals with how the user
 *        interacts with and gets information from the connected database and provides
 */
class Session : public Wt::Dbo::Session {
public:
    explicit Session(const std::string& sqliteDb);

    static void configureAuth();

    static const Wt::Auth::AuthService& auth();
    static const Wt::Auth::PasswordService& passwordAuth();
    static const std::vector<const Wt::Auth::OAuthService *>& oAuth();

    void new_registered_user(Wt::Auth::User& user);
    void link_account_to_database(Wt::Dbo::ptr<DbUser>& user);

    Wt::Auth::AbstractUserDatabase& users();
    Wt::Dbo::ptr<AuthInfo> user();
    Wt::Auth::Login& login(){ return _login; }

private:
    std::unique_ptr<Wt::Auth::Dbo::UserDatabase<Wt::Auth::Dbo::AuthInfo<DbUser>>> _users;
    Wt::Auth::Login _login;


};


#endif //CRYPTO_ONLINE_PROJECT_SESSION_H

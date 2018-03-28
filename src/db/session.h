/**
 * @file session.h
 * @date 30/01/2018
 *
 * @brief
 *
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

using UserDatabase = Wt::Auth::Dbo::UserDatabase<AuthInfo>;

/**
 * @class Session
 */
class Session : public Wt::Dbo::Session {
public:
    explicit Session(const std::string& sqliteDb);

    static void configureAuth();

    static const Wt::Auth::AuthService& auth();
    static const Wt::Auth::PasswordService& passwordAuth();
    static const std::vector<const Wt::Auth::OAuthService *>& oAuth();

    Wt::Auth::AbstractUserDatabase& users();
    Wt::Dbo::ptr<DbUser> user();
    Wt::Auth::Login& login(){ return _login; }

private:
    std::unique_ptr<UserDatabase> _users;
    Wt::Auth::Login _login;


};


#endif //CRYPTO_ONLINE_PROJECT_SESSION_H

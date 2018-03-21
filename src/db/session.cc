/**
 * @file session.cc
 * @date 30/01/2018
 *
 * @brief
 *
 *
 * @author Jacob Powell
 */

#include "session.h"

#include <Wt/Auth/Dbo/AuthInfo.h>
#include <Wt/Dbo/backend/Sqlite3.h>

#include <Wt/Auth/AuthService.h>
#include <Wt/Auth/HashFunction.h>
#include <Wt/Auth/PasswordService.h>
#include <Wt/Auth/PasswordStrengthValidator.h>
#include <Wt/Auth/PasswordVerifier.h>
#include <Wt/Auth/GoogleService.h>
#include <Wt/Auth/FacebookService.h>

namespace {
    Wt::Auth::AuthService myAuthService;
    Wt::Auth::PasswordService myPasswordService{myAuthService};
    std::vector<std::unique_ptr<Wt::Auth::OAuthService>> myOAuth;
}

Session::Session(const std::string &sqliteDb) {
    auto connection = Wt::cpp14::make_unique<Wt::Dbo::backend::Sqlite3>(sqliteDb);
    this->setConnection(std::move(connection));

    this->mapClass<db_user>("db_user");
    this->mapClass<AuthInfo>("auth_info");
    this->mapClass<AuthInfo::AuthIdentityType>("auth_identity");
    this->mapClass<AuthInfo::AuthTokenType>("auth_token");
    std::cout << "DATABASE CHECKING" << std::endl;

    try {
        this->createTables();
        std::cerr << "Created Database" << std::endl;
    }catch(Wt::Dbo::Exception &e){
        std::cerr << e.what() << std::endl;
        std::cerr << "Using Existing Database" << std::endl;
    }

    this->_users = Wt::cpp14::make_unique<UserDatabase >(*this);

}

Wt::Auth::AbstractUserDatabase &Session::users() {
    return *_users;
}

void Session::configureAuth() {
    myAuthService.setAuthTokensEnabled(true, "logincookie");
    myAuthService.setEmailVerificationEnabled(true);
    myAuthService.setEmailVerificationRequired(false);

    std::unique_ptr<Wt::Auth::PasswordVerifier> verifier =
            Wt::cpp14::make_unique<Wt::Auth::PasswordVerifier>();
    verifier->addHashFunction(Wt::cpp14::make_unique<Wt::Auth::BCryptHashFunction>(7));
    myPasswordService.setVerifier(std::move(verifier));
    myPasswordService.setAttemptThrottlingEnabled(true);
    myPasswordService.setStrengthValidator(Wt::cpp14::make_unique<Wt::Auth::PasswordStrengthValidator>());

    if (Wt::Auth::GoogleService::configured()) {
        std::cout << "GOOGLE SERVICE CONFIGURED" << std::endl;
        myOAuth.push_back(Wt::cpp14::make_unique<Wt::Auth::GoogleService>(myAuthService));
    }

    if (Wt::Auth::FacebookService::configured())
        myOAuth.push_back(Wt::cpp14::make_unique<Wt::Auth::FacebookService>(myAuthService));

    for (unsigned int i = 0; i < myOAuth.size(); i++)
        myOAuth[i]->generateRedirectEndpoint();
}

const Wt::Auth::AuthService& Session::auth() {
    return myAuthService;
}

const Wt::Auth::PasswordService& Session::passwordAuth() {
    return myPasswordService;
}

const std::vector<const Wt::Auth::OAuthService *>& Session::oAuth() {
    std::vector<const Wt::Auth::OAuthService *> result;
    for (auto &auth : myOAuth) {
        result.push_back(auth.get());
    }
    return result;
}

Wt::Dbo::ptr<db_user> Session::user() {
    if(_login.loggedIn()){
        Wt::Dbo::ptr<AuthInfo> authInfo = _users->find(_login.user());
        return authInfo->user();
    }else{
        return Wt::Dbo::ptr<db_user>();
    }
}

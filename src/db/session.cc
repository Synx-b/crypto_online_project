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

#include <Wt/Dbo/backend/Sqlite3.h>
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
    connection->setProperty("show-queries", "true");
    this->setConnection(std::move(connection));

    this->mapClass<DbUser>("db_user");
    this->mapClass<Question>("questions");
    this->mapClass<Wt::Auth::Dbo::AuthInfo<DbUser>>("auth_info");
    this->mapClass<Wt::Auth::Dbo::AuthInfo<DbUser>::AuthIdentityType>("auth_identity");
    this->mapClass<Wt::Auth::Dbo::AuthInfo<DbUser>::AuthTokenType>("auth_token");

    std::cout << "DATABASE CHECKIN"
            "G" << std::endl;
    try {
        this->createTables();
        std::cerr << "Created Database" << std::endl;
    }catch(Wt::Dbo::Exception &e){
        std::cerr << e.what() << std::endl;
        std::cerr << "Using Existing Database" << std::endl;
    }
    this->_users = Wt::cpp14::make_unique<Wt::Auth::Dbo::UserDatabase<Wt::Auth::Dbo::AuthInfo<DbUser>>>(*this);
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

    for (unsigned i = 0; i < myOAuth.size(); i++)
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

Wt::Dbo::ptr<AuthInfo> Session::user() {
    if(_login.loggedIn()){
        Wt::Dbo::ptr<AuthInfo> authInfo = _users->find(_login.user());
        return authInfo;
    }else{
        return Wt::Dbo::ptr<AuthInfo>();
    }
}

/**
 * @brief This method handles the registration of a new user
 *        It is called during a transaction
 *
 * @param user The new user that just registered on the site
 */
void Session::new_registered_user(Wt::Auth::User &user) {
    auto authInfo{_users->find(user)};
    auto foundUser{authInfo->user()};

    if(!foundUser){
        foundUser = this->add(Wt::cpp14::make_unique<DbUser>());
        authInfo.modify()->setUser(foundUser);
    }
}

void Session::link_account_to_database(Wt::Dbo::ptr<DbUser>& user) {

    Wt::Dbo::Transaction transaction(*this);
    std::cout << "LINKING ACCOUNT TO DATA" << std::endl;
    std::unique_ptr<DbUser> new_user{new DbUser()};
    new_user->user_id = static_cast<int>(user.id());
    new_user->user_role = Role::User;
    new_user->user_identity = this->login().user().identity(Wt::Auth::Identity::LoginName);

    Wt::Dbo::ptr<DbUser> new_user_ptr = this->add(std::move(new_user));
}


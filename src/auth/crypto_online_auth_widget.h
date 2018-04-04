/**
 * @file crypto_online_auth_widget.h
 * @date 31/01/2018
 *
 * @author Jacob Powell
 */

#ifndef CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_AUTH_WIDGET_H
#define CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_AUTH_WIDGET_H


#include <Wt/Auth/AuthWidget.h>
#include "../db/db_interface.h"


/**
 * @class CryptoOnlineAuthWidget
 *
 * @brief Basic implementation of the Authentication widget from the Wt Library. It handles basic user registration,
 *        user login, and linking database information.
 */
class CryptoOnlineAuthWidget : public Wt::Auth::AuthWidget {
public:
    CryptoOnlineAuthWidget(const Wt::Auth::AuthService &baseAuth, Wt::Auth::AbstractUserDatabase &users,
                           Wt::Auth::Login &login, Session& session);

    /**
     * @brief This method overrides the default createRegistrationView method for the Wt::Auth::Widget Class
     *        This method loads the registration view form which allows a user to register and create an account
     *        for the website.
     *
     * @param id Identifies what user has just registered
     * @return
     */
    std::unique_ptr<Wt::WWidget> createRegistrationView(const Wt::Auth::Identity& id) override;


private:
    Session& _session;
};


#endif //CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_AUTH_WIDGET_H

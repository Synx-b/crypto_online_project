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
                           Wt::Auth::Login &login);


};


#endif //CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_AUTH_WIDGET_H

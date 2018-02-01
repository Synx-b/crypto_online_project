/**
 * @file crypto_online_auth_widget.h
 * @date 31/01/2018
 *
 * @author Jacob Powell
 */

#ifndef CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_AUTH_WIDGET_H
#define CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_AUTH_WIDGET_H


#include <Wt/Auth/AuthWidget.h>

class CryptoOnlineAuthWidget : public Wt::Auth::AuthWidget {
public:
    CryptoOnlineAuthWidget(const Wt::Auth::AuthService &baseAuth, Wt::Auth::AbstractUserDatabase &users,
                           Wt::Auth::Login &login);
    CryptoOnlineAuthWidget(Wt::Auth::Login &login);

};


#endif //CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_AUTH_WIDGET_H

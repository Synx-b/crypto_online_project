/**
 * @file crypto_online_auth_widget.cc
 * @date 31/01/2018
 *
 * @author Jacob Powell
 */

#include "crypto_online_auth_widget.h"
#include "../db/session.h"

CryptoOnlineAuthWidget::CryptoOnlineAuthWidget(const Wt::Auth::AuthService &baseAuth,
                                               Wt::Auth::AbstractUserDatabase &users, Wt::Auth::Login &login)
        : AuthWidget(baseAuth, users, login)

{
    this->model()->addPasswordAuth(
            reinterpret_cast<const Wt::Auth::AbstractPasswordService *>(&Session::passwordAuth()));
    //authWidget->model()->addOAuth(Session::oAuth());
    this->setRegistrationEnabled(true);

    this->processEnvironment();
}

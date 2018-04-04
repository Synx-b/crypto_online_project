//
// Created by synx on 3/30/18.
//

#ifndef CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_REGISTER_WIDGET_H
#define CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_REGISTER_WIDGET_H


#include <Wt/Auth/RegistrationWidget.h>
#include "../db/session.h"

class CryptoOnlineRegisterWidget : public Wt::Auth::RegistrationWidget {
public:
    CryptoOnlineRegisterWidget(Wt::Auth::AuthWidget* parent, Session& session);

    void register_new_user(Wt::Auth::User& user);

private:
    Session& _session;
};


#endif //CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_REGISTER_WIDGET_H

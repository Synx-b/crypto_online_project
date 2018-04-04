//
// Created by synx on 3/30/18.
//

#include "crypto_online_register_widget.h"
#include <Wt/WLineEdit.h>

CryptoOnlineRegisterWidget::CryptoOnlineRegisterWidget(Wt::Auth::AuthWidget *parent, Session& session) :
        Wt::Auth::RegistrationWidget(parent),
        _session(session)
{

}


void CryptoOnlineRegisterWidget::register_new_user(Wt::Auth::User &user) {
    _session.new_registered_user(user);
}

/**
 * @file crypto_online_auth_widget.cc
 * @date 31/01/2018
 *
 * @author Jacob Powell
 */

#include "crypto_online_auth_widget.h"
#include "crypto_online_register_widget.h"

CryptoOnlineAuthWidget::CryptoOnlineAuthWidget(const Wt::Auth::AuthService &baseAuth,
                                               Wt::Auth::AbstractUserDatabase &users,
                                               Wt::Auth::Login &login, Session& session)
        : AuthWidget(baseAuth, users, login),
          _session(session)

{
    this->model()->addPasswordAuth(
            reinterpret_cast<const Wt::Auth::AbstractPasswordService *>(&Session::passwordAuth()));
    //this->model()->addOAuth(Session::oAuth());
    this->setRegistrationEnabled(true);

    this->processEnvironment();
}


std::unique_ptr<Wt::WWidget> CryptoOnlineAuthWidget::createRegistrationView(const Wt::Auth::Identity& id) {
    auto registerWidget = Wt::cpp14::make_unique<CryptoOnlineRegisterWidget>(this, _session);
    auto model = this->createRegistrationModel();
    if(id.isValid()){
        model->registerIdentified(id);
    }
    registerWidget->setModel(std::move(model));
    return std::move(registerWidget);
}


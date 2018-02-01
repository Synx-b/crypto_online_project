/**
 * @file crypto_online_launcher.h
 * @date 30/01/2018
 *
 */

#ifndef CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_LAUNCHER_H
#define CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_LAUNCHER_H

#include "db/session.h"

#include <Wt/WApplication.h>
#include <Wt/WBootstrapTheme.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WServer.h>
#include <Wt/WEnvironment.h>

#include <Wt/Auth/AuthWidget.h>
#include <Wt/Auth/PasswordService.h>

class CryptoOnlineLauncher : public Wt::WApplication {
public:
    explicit CryptoOnlineLauncher(const Wt::WEnvironment &environment);

    void auth_event();

private:
    Session _session;
};


#endif //CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_LAUNCHER_H

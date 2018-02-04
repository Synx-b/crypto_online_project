/**
 * @file crypto_online_launcher.h
 * @date 30/01/2018
 *
 * @file Contains Class Definitions for the CryptoOnlineLauncher class
 * @version 0.01
 * @author Jacob Powell
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

/**
 * @class CryptoOnlineLauncher
 *
 * @brief This class is responsible for how the web application is setup and what the settings and configuration
 * options are set.
 */
class CryptoOnlineLauncher : public Wt::WApplication {
public:
    explicit CryptoOnlineLauncher(const Wt::WEnvironment &environment);
    void auth_event(); /**< Method that handles any authentication signals */

private:
    void load_css_files(); /**< Loads the required style files */
    void load_message_bundles(); /**< Loads the required message bundles */

    Session _session; /**< Instance that holds the current session */
};


#endif //CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_LAUNCHER_H

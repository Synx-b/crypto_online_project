/**
 * @file crypto_online_launcher.cc
 * @date 30/01/2018
 *
 * @author Jacob Powell
 */

#include "crypto_online_launcher.h"
#include "layout/crypto_online_home.h"


#include <Wt/WCssTheme.h>

CryptoOnlineLauncher::CryptoOnlineLauncher(const Wt::WEnvironment &environment)
        : WApplication(environment), _session(appRoot() + "auth.db") {
    /**
     * This section gets the current enviroment theme for the project. Then checks if the theme is set to bootstrap3,
     * if it is then it sets the project theme to bootstrap3. If the environment theme is not set to bootstrap3 then
     * It check if the theme is set to bootstrap2, if it is it then makes that the theme. If the environment theme is
     * neither then it just creates a shared WCssTheme and sets that to the theme.
     */
    const std::string *themePtr = environment.getParameter("theme");
    std::string theme;
    if (!themePtr)
        theme = "bootstrap3";
    else
        theme = *themePtr;

    if (theme == "bootstrap3") {
        auto bootstrapTheme = std::make_shared<Wt::WBootstrapTheme>();
        bootstrapTheme->setVersion(Wt::BootstrapVersion::v3);
        bootstrapTheme->setResponsive(true);
        this->setTheme(bootstrapTheme);

        // load the default bootstrap3 (sub-)theme
        this->useStyleSheet("resources/themes/bootstrap/3/bootstrap-theme.min.css");
    } else if (theme == "bootstrap2") {
        auto bootstrapTheme = std::make_shared<Wt::WBootstrapTheme>();
        bootstrapTheme->setResponsive(true);
        this->setTheme(bootstrapTheme);
    } else
        this->setTheme(std::make_shared<Wt::WCssTheme>(theme));

    this->setTitle("Cryptology Online");

    this->_session.login().changed().connect(this, &CryptoOnlineLauncher::auth_event);



    /**
     * Load the necessary style sheets into the project
     */
    this->useStyleSheet("resource/css/crypto_online_header.css");
    this->useStyleSheet("resource/css/crypto_online_grid.css");
    this->useStyleSheet("resource/css/crypto_online_login.css");
    this->useStyleSheet("resource/css/crypto_online_register.css");
    this->useStyleSheet("resource/css/crypto_online_profile.css");
    this->useStyleSheet("resource/css/crypto_online_learning_content.css");

    /**
     * Load the necessary xml templates and message bundles for the project
     */
    this->messageResourceBundle().use(this->appRoot() + "resource/xml-templates/login_template");

    this->messageResourceBundle().use(this->appRoot() + "resource/content_xmls/modular_arithmetic");
    this->messageResourceBundle().use(this->appRoot() + "resource/content_xmls/intro_to_cryptography");

    this->root()->addWidget(Wt::cpp14::make_unique<CryptoOnlineHome>(_session));
    this->root()->setContentAlignment(Wt::AlignmentFlag::Center);
}

void CryptoOnlineLauncher::auth_event() {
    if (_session.login().loggedIn()) {
        std::cout << "AUTH EVENT: CALLED" << std::endl;
        this->root()->clear();
        this->setInternalPath("/home", true);
        this->root()->addWidget(Wt::cpp14::make_unique<CryptoOnlineHome>(_session));
    }else{

    }
}
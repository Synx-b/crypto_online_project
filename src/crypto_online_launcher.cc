/**
 * @file crypto_online_launcher.cc
 * @date 30/01/2018
 *
 * @brief Method definitions for the CryptoOnlineLauncher class
 * @version 0.01
 * @author Jacob Powell
 */

#include "crypto_online_launcher.h"
#include "layout/crypto_online_home.h"


#include <Wt/WCssTheme.h>

/**
 * @brief Constructor for the CryptoOnlineLauncher
 * It loads the initial state including the theme, css files and message bundles
 *
 * @param environment current enviroment that the application is loaded with
 */
CryptoOnlineLauncher::CryptoOnlineLauncher(const Wt::WEnvironment &environment)
        : WApplication(environment), _session(appRoot() + "data.db") {
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

    load_css_files();
    load_message_bundles();

    /**
     * Load the initial settings of the website
     */
    this->root()->addWidget(Wt::cpp14::make_unique<CryptoOnlineHome>(_session));
    this->root()->setContentAlignment(Wt::AlignmentFlag::Center);
}

/**
 * @brief When a change in the authentication is detected this method is called
 */
void CryptoOnlineLauncher::auth_event() {
    if (_session.login().loggedIn()) {
        const Wt::Auth::User& user = _session.login().user();
        std::cout << "User " << user.id()
                  << " (" << user.identity(Wt::Auth::Identity::LoginName)
                  << ") Logged in" << std::endl;
        this->setInternalPath("/home", true);
        _session.link_account_to_database(user);
        this->root()->clear();
        this->root()->addWidget(Wt::cpp14::make_unique<CryptoOnlineHome>(_session));
    }else{
        this->setInternalPath("/home", true);
        std::cout << "User Logged Out" << std::endl;
    }
}

/**
 * @brief This method loads all the required style files
 */
void CryptoOnlineLauncher::load_css_files() {

    this->useStyleSheet("resource/css/CryptoOnlineHeader.css");
    this->useStyleSheet("resource/css/crypto_online_grid.css");
    this->useStyleSheet("resource/css/crypto_online_login.css");
    this->useStyleSheet("resource/css/crypto_online_register.css");
    this->useStyleSheet("resource/css/crypto_online_profile.css");
    this->useStyleSheet("resource/css/crypto_online_learning_content.css");
    this->useStyleSheet("resource/css/crypto_online_aes_example.css");
}

/**
 * @brief Load the necessary xml templates and message bundles for the project
 */
void CryptoOnlineLauncher::load_message_bundles() {

    this->messageResourceBundle().use(this->appRoot() + "resource/xml-templates/answer_template");

    this->messageResourceBundle().use(this->appRoot() + "resource/content_xmls/modular_arithmetic");
    this->messageResourceBundle().use(this->appRoot() + "resource/content_xmls/intro_to_cryptography");

}

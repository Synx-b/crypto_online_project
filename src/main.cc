/**
 * @file main.cc
 * @date 14/12/2017
 *
 * @brief This is the file from which the deployment of the website is launched.
 * It handles the deployment options, the necessary external style files and message bundles
 *
 * @author Jacob Powell
 */

#include "crypto_online_launcher.h"


using namespace Wt;

/**
 * @brief This method initializes and creates the web application.
 * It is responsible for loading bootstrap3 as the main theme and if bootstrap3 is not available then it tries to load
 * bootstrap2 and if that is not possible then it will set the theme to the standard WCssTheme. It is also responsible
 * for loading in the required style sheets and message bundles that are needed.
 *
 * @param env The current environment that the application is running from.
 * @return A live web application for the project to run from.
 */
std::unique_ptr<WApplication> createApplication(const WEnvironment& env)
{
    return cpp14::make_unique<CryptoOnlineLauncher>(env);
}

/**
 * @brief The main function for the project.
 * It created the server instance and configures it for the requirements of the project. It also handles any errors
 * that may stop the flow of the program.
 *
 * @param argc The number of command line arguments
 * @param argv The command line arguments that set the http-listen ip and the port the server will run on. It also sets
 * the current working directory and the links to the necessary directories that contain the style sheets and resources.
 * @return
 */
int main(int argc, char **argv)
{
    try {
        WServer server(argc, argv, WTHTTP_CONFIGURATION);
        server.addEntryPoint(EntryPointType::Application, createApplication);
        Session::configureAuth();
        server.run();
    } catch (WServer::Exception& e) {
        std::cerr << e.what() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "exception: " << e.what() << std::endl;
    }
}

/*
 * File: crypto_online_home.cc
 * Created: 19/12/2017 13:25
 * Finished:
 *
 * Description:
 *
 * Author: Jacob Powell
 */

#ifndef CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_HEADER_H
#define CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_HEADER_H


#include "../../db/db_interface.h"
#include "../../db/db_user.h"
#include "../../db/session.h"

#include <Wt/WHBoxLayout.h>
#include <Wt/WNavigationBar.h>
#include <Wt/WStackedWidget.h>
#include <Wt/WMenu.h>



class crypto_online_header : public Wt::WHBoxLayout{
public:
    explicit crypto_online_header(Session& session);

private:
    void create_navigation_bar();
    void create_user_navigation_bar();

    Session& _current_session;

    std::unique_ptr<Wt::WNavigationBar> navigation_bar;
    std::unique_ptr<Wt::WMenu> left_menu;
    std::unique_ptr<Wt::WMenu> right_menu;

    Wt::WStackedWidget *navigation_bar_contents_stack;

};


#endif //CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_HEADER_H

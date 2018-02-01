/*
 * File: db_interface.h
 * Created: 20/12/2017 19:45
 * Finished:
 *
 * Description:
 *
 * Author: Jacob Powell
 */

#ifndef CRYPTO_ONLINE_PROJECT_DATABASE_INTERFACE_H
#define CRYPTO_ONLINE_PROJECT_DATABASE_INTERFACE_H

#include "db_roles.h"
#include "db_user.h"

#include <Wt/Dbo/Session.h>


class db_interface {
public:

    void connect_database();

    void add_user(std::string username, std::string passwordHash, std::string email,
                  Role role);

    bool check_user_does_not_exist(const std::string &username);
    bool check_user_pass(std::string username, std::string passwordHash);
    int get_user_id(const std::string &username);

    Wt::Dbo::ptr<db_user> get_user_details(const int &id);


private:
    void create_tables();
    Wt::Dbo::Session session;

};


#endif //CRYPTO_ONLINE_PROJECT_DATABASE_INTERFACE_H

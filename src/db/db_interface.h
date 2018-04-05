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

#include "session.h"
#include "db_roles.h"
#include "db_user.h"


class db_interface;

class db_interface {
public:

    explicit db_interface(Session& session) {

    }

    bool does_user_exist_in_dbuser(Session& current_session, const Wt::Auth::User& user);

private:

};


#endif //CRYPTO_ONLINE_PROJECT_DATABASE_INTERFACE_H

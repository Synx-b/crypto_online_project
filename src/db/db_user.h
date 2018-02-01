/**
 * @file db_user.h
 * @date 20/12/2017
 *
 * @brief This file contains the class definition for the db_user class. When reading data from the database, this class
 * is used to hold the temporary data of the user details and when the application is done with the data the object is
 * deleted. This class is the intermediary interface between the application and the database. Data goes from the
 * database and into this class and then we can use it by accessing the object holding the data.
 *
 * @author Jacob Powell
 */

#ifndef CRYPTO_ONLINE_PROJECT_DB_USER_H
#define CRYPTO_ONLINE_PROJECT_DB_USER_H


#include "db_roles.h"

#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/Types.h>
#include <Wt/WGlobal.h>

#include <string>

class db_user;
using AuthInfo = Wt::Auth::Dbo::AuthInfo<db_user>;

class db_user  {
public:
    template<class Action>
    void persist(Action& a) {

    }


private:

};



#endif //CRYPTO_ONLINE_PROJECT_DB_USER_H

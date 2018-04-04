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
#include <Wt/WString.h>

#include <string>

class DbUser;
class Question;

using AuthInfo = Wt::Auth::Dbo::AuthInfo<DbUser>;

class Question {
public:

    Wt::Dbo::ptr<DbUser> user;

    int question_id;
    int answer_id;

    std::string question_text;
    std::string answer_text;


    template<class Action>
    void persist(Action& a){

        Wt::Dbo::field(a, question_id, "question_id");
        Wt::Dbo::field(a, answer_id, "answer_id");
        Wt::Dbo::field(a, question_text, "question_text");
        Wt::Dbo::field(a, answer_text, "answer_text");

        Wt::Dbo::belongsTo(a, user, "user");
    }
};


class DbUser {
public:

    Wt::Dbo::collection< Wt::Dbo::ptr<Question> > questions;

    int user_id;
    Role user_role;
    Wt::WString user_identity;

    template<class Action>
    void persist(Action& a) {

        Wt::Dbo::field(a, user_id, "user_id");
        Wt::Dbo::field(a, user_role, "user_role");
        Wt::Dbo::field(a, user_identity, "user_identity");

        Wt::Dbo::hasMany(a, questions, Wt::Dbo::ManyToOne, "user");
    }

private:

};



#endif //CRYPTO_ONLINE_PROJECT_DB_USER_H

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

#ifndef CRYPTO_ONLINE_PROJECT_DB_QUESTION_H
#define CRYPTO_ONLINE_PROJECT_DB_QUESTION_H


#include "db_roles.h"
#include "db_user.h"

#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/Types.h>
#include <Wt/WGlobal.h>
#include <Wt/WString.h>

#include <string>

class DbUserAnsweredQuestion;
class DbUser;

using AuthInfo = Wt::Auth::Dbo::AuthInfo<DbUser>;

class DbUserAnsweredQuestion {
public:

    Wt::Dbo::ptr<DbUser> user;

    int question_id;
    int answer_id;

    std::string question_text;
    std::string answer_text;


    template<class Action>
    void persist(Action& a){

        Wt::Dbo::field(a, question_id, "user_answered_question_id");
        Wt::Dbo::field(a, answer_id, "user_answered_answer_id");
        Wt::Dbo::field(a, question_text, "user_answered_question_text");
        Wt::Dbo::field(a, answer_text, "user_answered_answer_text");

        Wt::Dbo::belongsTo(a, user, "user");
    }
};


#endif //CRYPTO_ONLINE_PROJECT_DB_QUESTION_H

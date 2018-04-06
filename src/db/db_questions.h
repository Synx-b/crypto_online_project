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

#ifndef CRYPTO_ONLINE_PROJECT_DB_QUESTIONS_H
#define CRYPTO_ONLINE_PROJECT_DB_QUESTIONS_H


#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/Types.h>
#include <Wt/WGlobal.h>
#include <Wt/WString.h>

#include <string>

class DbQuestions;

class DbQuestions {
public:

    std::string question_text;
    std::string question_answer;
    std::string question_option_a;
    std::string question_option_b;
    std::string question_option_c;


    template<class Action>
    void persist(Action& a) {

        Wt::Dbo::field(a, question_text, "question_text");
        Wt::Dbo::field(a, question_answer , "question_answer");
        Wt::Dbo::field(a, question_option_a, "question_option_a");
        Wt::Dbo::field(a, question_option_b, "question_option_b");
        Wt::Dbo::field(a, question_option_c, "question_option_c");
    }

private:

};


#endif //CRYPTO_ONLINE_PROJECT_DB_QUESTIONS_H

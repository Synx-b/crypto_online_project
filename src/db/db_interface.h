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
#include "db_questions.h"


class db_interface;

class db_interface {
public:

    explicit db_interface(Session& session) : current_session(session) {}

    Wt::Dbo::ptr<DbUser> get_user(std::string id);

    void add_answer_to_user(const std::string& answer, int question_id);
    bool check_answer(const std::string& answer, int question_id);
    void set_answer_check_flag(int question_id, bool flag);
    int get_total_questions_answered();
    int get_total_correct_question_answered();


private:

    bool does_answer_exist_user(const int& answer_id);
    Wt::Dbo::ptr<DbUserAnsweredQuestion> get_answer(const int& answer_id);

    Session& current_session;
};


#endif //CRYPTO_ONLINE_PROJECT_DATABASE_INTERFACE_H

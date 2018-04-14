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

    explicit db_interface(Session& session) : current_session(session) {}

    Wt::Dbo::ptr<DbUser> get_user(std::string id);

    void add_answer_to_user(const std::string &answer, const int question_id);


private:

    bool does_answer_exist_user(const int& answer_id);
    Wt::Dbo::ptr<DbUserAnsweredQuestion> get_answer(const int& answer_id);

    Session& current_session;
};


#endif //CRYPTO_ONLINE_PROJECT_DATABASE_INTERFACE_H

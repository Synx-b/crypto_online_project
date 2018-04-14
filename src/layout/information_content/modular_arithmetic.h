/*
 * File: modular_arithmetic.h
 * Created: 15/01/2018 14:35
 * Finished:
 *
 * Description:
 *
 * Author: Jacob Powell
 */

#ifndef CRYPTO_ONLINE_PROJECT_MODULAR_ARITHMETIC_H
#define CRYPTO_ONLINE_PROJECT_MODULAR_ARITHMETIC_H


#include "learning_content_template.h"
#include "../../db/session.h"
#include "../../db/db_interface.h"

#include <Wt/WImage.h>

class modular_arithmetic : public learning_content_template {
public:
    modular_arithmetic(Session& session, std::string &title, std::string &contents_link, std::string &question_link);

private:
    void load_contents() override;
    void load_questions() override;


};


#endif //CRYPTO_ONLINE_PROJECT_MODULAR_ARITHMETIC_H

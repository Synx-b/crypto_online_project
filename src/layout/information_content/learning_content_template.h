/*
 * File: learning_content_template.h
 * Created: 15/01/2018 14:26
 * Finished:
 *
 * Description:
 *
 * Author: Jacob Powell
 */

#ifndef CRYPTO_ONLINE_PROJECT_LEARNING_CONTENT_TEMPLATE_H
#define CRYPTO_ONLINE_PROJECT_LEARNING_CONTENT_TEMPLATE_H


#include <Wt/WTable.h>
#include <Wt/WLineEdit.h>

#include <string>
#include <Wt/WTemplate.h>
#include "../../db/db_interface.h"

class learning_content_template : public Wt::WTable{
public:
    learning_content_template(Session& session, std::string title, std::string contents_link);
    learning_content_template(Session& session, std::string title, std::string contents_link, std::string questions_link);

    virtual void load_contents() = 0;
    virtual void load_questions() = 0;

    std::unique_ptr<Wt::WTemplate> load_question_section(const std::string& template_name, const int question_id[]);

    Wt::WText* page_title;
    Wt::WText* page_content;

    std::string content_title_link;
    std::string content_resource_link;
    std::string content_question_link;
private:
    db_interface database_api;

};


#endif //CRYPTO_ONLINE_PROJECT_LEARNING_CONTENT_TEMPLATE_H

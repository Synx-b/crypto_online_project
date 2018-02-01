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

#include <string>

class learning_content_template : public Wt::WTable{
public:
    learning_content_template(std::string title, std::string contents_link);

    virtual void load_contents() = 0;

    Wt::WText* page_title;
    Wt::WText* page_content;

    std::string content_title_link;
    std::string content_resource_link;


};


#endif //CRYPTO_ONLINE_PROJECT_LEARNING_CONTENT_TEMPLATE_H

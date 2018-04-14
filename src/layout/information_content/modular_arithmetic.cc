/*
 * File: modular_arithmetic.cc
 * Created: 15/01/2018 14:35
 * Finished:
 *
 * Description:
 *
 * Author: Jacob Powell
 */

#include "modular_arithmetic.h"

#include <Wt/WText.h>
#include <Wt/WTemplate.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>

modular_arithmetic::modular_arithmetic(Session& session, std::string &title, std::string &contents_link, std::string &question_link) :
        learning_content_template(session, title, contents_link, question_link){
    load_contents();
    load_questions();
}

void modular_arithmetic::load_contents() {
    this->page_title = this->elementAt(0,0)->addWidget(Wt::cpp14::make_unique<Wt::WText>
                                                               (Wt::WString::tr(this->content_title_link)));
    this->elementAt(0,0)->setStyleClass("learning_content_title");
    this->page_content = this->elementAt(1,0)->addWidget(Wt::cpp14::make_unique<Wt::WText>
                                                                 (Wt::WString::tr(this->content_resource_link)));
    this->elementAt(1,0)->setStyleClass("learning_content_content");
}

void modular_arithmetic::load_questions() {
    const int question_id[] = {21, 22};
    std::cout << question_id[0] << std::endl;
    auto result = learning_content_template::load_question_section(this->content_question_link, question_id);
    this->elementAt(2,0)->addWidget(std::move(result));
}


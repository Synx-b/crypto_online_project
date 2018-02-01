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

modular_arithmetic::modular_arithmetic(std::string &title, std::string &contents_link) :
        learning_content_template(title, contents_link) {
    load_contents();

}

void modular_arithmetic::load_contents() {
    this->page_title = this->elementAt(0,0)->addWidget(Wt::cpp14::make_unique<Wt::WText>
                                                               (Wt::WString::tr(this->content_title_link)));
    this->elementAt(0,0)->setStyleClass("learning_content_title");

    this->page_content = this->elementAt(1,0)->addWidget(Wt::cpp14::make_unique<Wt::WText>
                                                                 (Wt::WString::tr(this->content_resource_link)));
    this->page_content->setStyleClass("learning_content_content");
    this->elementAt(1,0)->setContentAlignment(Wt::AlignmentFlag::Center);

}

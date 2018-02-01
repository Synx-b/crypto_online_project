/*
 * File: intro_to_cryptography.cc
 * Created: 24/01/2018 9:00
 * Finished:
 *
 * Description:
 *
 * Author: Jacob Powell
 */

#include "intro_to_cryptography.h"

#include <Wt/WText.h>

intro_to_cryptography::intro_to_cryptography(std::string title, std::string contents_link)
        : learning_content_template(std::move(title), std::move(contents_link)) {
    load_contents();
}

void intro_to_cryptography::load_contents() {
    this->page_title = this->elementAt(0,0)->addWidget(Wt::cpp14::make_unique<Wt::WText>
                                                               (Wt::WString::tr(this->content_title_link)));
    this->elementAt(0,0)->setStyleClass("learning_content_title");

    this->page_content = this->elementAt(1,0)->addWidget(Wt::cpp14::make_unique<Wt::WText>
                                                                 (Wt::WString::tr(this->content_resource_link)));
    this->elementAt(1,0)->setStyleClass("learning_content_content");
    this->elementAt(1,0)->setContentAlignment(Wt::AlignmentFlag::Left);


}

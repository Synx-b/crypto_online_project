/*
 * File: crypto_online_home.cc
 * Created: 20/12/2017 20:16
 * Finished:
 *
 * Description:
 *
 * Author: Jacob Powell
 */

#include "crypto_online_footer.h"

#include <Wt/WText.h>

crypto_online_footer::crypto_online_footer() {
    auto footer = Wt::cpp14::make_unique<Wt::WText>("FOOTER LOCATION");
    this->addWidget(std::move(footer),0,0,Wt::AlignmentFlag::Center);
}

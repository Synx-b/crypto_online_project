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

#include <Wt/WImage.h>

class modular_arithmetic : public learning_content_template {
public:
    modular_arithmetic(std::string &title, std::string &contents_link);
    void load_contents() override;

};


#endif //CRYPTO_ONLINE_PROJECT_MODULAR_ARITHMETIC_H

/*
 * File: intro_to_cryptography.h
 * Created: 24/01/2018 9:00
 * Finished:
 *
 * Description:
 *
 * Author: Jacob Powell
 */

#ifndef CRYPTO_ONLINE_PROJECT_INTRO_TO_CRYPTOGRAPHY_H
#define CRYPTO_ONLINE_PROJECT_INTRO_TO_CRYPTOGRAPHY_H


#include "learning_content_template.h"

class intro_to_cryptography : public learning_content_template {
public:
    intro_to_cryptography(std::string title, std::string contents_link);

    void load_contents() override;
private:

};


#endif //CRYPTO_ONLINE_PROJECT_INTRO_TO_CRYPTOGRAPHY_H

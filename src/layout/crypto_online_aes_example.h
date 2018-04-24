/**
 * @file crypto_online_aes_example.h
 * @date 15/04/2018
 *
 * @brief This file contains the class that loads the AES Example page
 *
 * @author Jacob Powell
 */

#ifndef CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_AES_EXAMPLE_H
#define CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_AES_EXAMPLE_H

#include "../crypto/aes_implementation.h"

#include <Wt/WTable.h>
#include <Wt/WLineEdit.h>
#include <Wt/WText.h>
#include <Wt/WTextArea.h>
#include <Wt/WPushButton.h>

class CryptoOnlineAESExample : public Wt::WTable {
public:
    CryptoOnlineAESExample();

private:

    void load_page_content();
    void process();
    void hexstring_to_array(std::string hexstring, byte out[], int length);
    uint8_t hex_char_to_string(char c);

    Wt::WLineEdit* plaintext_entry;
    Wt::WLineEdit* key_entry;

    Wt::WText* plaintext_error;
    Wt::WText* key_error;

    Wt::WTextArea* ciphertext_area;

    AESImplementation aes_implementation;
};


#endif //CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_AES_EXAMPLE_H

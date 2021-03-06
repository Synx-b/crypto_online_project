/**
 * @file crypto_online_aes_example.cc
 * @date 15/04/2018
 *
 * @author Jacob Powell
 */

#include "crypto_online_aes_example.h"

CryptoOnlineAESExample::CryptoOnlineAESExample() {
    load_page_content();
}

void CryptoOnlineAESExample::load_page_content() {
    this->elementAt(0,0)->addWidget(Wt::cpp14::make_unique<Wt::WText>("Plaintext: "));
    this->elementAt(0,0)->setStyleClass("aes_example_text");
    this->elementAt(0,0)->setContentAlignment(Wt::AlignmentFlag::Right);
    this->plaintext_entry = this->elementAt(0,1)->addWidget(Wt::cpp14::make_unique<Wt::WLineEdit>());
    this->elementAt(0,1)->setStyleClass("aes_example_entry");
    this->elementAt(0,1)->setContentAlignment(Wt::AlignmentFlag::Left);
    this->elementAt(0,1)->setPadding(500, Wt::Side::Right);
    this->plaintext_error = this->elementAt(0,2)->addWidget(Wt::cpp14::make_unique<Wt::WText>());
    this->elementAt(0,2)->setContentAlignment(Wt::AlignmentFlag::Left);


    this->elementAt(1,0)->addWidget(Wt::cpp14::make_unique<Wt::WText>("Key: "));
    this->elementAt(1,0)->setStyleClass("aes_example_text");
    this->elementAt(1,0)->setContentAlignment(Wt::AlignmentFlag::Right);
    this->key_entry = this->elementAt(1,1)->addWidget(Wt::cpp14::make_unique<Wt::WLineEdit>());
    this->elementAt(1,1)->setStyleClass("aes_example_entry");
    this->elementAt(1,1)->setContentAlignment(Wt::AlignmentFlag::Left);
    this->elementAt(1,1)->setPadding(500, Wt::Side::Right);
    this->key_error = this->elementAt(0,2)->addWidget(Wt::cpp14::make_unique<Wt::WText>());
    this->elementAt(0,2)->setContentAlignment(Wt::AlignmentFlag::Left);

    auto start_encrypt_process = this->elementAt(2,0)->addWidget(Wt::cpp14::make_unique<Wt::WPushButton>("Encrypt"));
    this->elementAt(2,0)->setContentAlignment(Wt::AlignmentFlag::Right);
    start_encrypt_process->setStyleClass("aes_example_text");
    start_encrypt_process->clicked().connect([=]{
        this->process();
    });

    this->elementAt(3,0)->addWidget(Wt::cpp14::make_unique<Wt::WText>("Ciphertext: "));
    this->elementAt(3,0)->setStyleClass("aes_example_text");
    this->elementAt(3,0)->setContentAlignment(Wt::AlignmentFlag::Right);
    this->ciphertext_area = this->elementAt(3,1)->addWidget(Wt::cpp14::make_unique<Wt::WTextArea>());
    this->elementAt(3,1)->setStyleClass("aes_example_entry");
    this->elementAt(3,1)->setContentAlignment(Wt::AlignmentFlag::Left);
    this->elementAt(3,1)->setPadding(500, Wt::Side::Right);
}

void CryptoOnlineAESExample::process() {

    std::string plaintext = this->plaintext_entry->text().toUTF8();
    std::string key = this->key_entry->text().toUTF8();
    std::string ciphertext = "";

    if(plaintext.length() != 32) {
        this->plaintext_error->setText("Plaintext needs to be 32 Hex Characters");
        this->plaintext_error->setStyleClass("error_message");
    }else if(key.length() != 16 && key.length() != 24 && key.length() != 32){
        this->key_error->setText("Key needs to be 32, 48 or 64 Hex Characters Long");
        this->key_error->setStyleClass("error_message");
    }
    else{
        byte output[16];
        aes_implementation.encrypt_block((const byte*)plaintext.data(), output, (const byte*)key.data());
        for(int i = 0; i < 16; i++) {
            std::cout << unsigned(output[i]);
            ciphertext += std::to_string(unsigned(output[i]));
        }
        std::cout << std::endl;
        this->ciphertext_area->setText(ciphertext);
    }

}





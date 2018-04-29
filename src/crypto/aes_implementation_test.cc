/**
 * @file aes_implementation_test.cc
 * @date 28/02/2018
 *
 * @breif This file will contain test methods to verify the functionality of my implementation of the AES Algorithm
 *        All of the test keys and plaintexts are the same as shown in FIPS 197.
 *
 * @version 0.01
 * @author Jacob Powell
 *
 */

#include "aes_implementation.h"

#include <iostream>
#include <iomanip>

void test_aes_256(){
    AESImplementation aes(AES256);
    byte key_256[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
                      0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f};
    byte plaintext[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
    byte ciphertext[16];
    byte plaintext2[16];

    std::cout << "Plaintext: ";
    for(byte i = 0; i < 16; i++){
        std::cout << std::hex << std::setfill('0') << std::setw(2) << unsigned(plaintext[i]);
    }
    std::cout << std::endl;

    std::cout << "Key: ";
    for(byte i = 0; i < 32; i++){
        std::cout << std::hex << std::setfill('0') << std::setw(2) << unsigned(key_256[i]);
    }
    std::cout << std::endl;

    aes.encrypt_block(plaintext, ciphertext, key_256);

    std::cout << "Cipher Text: ";
    for(byte i = 0; i < 16; i++){
        std::cout << std::hex << std::setfill('0') << std::setw(2) << unsigned(ciphertext[i]);
    }
    std::cout << std::endl;

    aes.decrypt_block(ciphertext, plaintext2, key_256);

    std::cout << "Plaintext: ";
    for(byte i = 0; i < 16; i++){
        std::cout << std::hex << std::setfill('0') << std::setw(2) << unsigned(plaintext2[i]);
    }
    std::cout << std::endl;

    std::cout << std::endl;
}

void test_aes_192(){
    AESImplementation aes(AES192);
    byte key_192[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
                      0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17};
    byte plaintext[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
    byte ciphertext[16];
    byte plaintext2[16];

    std::cout << "Plaintext: ";
    for(byte i = 0; i < 16; i++){
        std::cout << std::hex << std::setfill('0') << std::setw(2) << unsigned(plaintext[i]);
    }
    std::cout << std::endl;

    std::cout << "Key: ";
    for(byte i = 0; i < 24; i++){
        std::cout << std::hex << std::setfill('0') << std::setw(2) << unsigned(key_192[i]);
    }
    std::cout << std::endl;

    aes.encrypt_block(plaintext, ciphertext, key_192);

    std::cout << "Cipher Text: ";
    for(byte i = 0; i < 16; i++){
        std::cout << std::hex << std::setfill('0') << std::setw(2) << unsigned(ciphertext[i]);
    }
    std::cout << std::endl;

    aes.decrypt_block(ciphertext, plaintext2, key_192);

    std::cout << "Plaintext: ";
    for(byte i = 0; i < 16; i++){
        std::cout << std::hex << std::setfill('0') << std::setw(2) << unsigned(plaintext2[i]);
    }
    std::cout << std::endl;

    std::cout << std::endl;
}

void test_aes_128(){
    AESImplementation aes(AES128);

    byte key_128[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
    byte plaintext[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};

    byte ciphertext[16];
    byte plaintext2[16];

    std::cout << "Plaintext: ";
    for(byte i = 0; i < 16; i++){
        std::cout << std::hex << std::setfill('0') << std::setw(2) << unsigned(plaintext[i]);
    }
    std::cout << std::endl;

    std::cout << "Key: ";
    for(byte i = 0; i < 16; i++){
        std::cout << std::hex << std::setfill('0') << std::setw(2) << unsigned(key_128[i]);
    }
    std::cout << std::endl;

    aes.encrypt_block(plaintext, ciphertext, key_128);

    std::cout << "Cipher Text: ";
    for(byte i = 0; i < 16; i++){
        std::cout << std::hex << std::setfill('0') << std::setw(2) << unsigned(ciphertext[i]);
    }
    std::cout << std::endl;

    aes.decrypt_block(ciphertext, plaintext2, key_128);

    std::cout << "Plaintext: ";
    for(byte i = 0; i < 16; i++){
        std::cout << std::hex << std::setfill('0') << std::setw(2) << unsigned(plaintext2[i]);
    }
    std::cout << std::endl;

    std::cout << std::endl;

}


int main(){
    test_aes_128();
    test_aes_192();
    test_aes_256();
}
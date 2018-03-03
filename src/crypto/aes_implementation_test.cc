/**
 * @file aes_implementation_test.cc
 * @date 28/02/2018
 *
 * @breif This file will contain test methods to verify the functionality of my implementaiton of the AES Algorithm
 *
 * @version 0.01
 * @author Jacob Powell
 *
 */

#include <cstdint>
#include <string>
#include <iostream>
#include "aes_implementation.h"


void outputHexArray(uint8_t array[]);

char hexchar(int num){
    switch(num){
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        case 10:
            return 'A';
        case 11:
            return 'B';
        case 12:
            return 'C';
        case 13:
            return 'D';
        case 14:
            return 'E';
        case 15:
            return 'F';
        default:
            return 'p';
    }
}

void test_aes_128(){
    AESImplementation aes(AES128);

    uint8_t key[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,
                    0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
    uint8_t plaintext[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99,
                    0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xdd};
    uint8_t ciphertext[16];

    aes.encrypt(plaintext, key, ciphertext);

    outputHexArray(ciphertext);

}

void outputHexArray(uint8_t array[]){
    for(int i = 0; i < 16; i++){
        std::cout << "+" << array[i] << "+";
    }
    std::cout << std::endl << "End" << std::endl;
}

int main(){
    test_aes_128();
}
/**
 * @file aes_implementation.cc
 * @date 14/01/2018
 *
 * @brief This file contains my method definitions for my AES Implementation
 *
 * @version 0.01
 * @author Jacob Powell
 */

#include <stdexcept>
#include <cstring>
#include <iostream>
#include <iomanip>

#include "aes_implementation.h"

/**< Precomputed Tables and Lookup tables are given below */

static byte sbox[256] = {
        0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
        0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
        0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
        0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
        0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
        0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
        0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
        0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
        0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
        0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
        0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
        0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
        0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
        0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
        0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
        0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16};

static byte inverse_sbox[256] = {
        0x52, 0x09, 0x6A, 0xD5, 0x30, 0x36, 0xA5, 0x38, 0xBF, 0x40, 0xA3, 0x9E, 0x81, 0xF3, 0xD7, 0xFB,
        0x7C, 0xE3, 0x39, 0x82, 0x9B, 0x2F, 0xFF, 0x87, 0x34, 0x8E, 0x43, 0x44, 0xC4, 0xDE, 0xE9, 0xCB,
        0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D, 0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E,
        0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2, 0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B, 0xD1, 0x25,
        0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xD4, 0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92,
        0x6C, 0x70, 0x48, 0x50, 0xFD, 0xED, 0xB9, 0xDA, 0x5E, 0x15, 0x46, 0x57, 0xA7, 0x8D, 0x9D, 0x84,
        0x90, 0xD8, 0xAB, 0x00, 0x8C, 0xBC, 0xD3, 0x0A, 0xF7, 0xE4, 0x58, 0x05, 0xB8, 0xB3, 0x45, 0x06,
        0xD0, 0x2C, 0x1E, 0x8F, 0xCA, 0x3F, 0x0F, 0x02, 0xC1, 0xAF, 0xBD, 0x03, 0x01, 0x13, 0x8A, 0x6B,
        0x3A, 0x91, 0x11, 0x41, 0x4F, 0x67, 0xDC, 0xEA, 0x97, 0xF2, 0xCF, 0xCE, 0xF0, 0xB4, 0xE6, 0x73,
        0x96, 0xAC, 0x74, 0x22, 0xE7, 0xAD, 0x35, 0x85, 0xE2, 0xF9, 0x37, 0xE8, 0x1C, 0x75, 0xDF, 0x6E,
        0x47, 0xF1, 0x1A, 0x71, 0x1D, 0x29, 0xC5, 0x89, 0x6F, 0xB7, 0x62, 0x0E, 0xAA, 0x18, 0xBE, 0x1B,
        0xFC, 0x56, 0x3E, 0x4B, 0xC6, 0xD2, 0x79, 0x20, 0x9A, 0xDB, 0xC0, 0xFE, 0x78, 0xCD, 0x5A, 0xF4,
        0x1F, 0xDD, 0xA8, 0x33, 0x88, 0x07, 0xC7, 0x31, 0xB1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xEC, 0x5F,
        0x60, 0x51, 0x7F, 0xA9, 0x19, 0xB5, 0x4A, 0x0D, 0x2D, 0xE5, 0x7A, 0x9F, 0x93, 0xC9, 0x9C, 0xEF,
        0xA0, 0xE0, 0x3B, 0x4D, 0xAE, 0x2A, 0xF5, 0xB0, 0xC8, 0xEB, 0xBB, 0x3C, 0x83, 0x53, 0x99, 0x61,
        0x17, 0x2B, 0x04, 0x7E, 0xBA, 0x77, 0xD6, 0x26, 0xE1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0C, 0x7D};

static byte galois_mul_3[256] = {
        0x00,0x03,0x06,0x05,0x0c,0x0f,0x0a,0x09,0x18,0x1b,0x1e,0x1d,0x14,0x17,0x12,0x11,
        0x30,0x33,0x36,0x35,0x3c,0x3f,0x3a,0x39,0x28,0x2b,0x2e,0x2d,0x24,0x27,0x22,0x21,
        0x60,0x63,0x66,0x65,0x6c,0x6f,0x6a,0x69,0x78,0x7b,0x7e,0x7d,0x74,0x77,0x72,0x71,
        0x50,0x53,0x56,0x55,0x5c,0x5f,0x5a,0x59,0x48,0x4b,0x4e,0x4d,0x44,0x47,0x42,0x41,
        0xc0,0xc3,0xc6,0xc5,0xcc,0xcf,0xca,0xc9,0xd8,0xdb,0xde,0xdd,0xd4,0xd7,0xd2,0xd1,
        0xf0,0xf3,0xf6,0xf5,0xfc,0xff,0xfa,0xf9,0xe8,0xeb,0xee,0xed,0xe4,0xe7,0xe2,0xe1,
        0xa0,0xa3,0xa6,0xa5,0xac,0xaf,0xaa,0xa9,0xb8,0xbb,0xbe,0xbd,0xb4,0xb7,0xb2,0xb1,
        0x90,0x93,0x96,0x95,0x9c,0x9f,0x9a,0x99,0x88,0x8b,0x8e,0x8d,0x84,0x87,0x82,0x81,
        0x9b,0x98,0x9d,0x9e,0x97,0x94,0x91,0x92,0x83,0x80,0x85,0x86,0x8f,0x8c,0x89,0x8a,
        0xab,0xa8,0xad,0xae,0xa7,0xa4,0xa1,0xa2,0xb3,0xb0,0xb5,0xb6,0xbf,0xbc,0xb9,0xba,
        0xfb,0xf8,0xfd,0xfe,0xf7,0xf4,0xf1,0xf2,0xe3,0xe0,0xe5,0xe6,0xef,0xec,0xe9,0xea,
        0xcb,0xc8,0xcd,0xce,0xc7,0xc4,0xc1,0xc2,0xd3,0xd0,0xd5,0xd6,0xdf,0xdc,0xd9,0xda,
        0x5b,0x58,0x5d,0x5e,0x57,0x54,0x51,0x52,0x43,0x40,0x45,0x46,0x4f,0x4c,0x49,0x4a,
        0x6b,0x68,0x6d,0x6e,0x67,0x64,0x61,0x62,0x73,0x70,0x75,0x76,0x7f,0x7c,0x79,0x7a,
        0x3b,0x38,0x3d,0x3e,0x37,0x34,0x31,0x32,0x23,0x20,0x25,0x26,0x2f,0x2c,0x29,0x2a,
        0x0b,0x08,0x0d,0x0e,0x07,0x04,0x01,0x02,0x13,0x10,0x15,0x16,0x1f,0x1c,0x19,0x1a};

static byte galois_mul_2[256] = {
        0x00,0x02,0x04,0x06,0x08,0x0a,0x0c,0x0e,0x10,0x12,0x14,0x16,0x18,0x1a,0x1c,0x1e,
        0x20,0x22,0x24,0x26,0x28,0x2a,0x2c,0x2e,0x30,0x32,0x34,0x36,0x38,0x3a,0x3c,0x3e,
        0x40,0x42,0x44,0x46,0x48,0x4a,0x4c,0x4e,0x50,0x52,0x54,0x56,0x58,0x5a,0x5c,0x5e,
        0x60,0x62,0x64,0x66,0x68,0x6a,0x6c,0x6e,0x70,0x72,0x74,0x76,0x78,0x7a,0x7c,0x7e,
        0x80,0x82,0x84,0x86,0x88,0x8a,0x8c,0x8e,0x90,0x92,0x94,0x96,0x98,0x9a,0x9c,0x9e,
        0xa0,0xa2,0xa4,0xa6,0xa8,0xaa,0xac,0xae,0xb0,0xb2,0xb4,0xb6,0xb8,0xba,0xbc,0xbe,
        0xc0,0xc2,0xc4,0xc6,0xc8,0xca,0xcc,0xce,0xd0,0xd2,0xd4,0xd6,0xd8,0xda,0xdc,0xde,
        0xe0,0xe2,0xe4,0xe6,0xe8,0xea,0xec,0xee,0xf0,0xf2,0xf4,0xf6,0xf8,0xfa,0xfc,0xfe,
        0x1b,0x19,0x1f,0x1d,0x13,0x11,0x17,0x15,0x0b,0x09,0x0f,0x0d,0x03,0x01,0x07,0x05,
        0x3b,0x39,0x3f,0x3d,0x33,0x31,0x37,0x35,0x2b,0x29,0x2f,0x2d,0x23,0x21,0x27,0x25,
        0x5b,0x59,0x5f,0x5d,0x53,0x51,0x57,0x55,0x4b,0x49,0x4f,0x4d,0x43,0x41,0x47,0x45,
        0x7b,0x79,0x7f,0x7d,0x73,0x71,0x77,0x75,0x6b,0x69,0x6f,0x6d,0x63,0x61,0x67,0x65,
        0x9b,0x99,0x9f,0x9d,0x93,0x91,0x97,0x95,0x8b,0x89,0x8f,0x8d,0x83,0x81,0x87,0x85,
        0xbb,0xb9,0xbf,0xbd,0xb3,0xb1,0xb7,0xb5,0xab,0xa9,0xaf,0xad,0xa3,0xa1,0xa7,0xa5,
        0xdb,0xd9,0xdf,0xdd,0xd3,0xd1,0xd7,0xd5,0xcb,0xc9,0xcf,0xcd,0xc3,0xc1,0xc7,0xc5,
        0xfb,0xf9,0xff,0xfd,0xf3,0xf1,0xf7,0xf5,0xeb,0xe9,0xef,0xed,0xe3,0xe1,0xe7,0xe5};

static byte rcon[256] = {
        0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a,
        0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39,
        0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a,
        0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8,
        0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef,
        0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc,
        0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b,
        0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3,
        0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94,
        0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20,
        0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35,
        0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f,
        0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04,
        0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63,
        0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd,
        0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d
};


AESImplementation::AESImplementation(AESKeyLengths keyLength) : _n(0),
                                                                _b(0),
                                                                _number_of_rounds(0),
                                                                _block_size(0){
    switch(keyLength){
        case AES128:
            this->_number_of_rounds = 10;
            this->_n = 16;
            this->_b = 176;
            this->_m = 0;
            this->_key_size_decrementer = 16;
            break;
        case AES192:
            this->_number_of_rounds = 12;
            this->_n = 24;
            this->_b = 208;
            this->_m = 2;
            this->_key_size_decrementer = 24;
            break;
        case AES256:
            this->_number_of_rounds = 14;
            this->_n = 32;
            this->_b = 240;
            this->_m = 3;
            this->_key_size_decrementer = 32;
            break;
        default:
            throw std::runtime_error("Invalid key length");
    }
}

void AESImplementation::encrypt(const byte input[], byte output[], const byte key[]) {

    for(byte i = 0; i < 16; i++){
        std::cout << std::hex << std::setfill('0') << std::setw(2) << unsigned(key[i]);
    }
    std::cout << std::endl;

    for(byte i = 0; i < 4; i++){
        this->_state[i][0] = input[i];
        this->_state[i][1] = input[i + 4];
        this->_state[i][2] = input[i + 8];
        this->_state[i][3] = input[i + 12];
    }

    this->outputState("Start");

    byte expanded_key[this->_b];
    this->KeyExpansion(key, expanded_key);

    std::cout << "Key Expansion: ";
    for(byte i = 0; i < this->_b; i++){
        std::cout << (unsigned)expanded_key[i];
    }
    std::cout << std::endl;

    for(byte i = 0; i < 4; i++){
        this->_round_key[i][0] = expanded_key[i];
        this->_round_key[i][1] = expanded_key[i + 4];
        this->_round_key[i][2] = expanded_key[i + 8];
        this->_round_key[i][3] = expanded_key[i + 12];
    }

    this->AddRoundKey(this->_state, this->_round_key);

    for(byte current_round = 1; current_round < this->_number_of_rounds; current_round++){
        for(byte i = 0; i < 4; i++)
            for(byte j = 0; j < 4; j++){
                this->_round_key[i][j] = expanded_key[(current_round * this->_block_size) + (j * 4) + i];
            }
        this->SubBytes(this->_state);
        this->ShiftRows(this->_state);
        if(current_round != this->_number_of_rounds) {
            this->MixColumns(this->_state);
        }
        this->AddRoundKey(this->_state, this->_round_key);
    }

    for(byte i = 0; i < 4; i++){
        for(byte j = 0; j < 4; j++){
            output[(j * 4) + i] = this->_state[i][j];
        }
    }
}


void AESImplementation::KeyExpansion(const byte key[], byte expandedKey[]) const {

    //std::cout << "Key Expansion Start" << std::endl;

    memset(expandedKey, 0, this->_b);
    memcpy(expandedKey, key, this->_n);

    //std::cout << "W[0-3]:";
    /*for(byte i = 0; i < 16; i++){
        std::cout << std::hex << std::setfill('0') << std::setw(2) << unsigned(expandedKey[i]);
    }
    std::cout << std::endl;*/

    byte keySizeIterator = 0;
    keySizeIterator += this->_n;

    byte t[4];
    byte u[4];

    for(byte rcon = 1; keySizeIterator < this->_b; rcon++){

        memcpy(t, expandedKey + (keySizeIterator - 4), 4);

        /*std::cout << "PRE 4: ";
        for(byte i = 0; i < 4; i++)
            std::cout << std::hex << std::setfill('0') << std::setw(2) << unsigned(t[i]);
        std::cout << std::endl;*/

        this->KeyExpansionCore(rcon, t, u);
        memcpy(t, expandedKey + (keySizeIterator - this->_n), 4 * sizeof(byte));

        /*std::cout << "W[i - 4]: ";
        for(byte i = 0; i < 4; i++)
            std::cout << std::hex << std::setfill('0') << std::setw(2) << unsigned(u[i]);
        std::cout << std::endl;*/

        for(byte i = 0; i < 4; i++)
            t[i] ^= u[i];

        /*std::cout << "W[i]: ";
        for(byte i = 0; i < 4; i++)
            std::cout << std::hex << std::setfill('0') << std::setw(2) << unsigned(t[i]);
        std::cout << std::endl;*/

        memcpy(expandedKey + keySizeIterator, t, 4 * sizeof(byte));
        keySizeIterator += 4;

        for(byte i = 0; i < 3 && (keySizeIterator < this->_b); i++){
            memcpy(t, expandedKey + (keySizeIterator  - 4), 4 * sizeof(byte));

            //std::cout << "temp: ";
            for (byte j = 0; j < 4; j++)
            {
                expandedKey[keySizeIterator + j] = t[j] ^ expandedKey[keySizeIterator - this->_n + j];
                //std::cout << (unsigned)expandedKey[keySizeIterator + j];
            }
            //std::cout << std::endl;

            keySizeIterator += 4;
        }


    }


    int count = 0;
    std::cout << "Expanded Key: ";
    for(byte i = 0; i < 176; i++){
        if(count % 16 == 0)
            std::cout << std::endl;

        std::cout << std::hex << std::setfill('0') << std::setw(2) << unsigned(expandedKey[i]);
        count++;
    }

    std::cout << std::endl;

    std::cout << "Key Expansion End" << std::endl;
}

void AESImplementation::KeyExpansionCore(byte roundNumber, const byte keyIn[4], byte keyOut[4]){

    //std::cout << "Key Expansion Core Start" << std::endl;

    //std::cout << "KEY OUT: ";

    /*for(byte i = 0; i < 4; i++){
        std::cout << std::hex << std::setfill('0') << std::setw(2) << unsigned(keyOut[i]);
    }
    std::cout << std::endl;*/

    //std::cout << "KEY IN: ";

    /*for(byte i = 0; i < 4; i++){
        std::cout << std::hex << std::setfill('0') << std::setw(2) << unsigned(keyIn[i]);
    }
    std::cout << std::endl;*/

    memcpy(keyOut, keyIn, 4);

    /**
     * Rotation Step
     */
    byte temp = keyOut[0];
    for(byte i = 0; i < 3; i++){
        keyOut[i] = keyOut[i+1];
    }
    keyOut[3] = temp;

    /*std::cout << "After Rotation: ";

    for(byte i = 0; i < 4; i++){
        std::cout << std::hex << std::setfill('0') << std::setw(2) << unsigned(keyOut[i]);
    }
    std::cout << std::endl;*/

    /**
     * Substitution Step
     */
    for(byte i = 0; i < 4; i++){
        keyOut[i] = sbox[keyOut[i]];
    }

    /*std::cout << "After Substitution: ";
    for(byte i = 0; i < 4; i++){
        std::cout << std::hex << std::setfill('0') << std::setw(2) << unsigned(keyOut[i]);
    }
    std::cout << std::endl;*/


    keyOut[0] = keyOut[0] ^ rcon[roundNumber];

    /*std::cout << "After XOR With RCON: ";
    for(byte i = 0; i < 4; i++){
        std::cout << std::hex << std::setfill('0') << std::setw(2) << unsigned(keyOut[i]);
    }
    std::cout << std::endl;*/

    //std::cout << "Key Expansion Core End" << std::endl;

}

void AESImplementation::AddRoundKey(byte state[4][4], byte roundKey[4][4]) {
    for(byte i = 0; i < 4; i++){
        auto* key = reinterpret_cast<uint32_t *>(roundKey[i]);
        auto* row_state = reinterpret_cast<uint32_t *>(state[i]);
        *row_state ^= *key;
    }
}

void AESImplementation::SubBytes(byte state[4][4]) {
    for(byte i = 0; i < 4; i++)
        for(byte j = 0; j < 4; j++)
            state[i][j] = sbox[state[i][j]];
}

void AESImplementation::ShiftRows(byte state[4][4]) {
    for(byte i = 1; i < 4; i++){
        byte row[4];
        for(byte j = 0; j < 4; j++)
            row[j] = state[i][j];
        for(byte j = 0; j < 4; j++)
            state[i][j] = row[(i + j) % 4];
    }
}

void AESImplementation::MixColumns(byte state[4][4]) {

    for(byte i = 0; i < 4; i++){
        byte column[4] = {state[0][i], state[1][i], state[2][i], state[3][i],};

        state[0][i] = galois_mul_2[column[0]] ^ galois_mul_3[column[1]] ^ column[2] ^ column[3];
        state[1][i] = column[0] ^ galois_mul_2[column[1]] ^ galois_mul_3[column[2]] ^ column[3];
        state[2][i] = column[0] ^ column[1] ^ galois_mul_2[column[2]] ^ galois_mul_3[column[3]];
        state[3][i] = galois_mul_3[column[0]] ^ column[1] ^ column[2] ^ galois_mul_2[column[3]];

    }
}

void AESImplementation::outputState(std::string prefix) {

    if(prefix == "START"){
        std::cout << "PLAINTEXT: ";
        for(byte i = 0; i < 4; i++){
            for(byte j = 0; j < 4; j++){
                std::cout << std::hex << std::setfill('0') << std::setw(2) << unsigned(this->_state[j][i]);
            }
        }
        std::cout << std::endl << "KEY: ";
        for(byte i = 0; i < 16; i++){
            std::cout << std::hex << std::setfill('0') << std::setw(2) << unsigned(this->_round_key[i]);
        }
    }

    std::cout << std::endl;
}

void AESImplementation::outputKeyExpansion(std::string prefix) const {
    std::cout << this->expandedKey;
}


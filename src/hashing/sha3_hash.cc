/**
 * @file sha3_hash.cc
 * @date 20/12/2017
 * @version 0.01
 *
 * @brief This file contains the class method body definitions
 *
 * @author Jacob Powell
 */

#include "sha3_hash.h"

#include <iostream>

/**
 * @brief This is just a the default constructor the class
 */
SHA3_512::SHA3_512() = default;

/**
 * @brief This method takes a message as a parameter and returns a hash of that message
 *
 * @param message The plaintext message that needs to be hashed
 * @return The SHA3_512 hash of the parameter message
 */
std::string SHA3_512::compute_hash(const std::string message) {
    if(this->message.length() != 0 || this->hashed_message_bytes != nullptr || this->hashed_string.length() != 0){
        this->message.clear();
        this->hashed_string.clear();
        null_array();
    }

    this->message = message;
    SHA3.CalculateDigest(this->hashed_message_bytes, (const CryptoPP::byte*)this->message.data(), (std::size_t)this->message.length());

    hex_encoder.Attach(new CryptoPP::StringSink(this->hashed_string));
    hex_encoder.Put(this->hashed_message_bytes, sizeof(this->hashed_message_bytes));
    hex_encoder.MessageEnd();

    return this->hashed_string;
}

/**
 * @brief This nulls out the array containing the hashed message bytes
 */
void SHA3_512::null_array() {
    for(int i = 0; i < sizeof(this->hashed_message_bytes) / sizeof(CryptoPP::SHA3_512::DIGESTSIZE); i++){
        this->hashed_message_bytes[i] = 0;
    }
}


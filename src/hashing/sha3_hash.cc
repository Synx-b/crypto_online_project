/*
 * File: sha3_hash.cc
 * Created: 20/12/2017 22:07
 * Finished:
 *
 * Description:
 *
 * Author: Jacob Powell
 */


#include "sha3_hash.h"

#include <iostream>

sha3_512_hash::sha3_512_hash() = default;

std::string sha3_512_hash::compute_hash(const std::string message) {
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

void sha3_512_hash::null_array() {
    for(int i = 0; i < sizeof(this->hashed_message_bytes) / sizeof(CryptoPP::SHA3_512::DIGESTSIZE); i++){
        this->hashed_message_bytes[i] = 0;
    }
}



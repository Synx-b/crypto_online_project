/*
 * File: sha3_hash.h
 * Created: 20/12/2017 22:07
 * Finished:
 *
 * Description:
 *
 * Author: Jacob Powell
 */

#ifndef CRYPTO_ONLINE_PROJECT_SHA3_HASH_H
#define CRYPTO_ONLINE_PROJECT_SHA3_HASH_H

#include <sha3.h>
#include <hex.h>

#include <string>

class sha3_512_hash {
public:
    explicit sha3_512_hash();
    std::string compute_hash(std::string message);

private:

    void null_array();

    std::string message;
    std::string hashed_string;

    CryptoPP::byte hashed_message_bytes[CryptoPP::SHA3_512::DIGESTSIZE];
    CryptoPP::SHA3_512 SHA3;
    CryptoPP::HexEncoder hex_encoder;
};


#endif //CRYPTO_ONLINE_PROJECT_SHA3_HASH_H

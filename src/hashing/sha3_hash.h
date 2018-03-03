/**
 * @file sha3_hash.h
 * @date 20/12/2017
 * @version 0.01
 *
 * @brief This file contains the class definition for the sha3-512 hashing function
 *
 * @author Jacob Powell
 */

#ifndef CRYPTO_ONLINE_PROJECT_SHA3_HASH_H
#define CRYPTO_ONLINE_PROJECT_SHA3_HASH_H

#include <sha3.h>
#include <hex.h>

#include <string>

/**
 * @class SHA3_512
 *
 * @brief This class implements the SHA3 512-bit hash function provided in the Crypto++ library
 */
class SHA3_512 {
public:
    explicit SHA3_512(); /**< Default Constructor for the SHA3_512 Class*/
    std::string compute_hash(std::string message);/**< Public function that hashes a given message*/

private:
    void null_array(); /**< This nulls the byte array containing the hashed message*/

    std::string message; /**< This holds the message that needs to be hashed */
    std::string hashed_string; /**< This holds the SHA3_512 hash of the message */

    CryptoPP::byte hashed_message_bytes[CryptoPP::SHA3_512::DIGESTSIZE]; /**< This Contains in bytes the hashed message */
    CryptoPP::SHA3_512 SHA3; /**< This is an instance of the SHA3_512 class provided by the Crypto++ Library*/
    CryptoPP::HexEncoder hex_encoder; /**< This is an instance of thr HexEncoder class provided by the Crypto++ Library */
};


#endif //CRYPTO_ONLINE_PROJECT_SHA3_HASH_H

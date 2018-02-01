/*
 * File: aes_implementation.h
 * Created: 14/01/2018 12:39
 * Finished:
 *
 * Description:
 *
 * Author: Jacob Powell
 */

#ifndef CRYPTO_ONLINE_PROJECT_AES_IMPLEMENTATION_H
#define CRYPTO_ONLINE_PROJECT_AES_IMPLEMENTATION_H

#include <cstdint>

#ifndef CBC
    #define CBC 1
#endif

#ifndef ECB
    #define ECB 1
#endif

#ifndef CTR
    #define CTR 1
#endif

#define AES128 1
#define AES192 0
#define AES256 0

#define AES_BLOCKLEN 16

#if defined(AES128) && (AES128 == 1)
    #define AES_KEYLEN 16
    #define AES_KeyExpansionSize 176
#elif defined(AES192) && (AES192 == 1)
    #define AES_KEYLEN 24
    #define AES_KeyExpansionSize 208
#else
    #define AES_KEYLEN 32
    #define AES_KeyExpansionSize 240
#endif

struct AES {
    uint8_t _roundkey[AES_KeyExpansionSize];
#if (defined(CBC) && (CBC == 1) || defined(CTR) && (CTR == 1))
    uint8_t _iv[AES_BLOCKLEN];
#endif
};

void aes_init(struct AES* aes, const uint8_t* key);
#if defined(CBC) && (CBC == 1)
void aes_init_iv(struct AES* aes, const uint8_t* key, const uint8_t* iv);
void aes_set_iv(struct AES* aes, const uint8_t* iv);
#endif

#if defined(ECB) && (ECB == 1)
void aes_ecb_encrypt(struct AES* aes, const uint8_t* buf);
void aes_ecb_decrypt(struct AES* aes, const uint8_t* buf);
#endif

#if defined(CBC) && (CBC == 1)
void aes_cbc_encrypt_buffer(struct AES* aes, uint8_t* buf, uint32_t length);
void aes_cbc_decrypt_buffer(struct AES* aes, uint8_t* buf, uint32_t length);
#endif

#if defined(CTR) && (CTR == 1)
void aes_ctr_xcrypt(struct AES* aes, uint8_t* buf, uint32_t length);
#endif

#endif //CRYPTO_ONLINE_PROJECT_AES_IMPLEMENTATION_H

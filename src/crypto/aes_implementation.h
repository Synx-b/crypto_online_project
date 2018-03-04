/**
 * @file aes_implementation.h
 * @date 14/01/2018
 *
 * @brief This contains the class definition for my AES Implementation
 *
 * @version 0.01
 * @author Jacob Powell
 */

#include <cstdint>
#include <string>

typedef uint8_t byte; /**< This is a simple typedef that makes my life easier */

/**
 * @enum AESKeyLengths
 *
 * @version 0.01
 * @brief This enum contains the possible key lengths that the AES algorithm can use.
 */
enum AESKeyLengths{
    AES128,
    AES192,
    AES256
};


/**
 * @class AESImplementation
 *
 * @version 0.01
 * @brief This class contains my implementation for the AES encryption algorithm
 */
class AESImplementation {
public:
    /**
     * @brief Setting constructor with no arguments to delete
     */
    AESImplementation() = delete;

    /**
     * @brief Default constructor which sets the encryption 128-bit key to be used
     *
     * @param key The encryption key passed into the algorithm
     */
    explicit AESImplementation(AESKeyLengths keyLength);

    /**
     * @brief This method provides the encryption functionality for the AES algorithm
     *
     * @param input The plaintext that wants to be encrypted
     * @param output The ciphertext that has been encrypted
     * @param key The encryption key
     */
    void encrypt(const byte input[], byte output[], const byte key[]);

private:

    /**
     * @brief This provides the implementation for the KeyExpansion part of the algorithm
     *
     * @param key The original 128-bit key
     * @param expandedKey The expanded key used for the algorithms round
     */
    void KeyExpansion(const byte key[], byte expandedKey[]) const;
    static void KeyExpansionCore(byte roundNumber, const byte keyIn[4], byte keyOut[4]);

    void AddRoundKey(byte state[4][4], byte roundKey[4][4]);
    void SubBytes(byte state[4][4]);
    void ShiftRows(byte state[4][4]);
    void MixColumns(byte state[4][4]);

    void outputState(std::string prefix);
    void outputKeyExpansion(std::string prefix) const;

    byte _state[4][4]; /**< This will hold the current state of the algorithm */
    byte _round_key[4][4]; /**< This will hold the round key */

    byte* expandedKey;

    int _number_of_rounds; /**< This holds the number of rounds the algorithm will use */
    int _block_size; /**< This holds the Block size of the AES Algorithm */
    byte _n; /**< This holds the initial length of key */
    byte _b; /**< This holds the length of the expanded key */

    byte _key_size_decrementer;
    byte _m;

};

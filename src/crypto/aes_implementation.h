/**
 * @file aes_implementation.h
 * @date 14/01/2018
 *
 * @brief This contains the class definition for my AES Implementation
 *
 * @version 0.10
 * @author Jacob Powell
 */

#include <cstdint>
#include <string>

typedef uint8_t byte; /**< This is a simple typedef that makes my life easier */

/**
 * @enum AESKeyLengths
 *
 * @version 1.0
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
 * @version 1.0
 * @brief This class contains my implementation for the AES encryption algorithm
 */
class AESImplementation {
public:
    /**
     * @brief Setting constructor with no arguments to delete
     */
    AESImplementation() = default;

    /**
     * @brief Default constructor which sets the encryption 128-bit key to be used
     *
     * @param key The encryption key passed into the algorithm
     */
    explicit AESImplementation(AESKeyLengths keyLength);

    /**
     * @brief This method provides full encryption functionality of the encryption rounds for AES
     *
     * @param input The full plaintext message
     * @param output The full ciphertext message
     * @param key The encryption key
     * @return A string of the encrypted data
     */
    std::string encrypt(const byte input[], byte output[], const byte key[], const size_t message_length);

    /**
     * @brief This method provides the encryption functionality for a block in the AES Algorithm
     *
     * @param input The plaintext block that wants to be encrypted
     * @param output The ciphertext block that has been encrypted
     * @param key The algorithm key
     */
    void encrypt_block(const byte input[], byte output[], const byte key[]);

    /**
     * @brief This method provides the decryption functionality for a block in the AES Algorithm
     *
     * @param input The encrypted ciphertext block
     * @param output The decrypted plaintext block
     * @param key The algorithm key
     */
    void decrypt_block(const byte input[], byte output[], const byte key[]);

private:

    /**
     * @brief This provides the implementation for the KeyExpansion part of the algorithm
     *
     * @param key The original 128-bit key
     * @param expandedKey The expanded key used for the algorithms round
     */
    void KeyExpansion(const byte key[], byte expandedKey[]) const;

    /**
     * @brief This provides the implementation for the KeyExpansionCore for the Key Expansion
     *
     * @param roundNumber The current round number
     * @param keyIn The 4 byte input
     * @param keyOut The 4 byte output
     */
    static void KeyExpansionCore(byte roundNumber, const byte keyIn[4], byte keyOut[4]);

    /**
     * @brief This XOR's the current state with the rounds subkey
     *
     * @param state The current state
     * @param roundKey The current rounds subkey
     */
    void AddRoundKey(byte state[4][4], byte roundKey[4][4]);

    /**
     * @brief Applies the S-Box to each element of the current state
     *
     * @param state The current state
     */
    void SubBytes(byte state[4][4]);

    /**
     * @brief This shifts the rows of the current state by the appropriate
     *
     * @param state The current state
     */
    void ShiftRows(byte state[4][4]);

    /**
     * @brief This applies the MixColumn transformation to the current state
     *
     * @param state The current state
     */
    void MixColumns(byte state[4][4]);

    void InverseSubBytes(byte state[4][4]);
    void InverseShiftRows(byte state[4][4]);
    void InverseMixColumns(byte state[4][4]);

    /**
     * @brief This method outputs what the contents of the current state are with a prefix describing what section this
     * state has been formed in. The primary use for this method is for debug information.
     *
     * @param prefix This is appended to the start of the current state to show where exactly this is
     * being called from
     */
    void outputState(std::string prefix);

    /**
     * @brief This method outputs the current subkey that will be used for the particular round
     */
    void outputRoundKey();

    byte _state[4][4]; /**< This will hold the current state of the algorithm */
    byte _round_key[4][4]; /**< This will hold the round key */

    int _number_of_rounds; /**< This holds the number of rounds the algorithm will use */
    int _block_size; /**< This holds the Block size of the AES Algorithm */
    int _key_size; /**< The chosen key size of the algorithm */
    byte _n; /**< This holds the initial length of key */
    byte _b; /**< This holds the length of the expanded key */

    byte _m; /**< This is used when working out how the key schedule behaves for certain key lengths */

};

/*
 * File: validation.h
 * Created: 04/01/2018 10:51
 * Finished:
 *
 * Description:
 *
 * Author: Jacob Powell
 */

#ifndef CRYPTO_ONLINE_PROJECT_VALIDATION_H
#define CRYPTO_ONLINE_PROJECT_VALIDATION_H

#include <string>

class validation {
public:
    bool password_complexity_is_good(const std::string& password);
    bool is_valid_email(const std::string& email);

private:

    bool password_contains_lowercase(const std::string& password);
    bool password_contains_uppercase(const std::string& password);
    bool password_contains_special(const std::string& password);
    bool password_contains_numbers(const std::string& password);

    std::string lowercase[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
                                "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
                                "u", "v", "w", "x", "y", "z"};
    std::string uppercase[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
                                "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
                                "U", "V", "W", "X", "Y", "Z"};
    std::string special[34] = {"`", "¬", "!", "\"", "£", "$", "%", "^", "&", "*",
                                "(", ")", "-", "_", "=", "+", "[", "{", "]", "}",
                                ";", ":", "'", "@", "#", "~", ",", "<", ".", ">",
                                "/", "?", "|", "\\"};
    std::string numbers[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
};


#endif //CRYPTO_ONLINE_PROJECT_VALIDATION_H

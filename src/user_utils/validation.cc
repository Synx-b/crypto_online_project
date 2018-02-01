/*
 * File: validation.cc
 * Created: 04/01/2018 10:51
 * Finished:
 *
 * Description:
 *
 * Author: Jacob Powell
 */

#include <iostream>
#include "validation.h"

bool validation::password_complexity_is_good(const std::string& password) {
    if(password.length() < 10){
       return false;
    }else{
        bool number_check = password_contains_numbers(password);
        bool special_check = password_contains_special(password);
        bool lowercase_check = password_contains_lowercase(password);
        bool uppercase_check = password_contains_uppercase(password);
        if(number_check && special_check && (lowercase_check || uppercase_check))
            return true;
    }
}

bool validation::password_contains_lowercase(const std::string &password) {
    int count = 0;
    for(std::string &lowercase_char : this->lowercase){
        if(password.find(lowercase_char) != std::string::npos)
            count++;
    }
    return count > 2;
}

bool validation::password_contains_uppercase(const std::string &password) {
    int count = 0;
    for(std::string &uppercase_char : this->uppercase){
        if(password.find(uppercase_char) != std::string::npos)
            count++;
    }
    return count > 2;

}

bool validation::password_contains_special(const std::string &password) {
    int count = 0;
    for(std::string &special_char : this->special){
        if(password.find(special_char) != std::string::npos)
            count++;
    }
    return count > 3;
}

bool validation::password_contains_numbers(const std::string &password) {
    int count = 0;
    for(std::string &number_char : this->numbers){
        if(password.find(number_char) != std::string::npos)
            count++;
    }
    return count > 3;
}

bool validation::is_valid_email(const std::string &email) {
    if(email.find('.') == std::string::npos)
        return false;
    if(email.find('@') == std::string::npos)
        return false;
    return true;
}

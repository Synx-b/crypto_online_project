/**
 * @file db_roles.h
 * @date 19/12/2017
 *
 * @brief This file contains an enum which holds the possible 'roles' that a user registered to a website could be.
 * By default this value will be assigned to Visitor when the user first comes to the site. When they register then
 * then will become a User and if they need access to the admin stuff then they can get assigned the admin role.
 * For the user to become an admin they can't access it straight from the site, they need to be in contact with
 *
 * @author Jacob Powell
 */

#ifndef CRYPTO_ONLINE_PROJECT_DB_ROLES_H
#define CRYPTO_ONLINE_PROJECT_DB_ROLES_H
/**
 * @enum Role
 *
 * @brief This enum contains the basic roles that a user can be assigned to when joining the website
 */
enum class Role{
    Visitor = 0, /**< The Visitor role, assigned when the user first joins the website */
    User = 1, /**< The User role, assigned when a user on the website registers and creates an account*/
    Admin = 3 /**< The Admin role, only available to people who have been assigned this role by the creator of the site */
};

#endif //CRYPTO_ONLINE_PROJECT_DB_ROLES_H

/**
 * File: db_interface.cc
 * Created: 20/12/2017 19:45
 * Finished:
 *
 * Description:
 * @version 0.01
 * Author: Jacob Powell
 */

#include "db_interface.h"

/**
 * @brief This method gets given an id for a user and then searches through the DbUser table for the user with that id.
 *        If it finds a user with that id then it returns a Wt::Dbo::ptr<DbUser> object containing all the information
 *        on that user. If it does not find the user it does nothing.
 *
 * @param looking_for_id The id of the user we are looking for
 * @return The user in db_user with id == looking for id
 */
Wt::Dbo::ptr<DbUser> db_interface::get_user(std::string looking_for_id) {

    std::cerr << "Getting Information for User with ID(" << looking_for_id << ")" << std::endl;

    Wt::Dbo::Transaction transaction(current_session);

    std::cerr << "Getting all user data from the DbUser table" << std::endl;
    Wt::Dbo::collection< Wt::Dbo::ptr<DbUser> > all_users = current_session.find<DbUser>();

    if(!all_users.empty()){
        std::cerr << "DbUser Table is not Empty" << std::endl;
        for(const Wt::Dbo::ptr<DbUser>& current_user : all_users){
            long long int id = current_user.id();
            std::cout << "Identity: " << id << std::endl;
            if(std::to_string(id) == looking_for_id)
                return current_user;
        }
    }
}

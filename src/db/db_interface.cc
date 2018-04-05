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


Wt::Dbo::ptr<DbUser> db_interface::get_user(std::string looking_for_id) {
    Wt::Dbo::Transaction transaction(current_session);

    Wt::Dbo::collection< Wt::Dbo::ptr<DbUser> > all_users = current_session.find<DbUser>();

    for(const Wt::Dbo::ptr<DbUser>& current_user : all_users){
        long long int id = current_user.id();
        std::cout << "Identity: " << id << std::endl;
        if(std::to_string(id) == looking_for_id)
            return current_user;
    }

}

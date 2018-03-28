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

#include <Wt/Dbo/backend/Sqlite3.h>


db_interface::db_interface(Session &session) : current_session(session) {

}

void db_interface::connect_database() {

}

void db_interface::create_tables() {
    try{
        this->current_session.createTables();
    }catch(Wt::Dbo::Exception& e){
        std::cerr << "Tables Already Exist" << std::endl;
    }
}

void db_interface::add_user(const std::string name, const std::string passwordHash, const std::string email,
                                const Role role) {
    Wt::Dbo::Transaction transaction(this->current_session);

}

bool db_interface::check_user_pass(std::string username, std::string passwordHash) {

    Wt::Dbo::Transaction transaction(this->current_session);
    try{
        Wt::Dbo::ptr<DbUser> user = this->current_session.find<DbUser>().where("username = ?").bind(username);


    }catch(Wt::Dbo::Exception& exception){
        std::cout << "etryyuhiopx9zyhtgrfqawxtry67" << std::endl;
    }

}

bool db_interface::check_user_does_not_exist(const std::string &username) {

    Wt::Dbo::Transaction transaction(this->current_session);

    Wt::Dbo::ptr<DbUser> user = this->current_session.find<DbUser>().where("username = ?").bind(username);
    Wt::Dbo::ptr<DbUser> empty_account;

    if(user == empty_account){
        return true;
    }else{
        return false;
    }


}

int db_interface::get_user_id(const std::string &username) {
    Wt::Dbo::Transaction transaction(this->current_session);

    Wt::Dbo::ptr<DbUser> user = this->current_session.find<DbUser>().where("username = ?").bind(username);

    return static_cast<int>(user.id());

}

Wt::Dbo::ptr<DbUser> db_interface::get_user_details(const int& id) {
    Wt::Dbo::Transaction transaction(this->current_session);

    Wt::Dbo::ptr<DbUser> user = this->current_session.find<DbUser>().where("id = ?").bind(id);

    return user;
}

void db_interface::link_user_auth_account() {
    Wt::Dbo::Transaction transaction(this->current_session);

    Wt::Dbo::ptr<AuthInfo> user_auth_id = this->current_session.find<AuthInfo>().where("id = ?").bind(this->current_session.user());
    
}





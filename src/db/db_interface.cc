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
#include "db_user.h"

#include <Wt/Dbo/backend/Sqlite3.h>


void db_interface::connect_database() {
    std::unique_ptr<Wt::Dbo::backend::Sqlite3> sqlite3{new Wt::Dbo::backend::Sqlite3("database.db")};
    sqlite3->setProperty("show-queries", "true");
    this->session.setConnection(std::move(sqlite3));
    this->session.mapClass<db_user>("user");
    this->create_tables();
}

void db_interface::create_tables() {
    try{
        this->session.createTables();
    }catch(Wt::Dbo::Exception& e){
        std::cerr << "Tables Already Exist" << std::endl;
    }
}

void db_interface::add_user(const std::string name, const std::string passwordHash, const std::string email,
                                const Role role) {
    Wt::Dbo::Transaction transaction(this->session);




}

bool db_interface::check_user_pass(std::string username, std::string passwordHash) {

    Wt::Dbo::Transaction transaction(this->session);
    try{
        Wt::Dbo::ptr<db_user> user = this->session.find<db_user>().where("username = ?").bind(username);


    }catch(Wt::Dbo::Exception& exception){
        std::cout << "etryyuhiopx9zyhtgrfqawxtry67" << std::endl;
    }

}

bool db_interface::check_user_does_not_exist(const std::string &username) {

    Wt::Dbo::Transaction transaction(this->session);

    Wt::Dbo::ptr<db_user> user = this->session.find<db_user>().where("username = ?").bind(username);
    Wt::Dbo::ptr<db_user> empty_account;

    if(user == empty_account){
        return true;
    }else{
        return false;
    }


}

int db_interface::get_user_id(const std::string &username) {
    Wt::Dbo::Transaction transaction(this->session);

    Wt::Dbo::ptr<db_user> user = this->session.find<db_user>().where("username = ?").bind(username);

    return static_cast<int>(user.id());

}

Wt::Dbo::ptr<db_user> db_interface::get_user_details(const int& id) {
    Wt::Dbo::Transaction transaction(this->session);

    Wt::Dbo::ptr<db_user> user = this->session.find<db_user>().where("id = ?").bind(id);

    return user;
}



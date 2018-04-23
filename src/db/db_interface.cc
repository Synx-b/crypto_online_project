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

/**
 * @brief When a user answers a question it stores their answer in the database
 */
void db_interface::add_answer_to_user(const std::string &answer, const int question_id) {

    Wt::Dbo::Transaction transaction(current_session);

    const Wt::Auth::User& u = current_session.login().user();
    auto current_user = this->get_user(u.id());

    std::cout << question_id << std::endl;

    if(!this->does_answer_exist_user(question_id)){
        std::cout << "Adding Question for the first time" << std::endl;
        std::cout << question_id << std::endl;
        std::unique_ptr<DbUserAnsweredQuestion> question_answer_1{new DbUserAnsweredQuestion()};
        question_answer_1->question_id = question_id;
        question_answer_1->answer_text = answer;
        question_answer_1->user = current_user;
        Wt::Dbo::ptr<DbUserAnsweredQuestion> userPtr = current_session.add(std::move(question_answer_1));
    }else{
        auto question = this->get_answer(question_id);
        question.modify()->answer_text = answer;
    }

}

/**
 * @brief This method searches through the questions a user has saved and determines whether or not
 *        they have already answered said question.
 *
 * @param answer_id The id of the answer we are looking for
 * @return True if the user has answered that question, False if the user has not.
 */
bool db_interface::does_answer_exist_user(const int &answer_id) {
    Wt::Dbo::Transaction transaction(current_session);

    const std::string &current_user_id = this->current_session.login().user().id();
    auto current_user = this->get_user(current_user_id);

    if(current_user->questions.empty()){
        return false;
    }else{
        for(const Wt::Dbo::ptr<DbUserAnsweredQuestion>& question : current_user->questions){
            std::cout << question->question_id << std::endl;
            if(question->question_id == answer_id)
                return true;
        }
        std::cout << "Question already exits" << std::endl;
        return false;
    }

}

/**
 * @brief This method searches through the questions the user has answered and then returns an object
 *        containing the data on the question we are searching for.
 *
 * @param answer_id The answer_id of the question we are looking for
 * @return An object containing the information on the question begin searched for
 */
Wt::Dbo::ptr<DbUserAnsweredQuestion> db_interface::get_answer(const int &answer_id){
    std::cout << "GET ANSWER CALLED" << std::endl;
    Wt::Dbo::Transaction transaction(current_session);

    const std::string &current_user_id = this->current_session.login().user().id();

    return this->current_session.find<DbUserAnsweredQuestion>().where("user_answered_question_id = ?").bind(answer_id)
            .where("user_id = ?").bind(current_user_id);
}

/**
 * @brief This method gets an answer and a question and then checks to see if the users answer is right
 *
 * @param answer The user answer
 * @param question_id The id of the question being answered
 * @return Whether or not the question is right
 */
bool db_interface::check_answer(const std::string &answer, int question_id) {
    std::cout << "CHECK ANSWER CALLED" << std::endl;
    Wt::Dbo::Transaction transaction(current_session);

    const std::string& current_user_id = this->current_session.login().user().id();

    std::cout << "Getting User Answered Questions" << std::endl;
    Wt::Dbo::ptr<DbUserAnsweredQuestion> user_answer = this->current_session.find<DbUserAnsweredQuestion>()
            .where("user_answered_question_id = ?").bind(question_id)
            .where("user_id = ?").bind(current_user_id);

    std::cout << "Getting  Questions" << std::endl;
    Wt::Dbo::ptr<DbQuestions> question = this->current_session.find<DbQuestions>()
            .where("question_id = ?").bind(question_id);
    std::cout << "Got Questions" << std::endl;

    return (user_answer->answer_text == question->question_answer);
}

/**
 * @brief This method works out how many questions the user has answered
 * @return THe number of questions the user has attempted
 */
int db_interface::get_total_questions_answered() {
    Wt::Dbo::Transaction transaction(current_session);

    int number_of_questions = 0;

    auto current_user_id = this->current_session.login().user().id();
    auto current_user = this->get_user(current_user_id);

    for(const Wt::Dbo::ptr<DbUserAnsweredQuestion> question : current_user->questions){
        number_of_questions++;
    }

    return number_of_questions;
}

/**
 * This method works out how many of the quesitons the user has answered correctly
 * @return The number of correctly answered questions
 */
int db_interface::get_total_correct_question_answered() {
    Wt::Dbo::Transaction transaction(current_session);

    int number_of_correct_questions = 0;

    auto current_user_id = this->current_session.login().user().id();
    auto current_user = this->get_user(current_user_id);

    for(const Wt::Dbo::ptr<DbUserAnsweredQuestion> question : current_user->questions){
        if(question->is_correct)
            number_of_correct_questions++;
    }
    return number_of_correct_questions;
}

/**
 * @brief This method sets the is_correct flag in the user_answered_question table so I can easily work out whether or
 * not the user got the question correct
 */
void db_interface::set_answer_check_flag(int question_id, bool check) {
    Wt::Dbo::Transaction transaction(current_session);

    auto question = this->get_answer(question_id);
    question.modify()->is_correct = check;
}





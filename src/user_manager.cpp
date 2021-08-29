#include "user_manager.hpp"

bool UserManager::create_user(const std::string& user_id, const std::string& password){
    if(users_table.find(user_id) == users_table.end()){
        users_table.insert(std::pair<std::string, User>(user_id, User(user_id, password)));
        return true;
    }
    return false;
}

bool UserManager::remove_user(const std::string& user_id){
    if(users_table.find(user_id) != users_table.end()){
        users_table.erase(user_id);
        return true;
    }
    return false;
}

const std::unordered_map<std::string, User>& UserManager::get_users(){
    return users_table;
}

bool UserManager::authenticate_user(const std::string& user_id, const std::string& password){
    std::unordered_map<std::string, User>::iterator it = users_table.find(user_id);

    if(it != users_table.end()){
        if((it->second).get_password() != password)
            return false;
        return true;
    }
    return false;
}

std::vector<std::string> UserManager::get_all_users(){
    std::vector<std::string> users;
    for(auto entry: users_table){
        if(entry.first != "admin")
            users.emplace_back(entry.first);
    }
    return users;
}
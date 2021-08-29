#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include<string>
#include<unordered_map>
#include<vector>
#include "user.hpp"


class UserManager{
    std::unordered_map<std::string, User> users_table;  
public:
    bool create_user(const std::string& user_id, const std::string& password);
    bool remove_user(const std::string& user_id);
    const std::unordered_map<std::string, User>& get_users();
    bool authenticate_user(const std::string& user_id, const std::string& password);
    std::vector<std::string> get_all_users();
};
#endif
#include "user_roles_manager.hpp"

void UserRolesManager::assign_user_role(std::string user_id, std::string role_id){
    std::unordered_map<std::string, std::unordered_set<std::string> >::iterator it = users_roles_table.find(user_id);  
    if(it != users_roles_table.end()){
        (it->second).insert(role_id);
    }
    else{
        users_roles_table[user_id] = {role_id};
    }
}

bool UserRolesManager::remove_user_role(std::string user_id, std::string role_id){
    std::unordered_map<std::string, std::unordered_set<std::string> >::iterator it = users_roles_table.find(user_id);
    if(it != users_roles_table.end()){
        return (it->second).erase(role_id) == 1 ? true : false;
    }
    return false;
}

std::vector<std::string> UserRolesManager::get_user_roles(std::string user_id){
    std::unordered_map<std::string, std::unordered_set<std::string> >::iterator it = users_roles_table.find(user_id);
    if(it != users_roles_table.end()){
        std::vector<std::string> list_of_roles((it->second).begin(), (it->second).end());
        return list_of_roles; 
    }
    return std::vector<std::string>();
}
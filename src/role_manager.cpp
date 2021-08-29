#include "role_manager.hpp"

bool RoleManager::create_role(std::string role_id){
    if(roles_table.find(role_id) == roles_table.end()){
        roles_table.insert(std::pair<std::string, Role>(role_id, Role(role_id)));
        return true;
    }
    return false;
}

bool RoleManager::remove_role(std::string role_id){
    if(roles_table.find(role_id) != roles_table.end()){
        roles_table.erase(role_id);
        return true;
    }
    return false;
}

bool RoleManager::update_role(std::string role_id, std::string resource_id, ACTIONS_TYPE action_type, 
OPERATION operation){
    std::unordered_map<std::string, Role>::iterator it = roles_table.find(role_id);
    bool result = false;
    if(it != roles_table.end()) {
        Permission permission(resource_id, action_type);
        switch(operation){
            case OPERATION::ADD:
                it->second.add_permission(permission);
                result = true;
                break;
            case OPERATION::REMOVE:
                result = it->second.remove_permission(permission);
                break;
            case OPERATION::INVALID_OPERATION:
                break;
        }
    }
    return result;
}

bool RoleManager::check_permission(std::string role_id, std::string resource_id, ACTIONS_TYPE action_type){
    std::unordered_map<std::string, Role>::iterator it = roles_table.find(role_id);
    if(it != roles_table.end()){
        Permission permission(resource_id, action_type);
        return (it->second).validate_permission(permission);
    }
    return false;
}

std::string RoleManager::get_role_description(std::string role_id){
    std::unordered_map<std::string, Role>::iterator it = roles_table.find(role_id);
    if(it != roles_table.end()){
        return (it->second).to_string();
    }
    return role_id + " does not exist\n";
}

std::vector<std::string> RoleManager::get_all_roles(){
    std::vector<std::string> roles;
    for(auto entry:roles_table){
        roles.emplace_back(entry.second.get_role_id());
    }
    return roles;
}
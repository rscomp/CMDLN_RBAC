#ifndef ROLE_MANAGER_H
#define ROLE_MANAGER_H

#include<unordered_map>
#include<string>
#include<vector>
#include "role.hpp"
#include "user.hpp"
#include "action_type.hpp"
#include "permission.hpp"


enum OPERATION{
    ADD,
    REMOVE,
    INVALID_OPERATION
};

class RoleManager{
    std::unordered_map<std::string, Role> roles_table;
public:
    bool create_role(std::string role_id);
    bool remove_role(std::string role_id);
    bool update_role(std::string role_id, std::string resource_id, ACTIONS_TYPE action_type, OPERATION operation);
    bool check_permission(std::string role_id, std::string resource_id, ACTIONS_TYPE action_type);
    std::string get_role_description(std::string role_id);
    std::vector<std::string> get_all_roles();
};
#endif
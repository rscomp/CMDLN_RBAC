#ifndef USER_ROLES_MANAGER_H
#define USER_ROLES_MANAGER_H

#include<string>
#include<unordered_set>
#include<unordered_map>
#include<vector>

class UserRolesManager{
    std::unordered_map<std::string, std::unordered_set<std::string> > users_roles_table;
public:
    void assign_user_role(std::string user_id, std::string role_id);
    bool remove_user_role(std::string user_id, std::string role_id);
    std::vector<std::string> get_user_roles(std::string user_id);
};
#endif
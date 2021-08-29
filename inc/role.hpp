#ifndef ROLE_H
#define ROLE_H

#include<unordered_set>
#include<string>
#include<utility>
#include "permission.hpp"
using namespace std;

class Role {
    string role_id;
    unordered_set<Permission, PermissionHash> permission_set;

public:
    Role(){}
    Role(string role_id):role_id(role_id){}
    ~Role(){}

    void add_permission(const Permission& permission);
    bool remove_permission(const Permission& permission);
    bool validate_permission(const Permission& permission);
    std::string to_string();
    std::string get_role_id();
};
#endif
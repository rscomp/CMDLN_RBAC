#include "role.hpp"

void Role::add_permission(const Permission& permission){
    permission_set.insert(permission);
}

bool Role::remove_permission(const Permission& permission){
    return permission_set.erase(permission) == 1 ? true : false;
}

bool Role::validate_permission(const Permission& permission){
    if(permission_set.find(permission) != permission_set.end())
        return true;
    return false;
}

std::string Role::to_string(){
    std::string description;
    description.append("Role id: " + role_id + "\n");
    for(Permission permission: permission_set){
        description.append("resource id: " + permission.get_resource_id());
        description.append(", action_type: " + action_type_string(permission.get_action_type())+ "\n");
    }
    return description;
}

std::string Role::get_role_id(){
    return role_id;
}
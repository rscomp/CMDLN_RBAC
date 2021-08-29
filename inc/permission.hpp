#ifndef PERMISSION_H
#define PERMISSION_H

#include<string>
#include "action_type.hpp"

class Permission{
    std::string resource_id;
    ACTIONS_TYPE action_type;
public:
    Permission(){};
    Permission(std::string& resource_id, ACTIONS_TYPE action_type): resource_id(resource_id), action_type(action_type){};
    ~Permission(){};

    std::string get_resource_id() const;
    ACTIONS_TYPE get_action_type() const;

    bool operator==(const Permission& x) const;
};

class PermissionHash {
public:
    size_t operator()(const Permission& permission)const;
};

#endif
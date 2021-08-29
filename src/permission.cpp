#include "permission.hpp"

bool Permission::operator==(const Permission& permission) const{
    return this->resource_id == permission.resource_id && this->action_type == permission.action_type;
}

std::string Permission::get_resource_id() const{
    return this->resource_id;
}

ACTIONS_TYPE Permission::get_action_type() const{
    return this->action_type;
}

size_t PermissionHash::operator()(const Permission& permission) const{
    return ((std::hash<std::string>()(permission.get_resource_id()) ^ (std::hash<int>()(permission.get_action_type()) << 1)) >> 1);
}
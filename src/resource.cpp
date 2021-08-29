#include "resource.hpp"

bool Resource::operator==(const Resource& resource) const{
    return this->resource_id == resource.resource_id;
}

std::string Resource::get_resource_id() const{
    return this->resource_id;
}

size_t ResourceHash::operator()(const Resource& resource) const{
    return (std::hash<std::string>()(resource.get_resource_id()));
}
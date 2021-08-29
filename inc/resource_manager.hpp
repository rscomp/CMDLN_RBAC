#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H
#include<unordered_set>
#include<string>
#include<vector>
#include "resource.hpp"

class ResourceManager{
    std::unordered_set<Resource, ResourceHash> resource_table;
public:
    void create_resource(std::string resource_id);
    std::vector<std::string> get_all_resources();
    bool access_resource();
};
#endif
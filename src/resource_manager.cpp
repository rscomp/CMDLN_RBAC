#include "resource_manager.hpp"

void ResourceManager::create_resource(std::string resource_id){
    resource_table.insert(Resource(resource_id));
}

std::vector<std::string> ResourceManager::get_all_resources(){
    std::vector<std::string> resources;
    for(Resource resource: resource_table){
        resources.emplace_back(resource.get_resource_id());
    }
    return resources;
}
#ifndef RESOURCE_H
#define RESOURCE_H

#include<string>

class Resource {
    std::string resource_id;
public:
    Resource(){}
    Resource(std::string resource_id):resource_id(resource_id){}
    ~Resource(){}

    std::string get_resource_id() const;

    bool operator==(const Resource& x) const;
};

class ResourceHash {
public:
    size_t operator()(const Resource& resource)const;
};
#endif
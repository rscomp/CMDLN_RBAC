#include "action_type.hpp"

static const char *action_type_str[] = {
    "Create",
    "Read",
    "Update",
    "Delete"
};

std::string action_type_string(int enum_val){
    std::string conversion(action_type_str[enum_val]);
    return conversion;
}
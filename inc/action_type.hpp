#ifndef ACTION_TYPE_H
#define ACTION_TYPE_H

#include<string>

enum ACTIONS_TYPE{
    CREATE,
    READ,
    UPDATE,
    DELETE,
    INVALID_ACTION
};

extern std::string action_type_string(int enum_val);

#endif
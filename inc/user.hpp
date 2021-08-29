#ifndef USER_H
#define USER_H

#include<string>

class User {
    std::string user_id;
    std::string password;

public:
    User(){}
    User(std::string user_id, std::string password):user_id(user_id), password(password){}
    ~User(){}
    std::string& get_password();
};
#endif

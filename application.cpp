#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

#include "user_manager.hpp"
#include "role_manager.hpp"
#include "action_type.hpp"
#include "resource_manager.hpp"
#include "user_roles_manager.hpp"

using namespace std;

class Application {
    string INVALID;
    string admin_user;
    UserManager users_manager;
    RoleManager roles_manager;
    ResourceManager resource_manager;
    UserRolesManager user_roles_manager;

    string current_user;

    void panel_header(){
        cout<<"================================================"<<endl;
        cout<<"hi! you are logged in as "<<current_user<<endl;
        cout<<"enter 1 for login as another user"<<endl;
    }

    void panel_footer(){
        cout<<"enter 100 to exit from application"<<endl;
    }

    void user_login(){
        string user_id;
        string password;
        cout<<"++++++++ Login ++++++++"<<endl;
        cout<<"User ID: ";
        cin>>user_id;
        cout<<"Password: ";
        cin>>password;

        bool successful = users_manager.authenticate_user(user_id, password);
        if(successful) {
            cout<<"login successfull"<<endl;
            current_user = user_id;
        }
        else {
            cout<<"login un-successfull"<<endl;
        }
        cout<<"++++++++++++++++++++++++"<<endl;
    }

    string select_resource(){
        cout<<"++++++++ Select resource from list ++++++++"<<endl;
        vector<string> resources = resource_manager.get_all_resources();
        int resource_id = 1;
        for(string resource: resources){
            cout<<resource_id<<". "<<resource<<endl;
            resource_id += 1;
        }
        cin>>resource_id;
        cout<<"++++++++++++++++++++++++"<<endl;
        if(resource_id > 0 && resource_id > resources.size())
            return INVALID;
        return resources[resource_id-1];
    }
    
    ACTIONS_TYPE select_action_type(){
        cout<<"++++++++ Select access from list ++++++++"<<endl;
        ACTIONS_TYPE action_type;
        int selected_access_type;
        cout<<"1. READ\n2. UPDATE\n3. DELETE"<<endl;
        cin>>selected_access_type;
        switch(selected_access_type){
            case 1:
                action_type = ACTIONS_TYPE::READ;
                break;
            case 2:
                action_type = ACTIONS_TYPE::UPDATE;
                break;
            case 3:
                action_type = ACTIONS_TYPE::DELETE;
                break;
            default:
                action_type = ACTIONS_TYPE::INVALID_ACTION;
        }
        cout<<"++++++++++++++++++++++++"<<endl;
        return action_type;
    }    
    
    // Super Admin section
    void create_user(){
        string user_id;
        string password;
        cout<<"++++++++ Signup ++++++++"<<endl;
        cout<<"User ID: ";
        cin>>user_id;
        cout<<"Password: ";
        cin>>password;

        bool successful = users_manager.create_user(user_id, password);

        if(successful) {
            cout<<user_id<<" is successfully created"<<endl;
        }else{
            cout<<user_id<<" already exist in the system"<<endl;
        }
        cout<<"++++++++++++++++++++++++"<<endl;
    }

    string select_user(){
        cout<<"++++++++++++++ Select user from the list ++++++++++++++"<<endl;
        int user_index = 1;
        vector<string> users = users_manager.get_all_users();
        for(string user: users){
            cout<<user_index<<". "<<user<<endl;
            user_index += 1;
        }
        cin>>user_index;
        cout<<"++++++++++++++++++++++++++++"<<endl;
        if(user_index > 0 && user_index > users.size())
            return INVALID;
        return users[user_index-1];
    }

    string select_role(){
        cout<<"++++++++++++++ Select role from the list ++++++++++++++"<<endl;
        int role_index = 1;
        vector<string> roles = roles_manager.get_all_roles();
        for(string role: roles){
            cout<<role_index<<". "<<role<<endl;
            role_index += 1;
        }
        cin>>role_index;
        cout<<"++++++++++++++++++++++++++++"<<endl;
        if(role_index > 0 && role_index > roles.size())
            return INVALID;
        return roles[role_index-1];
    }

    OPERATION select_operation(){
        OPERATION operation;
        int operation_id;
        cout<<"++++++++ Select operation to be performed ++++++++"<<endl;
        cout<<"1. ADD\n2. REMOVE"<<endl;
        cin>>operation_id;
        switch(operation_id){
            case 1:
                operation = OPERATION::ADD;
                break;
            case 2:
                operation = OPERATION::REMOVE;
                break;
            default:
                operation = OPERATION::INVALID_OPERATION;
        }
        cout<<"++++++++++++++++++++++++++++++++"<<endl;
        return operation;
    }

    void edit_role(){
        cout<<"++++++++++++ EDIT ROLE START +++++++++++"<<endl;
        string role = select_role();
        if(role != INVALID){
            OPERATION selected_operation = select_operation();
            if(selected_operation != OPERATION::INVALID_OPERATION){
                string selected_resource = select_resource();
                if(selected_resource != INVALID){
                    ACTIONS_TYPE selected_action_type = select_action_type();
                    if(selected_action_type != ACTIONS_TYPE::INVALID_ACTION){
                        if(roles_manager.update_role(role, selected_resource, selected_action_type, selected_operation))
                            cout<<"Permissions updated for role "<<role<<endl;
                        else
                            cout<<"Failed to update permission"<<endl;
                    }
                    else{
                        cout<<"Invalid Input"<<endl;
                    }
                }
                else{
                    cout<<"Invalid Input"<<endl;
                }
            }
            else{
                cout<<"Invalid Input"<<endl;
            }
        }
        else{
            cout<<"Invalid Input"<<endl;
        }
        cout<<"++++++++++++ EDIT ROLE END +++++++++++"<<endl;
    }

    void update_user_roles(){
        cout<<"++++++++++++ UPDATE USER ROLES START +++++++++++"<<endl;
        string selected_user = select_user();
        if(selected_user != INVALID){
            OPERATION selected_operation = select_operation();
            if(selected_operation != OPERATION::INVALID_OPERATION){
                string selected_role = select_role();
                if(selected_role != INVALID){
                    if(selected_operation == OPERATION::ADD){
                        user_roles_manager.assign_user_role(selected_user, selected_role);
                        cout<<selected_user<<" assigned a new role "<<selected_role<<endl;
                    }
                    else if(selected_operation == OPERATION::REMOVE){
                        bool result = user_roles_manager.remove_user_role(selected_user, selected_role);
                        cout<<selected_user<<"  "<<selected_role<<" remove result "<<result<<endl;
                    }
                }
                else{
                    cout<<"Invalid Input"<<endl;
                }
            }
            else{
                cout<<"Invalid Input"<<endl;
            }
        }
        else{
            cout<<"Invalid Input"<<endl;
        }
        cout<<"++++++++++++ UPDATE USER ROLE ROLES END +++++++++++"<<endl;
    }

    void admin_panel(){
        panel_header();
        cout<<"enter 2 for create user"<<endl;
        cout<<"enter 3 for edit role"<<endl;
        cout<<"enter 4 for edit user roles"<<endl;
        panel_footer();
    }

    // Normal User section
    void user_panel(){
        panel_header();
        cout<<"enter 2 to view roles"<<endl;
        cout<<"enter 3 to access resource"<<endl;
        panel_footer();
    }

    void access_resource(){
        string selected_resource = select_resource();

        if(selected_resource == INVALID)
            cout<<"Invalid Input"<<endl;
        else{
            ACTIONS_TYPE selected_action_type = select_action_type();
            
            if(selected_action_type != ACTIONS_TYPE::INVALID_ACTION){
                vector<string> user_roles = user_roles_manager.get_user_roles(current_user);
                for(string role: user_roles){
                    if(roles_manager.check_permission(role, selected_resource, selected_action_type)){
                        cout<<"Access granted"<<endl;
                        return;
                    }
                }
                cout<<"Access denied"<<endl;
            }
            else{
                cout<<"Invalid Input"<<endl;
            }
        }
    }

    void view_user_roles(){
        cout<<"++++++++ "<<current_user<<" roles ++++++++"<<endl;
        vector<string> user_roles = user_roles_manager.get_user_roles(current_user);

        for(string role: user_roles){
            cout<<roles_manager.get_role_description(role);
            cout<<"------------------------"<<endl;
        }
        cout<<"++++++++++++++++++++++++"<<endl;
    }

    // Init Section
    void create_default_users(){
        users_manager.create_user(admin_user, admin_user);
        users_manager.create_user(string("User1"), string("User1"));
        current_user = admin_user;
    }

    void create_default_resources(){
        resource_manager.create_resource(string("resource1"));
        resource_manager.create_resource(string("resource2"));
        resource_manager.create_resource(string("resource3"));
        resource_manager.create_resource(string("resource4"));
    }

    void create_default_roles(){
        roles_manager.create_role(string("role1"));
        roles_manager.update_role(string("role1"), string("resource1"), ACTIONS_TYPE::READ, OPERATION::ADD);
        roles_manager.update_role(string("role1"), string("resource2"), ACTIONS_TYPE::UPDATE, OPERATION::ADD);
        roles_manager.update_role(string("role1"), string("resource3"), ACTIONS_TYPE::DELETE, OPERATION::ADD);
        roles_manager.update_role(string("role1"), string("resource4"), ACTIONS_TYPE::READ, OPERATION::ADD);
        roles_manager.update_role(string("role1"), string("resource4"), ACTIONS_TYPE::DELETE, OPERATION::ADD);

        roles_manager.create_role(string("role2"));
        roles_manager.update_role(string("role2"), string("resource1"), ACTIONS_TYPE::DELETE, OPERATION::ADD);
        roles_manager.update_role(string("role2"), string("resource2"), ACTIONS_TYPE::READ, OPERATION::ADD);
        roles_manager.update_role(string("role2"), string("resource3"), ACTIONS_TYPE::UPDATE, OPERATION::ADD);
        roles_manager.update_role(string("role2"), string("resource4"), ACTIONS_TYPE::UPDATE, OPERATION::ADD);
        roles_manager.update_role(string("role2"), string("resource4"), ACTIONS_TYPE::DELETE, OPERATION::ADD);

        roles_manager.create_role(string("role3"));
        roles_manager.update_role(string("role3"), string("resource1"), ACTIONS_TYPE::UPDATE, OPERATION::ADD);
        roles_manager.update_role(string("role3"), string("resource2"), ACTIONS_TYPE::DELETE, OPERATION::ADD);
    }

    void assign_default_roles(){
        user_roles_manager.assign_user_role("User1", "role1");
        user_roles_manager.assign_user_role("User1", "role3");
    }
public:
    void init(){
        this->INVALID = "INVALID";
        this->admin_user = "admin";
        create_default_users();
        create_default_resources();
        create_default_roles();
        assign_default_roles();
    }

    void run(){
        int option;
        while(true) {
            if(option == 100){
                cout<<"Thanks for using this application"<<endl;
                break;
            }
            if(current_user == admin_user){
                admin_panel();
                cin>>option;
                switch(option){
                    case 2:
                        create_user();
                        break;
                    case 3:
                        edit_role();
                        break;
                    case 4:
                        update_user_roles();
                        break;
                }
            }
            else{
                user_panel();
                cin>>option;
                switch(option){
                    case 2:
                        view_user_roles();
                        break;
                    case 3:
                        access_resource();
                        break;
                }
            }
            if(option == 1){
                user_login();
            }
        }
    }
};

int main(){
    Application my_app;
    my_app.init();
    my_app.run();
    return 0;
}


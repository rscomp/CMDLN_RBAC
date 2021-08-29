This is command line RBAC system with following functionality
SUPER_ADMIN
1. Create User
2. Switch Current User
3. Add/Remove permissions to a role
4. Assign/Remove role to/from User
NORMAL_USER
1. Switch Current User
2. View role descriptions for roles assigned to Current User
3. Access Resource as a Current User

Prerequisite
1. C++14 compiler
2. make utility

Makefile is included in the project for compilation and linking of the project.
Steps to run:
1. access root folder of the project from command line
2. $ make (it will pickup Makefile automatically and compile the project)
3. $ make run (for running the application)
4. user menu is self explanatory to move forward and test application
5. make clean (for clearing the output files from compilation)

Init System
System init with below default data
1. Resources (resource1, resource2, resource3, resource4)
2. Roles(role1, role2, role3)
3. Admin User(admin, admin) and Normal User(User1, User1)

The classes are defined with minimal data members as per requirement. It can be further extended without much effort.
Composition is favoured over Inheritence in this project.



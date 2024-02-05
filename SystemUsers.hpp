#include<iostream>
#include<vector>
#include"Users.hpp"


class SystemUsers{  // Singleton Design Pattern 

private:

    std::vector< Customer* > customers ;
    std::vector< Admin* > Admins ;
    static SystemUsers* system_users_obj ; 
    SystemUsers(){}
    std::pair <std::string,std::string> takeUserAndPassword() ;

public:

    static SystemUsers* get_instance();
    static void freeInstance() ;
    Customer* signUp() ;
    Customer* customerLogIn() ;
    Admin* adminLogIn() ;
    void loadAdmins() ;
    void freeUsers() ;
    void printAdmins() ;
    void addAdmin(Admin*) ;

};
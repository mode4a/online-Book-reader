#ifndef SYS 
#define SYS 


#include"SystemBooks.hpp"
#include"SystemUsers.hpp"

class RunSystem{
private : 

    int takeChoice() const ;
    int selectMode() const;
    int logInOrSignUp() const;
    int printAdminMenu() const;
    int printCustomerMenu() const ;
    void startAdminMenu(Admin*) const ;
    void startCustomerMenu( Customer* ) const ;

public:
    void startProgram() ;
};


#endif
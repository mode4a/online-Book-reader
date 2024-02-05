#ifndef USERS
#define USERS

#include<iostream>
#include<vector>
#include"Session.hpp"


class User{

protected:    
    std::string name ;
    std::string user_name ;
    std::string email ;
    std::string password ;

public: 
    User() ;
    User( std::string , std::string , std::string , std::string) ;
void printDetails() const ;
void setUser() ;
bool checkUSerAndPassword( std::string , std::string ) const ;
};

class Customer : public User {

private:
    std::vector< Session* > sessions ;

public: 
    void addSession( Session* ) ;
    bool printSessions() const ;
    Session* getSession( int ) const ;
    ~Customer();
};

class Admin : public User {

public :
    Admin() ;
    Admin( std::string , std::string , std::string , std::string) ;
    void addBook() ;
    

};

























#endif
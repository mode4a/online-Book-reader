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
    User( std::string user_name , std::string name , std::string email , std::string password ) ;
void printDetails() const ;
void setUser() ;
bool checkUSerAndPassword( std::string , std::string ) const ;
};

class Customer : public User {

private:
    std::vector< Session* > sessions ;

public: 
    void addSession( Session* session ) ;
    bool printSessions() const ;
    Session* getSession( int idx ) const ;
    ~Customer();
};

class Admin : public User {

public :
    Admin() ;
    Admin( std::string user_name , std::string name , std::string email , std::string password ) ;
    void addBook() ;
    

};

























#endif
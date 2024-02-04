#ifndef USERS
#define USERS

#include<iostream>
#include<vector>
#include"Session.hpp"
#include"System.hpp"


class User{

protected:    
    std::string name ;
    std::string user_name ;
    std::string email ;
    std::string password ;

public: 
void printDetails() const ;

};

class Customer : public User {

private:
    std::vector< Session* > sessions ;

public: 
    void addSession( Session* session ) ;
    void printSessions() const ;
    Session* getSession( int idx ) const ;
    void setCustomer() ;

};

class Admin{

public :
    void addBook() ;
};

























#endif
#ifndef SYS 
#define SYS 

#include<iostream>
#include<vector>
#include"Book.hpp"
#include"Users.hpp"



class SystemBooks{  // Singleton Design Pattern 

private:

    std::vector<Book*> books ;
    static SystemBooks* system_books_obj ; 
    SystemBooks(){}
    void printMenu() const ;
    void printCurrentPage( int idx ) const ;

public:

    void viewBooks() const ;
    int openBook( int , int ) const ;
    void insertBook( Book* ) ;
    static SystemBooks* get_instance();
    static void freeInstance() ;

};



#endif
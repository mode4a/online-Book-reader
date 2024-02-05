#ifndef SESSION
#define SESSION

#include<iostream>
#include"Book.hpp"
class Session{

private:
    int page ;
    const Book* book_ptr ;
    // date
    // time
public:
    
    void setSessionBook( const Book* book_ ) ;
    void setSessionpage( int page_ ) ; 
    void printSession() const ;
    int getPage() const ;
    const Book* getSessionBook() const ;
    
};

#endif
#ifndef BOOK
#define BOOK

#include<iostream>
#include<vector>
class Book{

private:

    std::string title ;
    std::string author_name ;
    std::vector<std::string> pages ;

public:
    Book();
    Book(  std::string , std::string , std::vector<std::string> );
    void setBook() ;
    std::string getPage( int idx ) const ;
    std::string getName() const ;
    int getNumOfPages() const ;

};

class BookPrinter { // iterator design pattern 

private: 

    const Book* book ;
    int current_page ;  // ITERATOR 
    bool checkCurrent() const ;
    bool has_next() const ;
    bool has_previous() const ;
    void printCurrentPage( int ) const ; 

public:

    BookPrinter( const Book*) ;
    void printNext() ;
    void printCurrent() const ;
    void printPrevious();
    void setPage( int idx ) ;
    int getPage() const ;

};

#endif 
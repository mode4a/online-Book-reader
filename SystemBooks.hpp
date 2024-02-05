#ifndef SYSBOOKS
#define SYSBOOKS

#include"Book.hpp"


class SystemBooks{  // Singleton Design Pattern 

private:

    std::vector<Book*> books ;
    static SystemBooks* system_books_obj ; 
    SystemBooks(){}
    // void printCurrentPage( int idx ) const ;

public:

    static SystemBooks* get_instance();
    static void freeInstance() ;
    void viewBooks() const ;
    void insertBook( Book* ) ;
    void freeBooks() ;
    void loadBooks() ;
    const Book* getBook(int) const ;
};

#endif 
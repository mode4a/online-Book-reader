#include"SystemBooks.hpp"

SystemBooks* SystemBooks::system_books_obj = nullptr ;

SystemBooks* SystemBooks::get_instance(){
    if( system_books_obj == nullptr ){
       system_books_obj = new SystemBooks ; 
    }
    return system_books_obj ;
}
void SystemBooks::freeInstance(){
    if( system_books_obj != nullptr ){
        delete system_books_obj ; 
        system_books_obj = nullptr ;
        std::cout << "systembooks obj freed" ;
    }
}

void SystemBooks::insertBook(Book* book_ptr ){
    books.push_back(book_ptr) ;
}
void SystemBooks::viewBooks() const{
    std::cout << "our current collection : \n" ;
    for(int i = 0 ; i < books.size() ; ++i ){
       std::cout<< i+1 << " " << books[i]->getName() << "\n" ; 
    }
}

void SystemBooks::freeBooks(){

    for(int i = 0 ; i < books.size() ; ++i ){
        if( books[i] != nullptr ){
            delete books[i] ;
            books[i] = nullptr ;
            std::cout<< "book " << i+1 << " freed\n" ;
        }
    }

}
void SystemBooks::loadBooks(){
    
    std::vector<std::string> pages1 = {"a", "b" ,"c"} ;
    std::vector<std::string> pages2 = {"d", "e" ,"f"} ;
    std::vector<std::string> pages3 = {"g", "h" ,"j"} ;

    Book* book1 = new Book( "c++" , "mostafa" , pages1 ) ;
    Book* book2 = new Book( "ds" , "abari" , pages2 ) ;
    Book* book3 = new Book( "algo" , "mostafa" , pages3 ) ;

    SystemBooks* system_books = SystemBooks::get_instance() ;
    system_books->books.push_back(book1) ;
    system_books->books.push_back(book2) ;
    system_books->books.push_back(book3) ;

}
const Book* SystemBooks::getBook( int idx ) const {
    return books[idx] ;
}



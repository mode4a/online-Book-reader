#include"System.hpp"

                                    // Systembooks definitions \\ 

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
    }
}
void SystemBooks::printMenu() const {
    std::cout << "menu :\n\
    \t\t1 : Next Page\n\
    \t\t2 : Previous Page\n\
    \t\t3 : Stop reading\n\n\
    Which book to read\n\
    Enter Number in range 1-3\n" ;
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
int SystemBooks::openBook( int idx , int current_page ) const{
    
    BookPrinter book_printer(books[idx]) ;
    book_printer.setPage(current_page) ;
    book_printer.printCurrent() ;
    while( true ){
        printMenu() ;
        int choice ; std::cin >> choice ;
        if( choice == 3 ){
            return book_printer.getPage() ;
        }
        else if( choice == 2 ){
            book_printer.printPrevious();
        }
        else{
            book_printer.printNext();
        }
    }
}

                                    // SystemUsers definitions \\


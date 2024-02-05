#include"Startsessions.hpp"

void StartSessions::printBookMenu(){
    std::cout << "menu :\n\
    \t\t1 : Next Page\n\
    \t\t2 : Previous Page\n\
    \t\t3 : Stop reading\n\n\
    Enter Number in range 1-3\n" ;
}

int StartSessions::openBook( const Book* book , int current_page ){
    
    BookPrinter book_printer(book) ;
    book_printer.setPage(current_page-1) ;
    book_printer.printCurrent() ;
    while( true ){
        printBookMenu() ;
        int choice ; std::cin >> choice ;
        if( choice == 3 ){
            return book_printer.getPage()+1 ;
        }
        else if( choice == 2 ){
            book_printer.printPrevious();
        }
        else{
            book_printer.printNext();
        }
    }
}

void StartSessions::ContinueOldSession( Customer* Customer ){


    if(Customer->printSessions() ){
    std::cout<<"Enter number to choose a session\n" ;
    int choice ;
    std::cin >> choice ;
    Session* session ;
    session = Customer->getSession(choice-1) ;
    int last_opend_page ;
    last_opend_page = openBook( session->getSessionBook() , session->getPage() ) ;
    session->setSessionpage(last_opend_page) ;
    }


}

void StartSessions::startNewSession( Customer* customer ){

    Session* session = new Session ;
    SystemBooks* system_books = SystemBooks::get_instance() ;
    system_books->viewBooks() ;
    std::cout<<"Enter number to choose a Book\n" ;
    int choice ;
    std::cin >> choice ;
    int last_opend_page ;
    last_opend_page = openBook( system_books->getBook(choice-1) , 1 ) ;
    session->setSessionpage(last_opend_page) ;
    session->setSessionBook(system_books->getBook(choice-1));
    customer->addSession(session) ;

}
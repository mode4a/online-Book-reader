#include"Session.hpp"

int Session::getPage() const {
    return page; 
}
void Session::printSession() const{
    std::cout << book_ptr->getName() << "  " << "page " << page << " / " << book_ptr->getNumOfPages() << std::endl ;
}
void Session::setSessionBook( const Book* book_ ){
    book_ptr = book_ ;
}
void Session::setSessionpage( int page_ ){
    page = page_ ;
}
const Book* Session::getSessionBook() const {
    return book_ptr ;
}

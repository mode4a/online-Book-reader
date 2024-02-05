#include"Book.hpp"


                                                        // Book \\

Book::Book(){}
Book::Book(  std::string title , std::string author , std::vector<std::string> pages ):
title(title) , author_name(author) , pages(pages){}

std::string Book::getName() const {
    return title ;
}
std::string Book::getPage(int idx) const {
    return pages[idx] ;
}
int Book::getNumOfPages() const {
    return pages.size() ;
}
void Book::setBook(){
    
    std::cout << "enter books's title : \n" ; std::cin >> title ;
    std::cout << "enter book's author name : \n" ; std::cin >> author_name ;
    int num_of_pages ;
    std::cout << "enter num of pages : \n" ; std::cin >> num_of_pages ;
    for( int i = 0 ; i < num_of_pages ; ++i ){
        std::cout << "enter page # : " << i+1 << " : \n" ; 
        std::string input_string ;  
        std::cin >> input_string ;
        pages.push_back(input_string) ;
    }

}
                                                     // Book Printer \\ 

BookPrinter::BookPrinter( const Book* book ) : book(book) , current_page(0) {}

void BookPrinter::setPage( int idx ){
    current_page = idx ;
}
int BookPrinter::getPage() const{
    return current_page ;
}
bool BookPrinter::has_previous() const {
    if( current_page > 0 && current_page < book->getNumOfPages() )
            return 1 ;
    return 0 ;
}
bool BookPrinter::has_next() const {
    if( current_page >= 0 && current_page < book->getNumOfPages()-1 )
            return 1 ;
    return 0 ;
}
bool BookPrinter::checkCurrent() const {
    if( current_page >= 0 && current_page < book->getNumOfPages() )
        return 1 ;
    return 0 ;
}
void BookPrinter::printCurrentPage( int current_page ) const{
    std::cout << "Current Page " ;
    std::cout << current_page+1 << "/" << book->getNumOfPages() << "\n" ;
}
void BookPrinter::printPrevious(){
    if( has_previous() ){
    std::cout << book->getPage(--current_page) << "\t" ;
    printCurrentPage(current_page) ;
    }
    else
    printCurrent() ;
}
void BookPrinter::printCurrent() const {
    if( checkCurrent() ){
    std::cout << book->getPage(current_page) << "\t" ;
    printCurrentPage(current_page) ;
    }
}
void BookPrinter::printNext(){
    if( has_next() ){
    std::cout << book->getPage(++current_page) << "\t" ;
    printCurrentPage(current_page) ;
    }
    else
    printCurrent() ;
}

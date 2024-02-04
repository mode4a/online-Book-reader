#include"Users.hpp"
#include"Book.hpp"
#include"System.hpp"


void User::printDetails() const{
    
    std::cout << "user name : " << user_name << std::endl ;
    std::cout << "name : " << name << std::endl ;
    std::cout << "email : " << email << std::endl ;

}

void Customer::printSessions() const{
    
    int size = sessions.size() ;
    for(int i = 0 ; i < size ; ++i ){
        sessions[i]->printSession() ;
    }

}
Session* Customer::getSession( int idx ) const { // a pointer is returning without const *Dangerous* but sessions must be edited every time 
    return sessions[idx] ;                       // so i think it's mandatory 
}
void Customer::setCustomer(){

    std::cout << "set your user name : " ; std::cin >> user_name ;
    std::cout << "enter your name : " ; std::cin >> name ; 
    std::cout << "enter yout email : " ; std::cin >> email ;
    std::cout << "set your password : " ; std::cin >> password ;


}
void Customer::addSession( Session* session ){
    sessions.push_back(session) ;
}

void Admin::addBook(){
    
    Book* book_ptr ;
    book_ptr = new Book ;
    book_ptr->setBook() ;

    SystemBooks* system_books_ptr = SystemBooks::get_instance() ;
    system_books_ptr->insertBook( book_ptr ) ;

} 

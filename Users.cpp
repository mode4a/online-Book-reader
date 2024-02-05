#include"Users.hpp"
#include"Book.hpp"
#include"SystemBooks.hpp"
void User::setUser(){

    std::cout << "set your user name : " ; std::cin >> user_name ;
    // validate user name 
    std::cout << "enter your name : " ; std::cin >> name ; 
    std::cout << "enter yout email : " ; std::cin >> email ;
    std::cout << "set your password : " ; std::cin >> password ;

}
void User::printDetails() const{
    
    std::cout << "user name : " << user_name << std::endl ;
    std::cout << "name : " << name << std::endl ;
    std::cout << "email : " << email << std::endl ;

}
bool User::checkUSerAndPassword( std::string username , std::string password_ ) const {
    if( user_name == username && password == password_ )
        return 1 ;
    return 0 ;
}
User::User(){}
User::User( std::string user_name , std::string name , std::string email , std::string password ):
    user_name(user_name) , name(name) , email(email) , password(password) {}

bool Customer::printSessions() const{

    int size = sessions.size() ;
    for(int i = 0 ; i < size ; ++i ){
        std::cout << i+1 << " : " ;
        sessions[i]->printSession() ;
        return 1 ;
    }
    if( size == 0 ){
        std::cout << "no previous sessions\n" ;
        return 0 ;
    }
    return 1 ;
}
Session* Customer::getSession( int idx ) const { // a pointer is returning without const *Dangerous* but sessions must be edited every time 
    return sessions[idx] ;                       // so i think it's mandatory 
}
void Customer::addSession( Session* session ){
    sessions.push_back(session) ;
}

Customer::~Customer(){
    for(int i = 0 ; i < sessions.size() ; ++i ){
        if( sessions[i] != nullptr ){
            delete sessions[i] ;
            sessions[i] = nullptr ;
        }
    }
}


void Admin::addBook(){
    
    Book* book_ptr ;
    book_ptr = new Book ;
    book_ptr->setBook() ;

    SystemBooks* system_books_ptr = SystemBooks::get_instance() ;
    system_books_ptr->insertBook( book_ptr ) ;

}
Admin::Admin(){}
Admin::Admin(std::string user_name , std::string name , std::string email , std::string password):
User(user_name , name , email , password ){}

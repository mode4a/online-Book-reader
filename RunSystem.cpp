#include"RunSystem.hpp"
#include"Startsessions.hpp"


int RunSystem::takeChoice() const {
    int choice ;
    std::cin >> choice ;
    return choice ;
}
int RunSystem::selectMode() const {

    std::cout<< 
    "1 : Admin \n2 : Customer\n\
    Enter number in Range 1-2\n" ;
    return takeChoice() ;

}
int RunSystem::logInOrSignUp() const{

    std::cout<< "1 : Sign up \n2 : log in\n\
    Enter number in Range 1-2\n" ;
    return takeChoice() ;

}
int RunSystem::printAdminMenu() const{

    std::cout<< "1 : View Profile \n\
    2 : Add Book\n\
    3 : Logout\n\
    Enter number in Range 1-3\n" ;
    return takeChoice() ;
    
}
int RunSystem::printCustomerMenu() const {
    std::cout<< "1 : View Profile \n\
    2 : List And Select From My Reading History\n\
    3 : List And Select From Available Books\n\
    4 : Logout\n\
    Enter number in Range 1-4\n" ;
    return takeChoice() ;
}
void RunSystem::startAdminMenu( Admin* admin ) const {

    int choice = printAdminMenu() ;
    if ( choice == 1 ){
        admin->printDetails() ;
    }
    else if ( choice == 2 ){
        admin->addBook() ;
    }
    else
    {
        return ;
    }
    startAdminMenu(admin) ;

}
void RunSystem::startCustomerMenu( Customer* customer ) const {

    int choice = printCustomerMenu() ;
    if ( choice == 1 ){
        customer->printDetails() ;
    }
    else if ( choice == 2 ){
        StartSessions::ContinueOldSession(customer) ;    
    }
    else if ( choice == 3 )
    {
        StartSessions::startNewSession(customer) ;
    }
    else
    {
        return ;
    }
    startCustomerMenu(customer) ;
}

void RunSystem::startProgram(){

    SystemBooks* system_books = SystemBooks::get_instance() ;
    SystemUsers* system_users = SystemUsers::get_instance() ;

    int mode ; // 1 -> Admin      2 -> Customer
    mode = selectMode() ;

    if( mode == 2 ){
        int log_sign ; // 1 -> sign up  2 -> log in  
        log_sign = logInOrSignUp() ;
        Customer* current_customer ;
        if ( log_sign == 1 ){
            current_customer = system_users->signUp() ;
        }
        else{
           current_customer = system_users->customerLogIn() ;
        }
        startCustomerMenu( current_customer ) ;
    }
    else if( mode == 1 ){
        Admin* current_admin ;
        current_admin = system_users->adminLogIn();
        startAdminMenu( current_admin ) ;
    }
    startProgram() ;

}
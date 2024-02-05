#include"SystemUsers.hpp"

SystemUsers* SystemUsers::system_users_obj = nullptr ;  

SystemUsers* SystemUsers::get_instance(){
    if( system_users_obj == nullptr ){
       system_users_obj = new SystemUsers ; 
    }
    return system_users_obj ;
}
void SystemUsers::freeInstance(){
    if( system_users_obj != nullptr ){
        delete system_users_obj ; 
        system_users_obj = nullptr ;
        std::cout << "system users object freed\n" ;
    }
}
Customer* SystemUsers::signUp(){

    Customer* current_customer ;
    current_customer = new Customer ;
    current_customer->setUser() ;
    customers.push_back(current_customer);
    return current_customer ;

}
std::pair<std::string,std::string> SystemUsers::takeUserAndPassword() {
    std::cout << "Enter user name\n" ;
    std::string username ;
    std::cin >> username ;
    std::cout << "Enter Password\n" ;
    std::string password ;
    std::cin >> password ;
    return std::make_pair( username , password ) ;
}
Customer* SystemUsers::customerLogIn(){

    while( true ){

    std::pair<std::string,std::string> userAndPass = takeUserAndPassword() ;
    for( int i = 0 ; i < customers.size() ; ++i ){
        if( customers[i]->checkUSerAndPassword( userAndPass.first , userAndPass.second )  ){
            return customers[i] ;
        }
    }
    std::cout << "Wrong username or password\ntry again" ;
    }

}
Admin* SystemUsers::adminLogIn(){
    
    while( true ){

    std::pair<std::string,std::string> userAndPass = takeUserAndPassword() ;

    for( int i = 0 ; i < Admins.size() ; ++i ){
        if( Admins[i]->checkUSerAndPassword( userAndPass.first , userAndPass.second )  ){
            return Admins[i] ;
        }
        else
            std::cout << "wrong username or password\ntryagain\n" ;
    }
    }

}
void SystemUsers::freeUsers(){

    for( int i = 0 ; i < Admins.size() ; ++i ){
        if( Admins[i] != nullptr ){
            delete Admins[i] ;
            Admins[i] = nullptr ; 
            std::cout << "Admin " << i+1 << " freed\n" ;
        }
    }
    for(int i = 0 ; i < customers.size() ; ++i ){
        if( customers[i] != nullptr ){
            delete customers[i] ;
            customers[i] = nullptr ;
            std::cout << "Customer " << i+1 << " freed\n" ;
        }
    }
    
}
void SystemUsers::addAdmin( Admin* admin ){
    Admins.push_back(admin) ;
}

void SystemUsers::loadAdmins(){

    Admin* mostafa = new Admin( "Mostafa" , "Mostafamahmoud" , "mm95@gmail.com" , "123" ) ;
    Admin* ali = new Admin( "Ali" , "Alimahmoud" , "Ali30@gmail.com" , "111" ) ;
    SystemUsers* system_users = SystemUsers::get_instance() ;
    system_users->addAdmin( mostafa ) ;
    system_users->addAdmin( ali ) ;

}
void SystemUsers::printAdmins(){
    for(int i = 0 ; i < Admins.size() ; ++i ){
        Admins[i]->printDetails() ;
    }
}
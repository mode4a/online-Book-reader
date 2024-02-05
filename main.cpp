
#include"RunSystem.hpp"
#include<iostream>
int main(){

    SystemUsers* system_users = SystemUsers::get_instance() ;
    system_users->loadAdmins() ;
    SystemBooks* system_books = SystemBooks::get_instance() ;
    system_books->loadBooks();

    RunSystem run ;
    run.startProgram() ;


    system_users->freeUsers();
    system_users->freeInstance();
    system_books->freeBooks() ;
    system_books->freeInstance() ;


    return 0 ;
}
#include"Book.hpp"
#include"Session.hpp"
#include"Users.hpp"

int main(){

    freopen("file.txt" , "rt" , stdin ) ;
    freopen("output.txt" , "wt" , stdout ) ;

    Admin mostafa ; 
    mostafa.addBook() ;
    mostafa.addBook() ;
    mostafa.addBook() ;
    SystemBooks* system_books = SystemBooks::get_instance() ;
    system_books->viewBooks() ;
    system_books->openBook( 0 , 0 ) ;

    
    
    
}
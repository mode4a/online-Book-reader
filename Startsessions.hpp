#ifndef STS
#define STS

#include"Users.hpp"
#include"SystemBooks.hpp"

class StartSessions{
    private:

    static void printBookMenu() ;
    static int openBook( const Book* , int );

    public:

    static void ContinueOldSession( Customer* ) ;
    static void startNewSession( Customer* ) ; 

};


#endif
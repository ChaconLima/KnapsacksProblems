#ifndef DATABASE_H
#define DATABASE_H
#include<string>
#include <mysql/mysql.h>

#include "input.h"
#include "answer.h"

class Input; class Answer;
class DataBase
{
    private:

        char *SERVER; 
        char *USER;
        char *PASSWORD;
        char *DATABASE;

        MYSQL *connect;

        void finish_with_error( MYSQL *connect);


    public:
        DataBase();
        Input findById(const std::string *key);
        bool persist(const Answer *answer);      
};





#endif
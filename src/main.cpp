#include<iostream>
#include<string>

#include "database.h"
#include "input.h"

using std::cout;
using std::endl;
int main( int argc, char *argv[] )
{

    DataBase dataBase;
    Input input;

    std::string key = "2";
    
    input = dataBase.findById(&key);
    

    cout<<input.getMaximunCapacity()<<"\n"<<input.getKey()<<"\n";


    return 0;

}
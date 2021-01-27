#include<iostream>
#include<string>

#include "database.h"
#include "greedyHeuristics.h"

using std::cout;
using std::endl;
int main( int argc, char *argv[] )
{

    DataBase database;
    std::string key = argv[1];

    Input input = database.findById(&key);

    GreedyHeuristics greedyHeuristics( &input );

    Answer answer = greedyHeuristics.getAnswer();
    answer.print();

   

    return 0;

}
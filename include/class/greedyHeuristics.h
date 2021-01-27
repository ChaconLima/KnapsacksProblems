#ifndef GREEDYHEURISTICS_H
#define GREEDYHEURISTICS_H

#include<vector>

#include "database.h"

using SetOfCandidates = std::vector<Item>;

class DataBase; class Input; class Answer;
class GreedyHeuristics
{
    private:

        Answer answer;
        Input input;

        const std::string id;

        
        void run();
        SetOfCandidates constructionOfCandidates();

    public:
        GreedyHeuristics(const Input *input);
        Answer getAnswer();

};


#endif
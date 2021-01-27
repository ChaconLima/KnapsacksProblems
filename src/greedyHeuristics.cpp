#include "greedyHeuristics.h"
#include<iostream>
#include <algorithm>    // std::sort
//CONTRUCTOR--------------------------------
//
//==========================================
GreedyHeuristics::GreedyHeuristics( const Input *input):input(*input){

    this->run();
}
//CONSTRUCTION OF CANDIDATES-------------------
//
//==========================================
SetOfCandidates GreedyHeuristics::constructionOfCandidates(){

    SetOfCandidates setOfCandidates;

    for(const auto &item : this->input.getItens())
    {
        if(setOfCandidates.size() == 0){
            setOfCandidates.push_back(item.second);
        }
        else{

            double costxBenefit = 0;
            costxBenefit = item.second.benefit / item.second.weight;
            unsigned int size = setOfCandidates.size();

            for (size_t i = 0; i < setOfCandidates.size(); i++){

                if( setOfCandidates[i].benefit/setOfCandidates[i].weight < costxBenefit){

                    setOfCandidates.insert(setOfCandidates.begin()+i, item.second);
                    i = setOfCandidates.size();
                }
            }
            if( setOfCandidates.size() == size){
                setOfCandidates.push_back(item.second);
            }
        }
    }

    return setOfCandidates;

}
//RUN PROGRAMIN--------------------------------
//
//==========================================
void GreedyHeuristics::run(){

    
    SetOfCandidates setOfCandidates = this->constructionOfCandidates();
    Answer current;

    std::string key = "1";
    current.setKey(&key);

    while ( setOfCandidates.size() != 0 )
    {
        Item item = setOfCandidates[0];
        double Fo = 0;
        double capacityUsed = 0;
        double calculationCapacity = 0;

        calculationCapacity = this->input.getMaximunCapacity() - (current.getCapacityUsed() + item.weight);

        if(calculationCapacity >= 0){
            Fo+= current.getFo()+item.benefit;
            capacityUsed+= current.getCapacityUsed()+item.weight;

            current.setFo(&Fo);
            current.setCapacityUsed(&capacityUsed);
            current.setItem(&item, &item.key);
        }
        setOfCandidates.erase(setOfCandidates.begin()+0);
    }
    this->answer=current;
}
//GET ANSWER--------------------------------
//
//==========================================
Answer GreedyHeuristics::getAnswer(){

    return this->answer;
}

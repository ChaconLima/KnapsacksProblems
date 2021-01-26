#ifndef ANSWER_H
#define ANSWER_H

#include<string>
#include<map>
#include"item.h"

using Itens = std::map<std::string, Item>;

class Answer
{
    private:
        std::string key;
        double capacityUsed;
        double Fo;
        Itens itens;

    public:
        Answer()=default;
        
        void setKey(std::string *key) {
            this->key = *key;
        }
    
        void setCapacityUsed(double *capacityUsed){
            this->capacityUsed = *capacityUsed;
        }

        void setFo(double *Fo){
            this->Fo = *Fo;
        }
            
        void setItens(Itens *itens){
            this->itens = *itens;
        }

        std::string getKey(){
            return this->key;
        }

        double getCapacityUsed(){
            return this->capacityUsed;
        }

        double getFo(){
            return this->Fo;
        }

        Itens getItens(){
            return this->itens;
        }
};
#endif
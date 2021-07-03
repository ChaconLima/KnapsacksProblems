#ifndef INPUT_H
#define INPUT_H

#include<string>
#include<map>
#include"item.h"

using Itens = std::map<std::string, Item>;

class Input
{
    private:
        std::string name;
        double maximunCapacity;
        Itens itens;

    public:
        Input()=default;
        
        void setName(std::string *key) {
            this->name = *key;
        }
    
        void setMaximunCapacity(double *maximunCapacity){
            this->maximunCapacity = *maximunCapacity;
        }
            
        void setItens(Itens *itens){
            this->itens = *itens;
        }
        std::string getKey(){
            return this->name;
        }
        double getMaximunCapacity(){
            return this->maximunCapacity;
        }
        Itens getItens(){
            return this->itens;
        }
};
#endif
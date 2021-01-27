#ifndef ANSWER_H
#define ANSWER_H

#include<string>
#include<iostream>
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
        Answer(){
            this->capacityUsed = 0;
            this->Fo = 0;
        }
        
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

        void setItem( Item *item, std::string *key){
            this->itens[*key] = *item;
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

        void print(){
            std::cout<<"Resultado do Problema "<<this->key <<"\n";
            std::cout<<"Função Objetiva = "<<this->Fo <<"\n";
            std::cout<<"Capacidade Utilizada = "<<this->capacityUsed<<"\n";
            for( auto &item : this->itens){
                std::cout<<"Item = "<<item.second.key <<"\t";
                std::cout<<"Beneficio = "<<item.second.benefit <<"\t";
                std::cout<<"Peso = "<<item.second.weight <<"\n";
            }
        }
};
#endif
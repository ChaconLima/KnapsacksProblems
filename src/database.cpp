#include"database.h"
#include <stdio.h>
#include<iostream>
#include <iomanip>
#include<cstring>
#include <json/json.h>



//CONTRUCTOR--------------------------------
//
//==========================================
DataBase::DataBase(){

    this->DATABASE = "optimization_project" ; this->SERVER = "localhost"; 
    this->PASSWORD = "Op@123time"; this->USER = "MOTOR";

    this->connect = mysql_init(NULL);

    if (!this->connect)
    {
        std::cerr << "Mysql Initialization Failed";
    }

    this->connect = mysql_real_connect(this->connect, this->SERVER, this->USER, this->PASSWORD, this->DATABASE, 0,NULL,0);

    if (!this->connect) {
        std::cerr << "Mysql Conection Failed";
        this->finish_with_error(this->connect);
    }
}
//FIND BY ID
//
//==========================================
Input DataBase::findById(const std::string *key){

    // Mysql -----------------------
        MYSQL_RES *res_set;
        MYSQL_ROW row;

    // Json ------------------------
        Json::Reader reader; 
        Json::Value obj;

    // Object Itens ----------------
        Itens itens;

    //Object Input ------------------
        Input input;

    //search in database ------------
        std::string command_str = "SELECT * FROM input WHERE id = "+ *key;
        const char* command_char = command_str.data();

        if(mysql_query(this->connect,command_char)){
            this->finish_with_error(this->connect);
        }

        res_set = mysql_store_result(this->connect);

        int num_fields = mysql_num_fields(res_set);

        row = mysql_fetch_row(res_set);
        
        std::string name = row[1];
        double maximunCapacity = atof(row[3]);


    //Reader Json------------
        reader.parse(row[2], obj);
        const Json::Value& attributes = obj["Itens"]; 

    
        for (int i = 0; i < attributes.size(); i++){
            Item item;

            item.key = attributes[i]["name"].asString();
            item.benefit = stod( attributes[i]["benefit"].asString());
            item.weight = stod( attributes[i]["weight"].asString());

            itens[item.key] = item;
        }
    // close mysql
        mysql_free_result(res_set);
        mysql_close(this->connect);

    //set in variables

        input.setItens(&itens);
        input.setName(&name);
        input.setMaximunCapacity(&maximunCapacity);
    
    return input;

}
//  FINISH WITH ERROR
//
//==========================================
void DataBase::finish_with_error( MYSQL *connect)
{
    std::cerr<< mysql_error(connect)<<"\n";
    mysql_close(connect);
    exit(1);
}
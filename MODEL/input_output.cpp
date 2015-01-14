#include "input_output.h"
#include <QFile>
#include <QTextStream>


std::string input_output::file_path ="./PERSISTENT/database.json";

input_output::input_output(){
}

bool input_output::carica_da_file(){
    return true;
}

bool input_output::salva_su_file(){


    return true;
}

void input_output::scrivi_un_utente(smart_utente *ptr_smu, QJsonObject &json_obj)
{
//    if(ptr_smu!=0){
//        json_obj["username"] =ptr_smu->get_ptr_utente()->get_username();
//        json_obj["cognome"] = ptr_smu->get_ptr_utente()->get_cognome();
//        json_obj["nome"] = ptr_smu->get_ptr_utente()->get_nome();
//        //jsonObj["id"] = this->id();
//    }
}

std::string input_output::get_file_path() const{
    return file_path;
}

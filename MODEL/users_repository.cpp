#include "users_repository.h"

#include "utente_basic.h"
#include "utente_business.h"
#include "utente_executive.h"
#include "input_output.h"


DB *users_repository::get_ptr_db() const{
    return ptr_db;
}

users_repository::~users_repository(){
    delete ptr_db;
}

users_repository::users_repository(DB* p_db):ptr_db(p_db){
    if(p_db!=0)           //per estensibilità
        carica_dati(); // da file

    //altrimenti non c'è niente da fare
}

smart_utente *users_repository::get_ptr_smart_utente(const std::string & usrnm){
    return ptr_db->get_ptr_smart_utente(usrnm);
}

utente *users_repository::get_ptr_utente(const std::string & usrnm){
    return ptr_db->get_ptr_utente(usrnm);
}

std::list<smart_utente *> users_repository::get_database() const{
    return ptr_db->get_database();
}

void users_repository::carica_dati(){
    delete ptr_db;
    ptr_db= input_output::carica_da_file();
}

int users_repository::size() const{
    return ptr_db->size();
}

bool users_repository::empty() const{
    return ptr_db->empty();
}




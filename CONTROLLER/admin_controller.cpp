#include "admin_controller.h"
#include "./MODEL/utente_business.h"
#include "./MODEL/input_output.h"

admin_controller::admin_controller(DB* ptr_db):ptr_database(ptr_db){


}

std::list<smart_utente*> admin_controller::get_model_db(){
    return ptr_database->get_database();
}

void admin_controller::salva_db() const{
    input_output io;
    io.salva_su_file(ptr_database);
}

DB* admin_controller::carica_db(){
    return input_output::carica_da_file();
}






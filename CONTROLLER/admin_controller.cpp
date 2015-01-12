#include "admin_controller.h"
#include "./MODEL/utente_business.h"

admin_controller::admin_controller(DB* ptr_db):ptr_database(ptr_db){

    /* temporaneo
     */
     ptr_database->aggiungi_utente(smart_utente(new utente_business));
    /*
    */
}

std::list<smart_utente*> admin_controller::get_model_db(){
    return ptr_database->get_database();
}

//void admin_controller::popola_tabella(modulo_visualizzazione_utenti *tbl){
//    //tbl->tabella->insertRow(2);
//}




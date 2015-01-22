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


//    //TEMP TEMP TEMP TEMP
//    utente_basic* b=new utente_basic;
//    b->update_nome("Fabio");
//    b->update_cognome("Ros");
//    b->update_username("FabioRos90");
//    b->aggiungi_esperienze_professionali(esperienza_professionale("az","po","lu","de",data(),data()));
//    b->aggiungi_lingua("italiano","C2","C2","C2");
//    b->aggiungi_competenze("XML");
//    b->aggiungi_competenze("PHP");
//    b->aggiungi_competenze("HTML");
//    b->aggiungi_competenze("WordPress");

//    smart_utente io(b);
//    ptr_db->aggiungi_utente(io);



//    utente_executive* user_mario=new utente_executive;
//    user_mario->set_carta_di_credito("cc123456");
//    user_mario->update_nome("Mario");
//    user_mario->update_cognome("Rossi");
//    user_mario->update_username("MarioRossi50");
//    user_mario->aggiungi_utente_a_rete(&io);
//    smart_utente mariorossi(user_mario);
//    ptr_db->aggiungi_utente(mariorossi);

//    //TEMP TEMP TEMP TEMP

    //...   da chiamare il carica dati di input_output
    delete ptr_db;
    ptr_db= input_output::carica_da_file();
}

int users_repository::size() const{
    return ptr_db->size();
}

bool users_repository::empty() const{
    return ptr_db->empty();
}




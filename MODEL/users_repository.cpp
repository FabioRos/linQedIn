#include "users_repository.h"

#include "utente_basic.h"


users_repository::users_repository(DB* p_db):ptr_db(p_db){
    //if(!p_db)
        carica_dati();
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
    //...


    //TEMP TEMP TEMP TEMP
    utente_basic* b=new utente_basic;
    b->update_nome("Fabio");
    b->update_cognome("Ros");
    b->update_username("FabioRos90");
    smart_utente io(b);
    ptr_db->aggiungi_utente(io);

    utente_basic* user_mario=new utente_basic;
    user_mario->update_nome("Mario");
    user_mario->update_cognome("Rossi");
    user_mario->update_username("MarioRossi50");
    smart_utente mariorossi(user_mario);
    ptr_db->aggiungi_utente(mariorossi);

    //TEMP TEMP TEMP TEMP

}

int users_repository::size() const{
    return ptr_db->size();
}

bool users_repository::empty() const{
    return ptr_db->empty();
}




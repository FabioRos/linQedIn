#include "users_repository.h"

#include "utente_basic.h"
#include "input_output.h"


users_repository::users_repository(DB* p_db):ptr_db(p_db){
    //if(!p_db)
        carica_dati();
        input_output* io;
        io->salva_su_file(p_db);
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
    //...   da chiamare il carica dati di input_output


    //TEMP TEMP TEMP TEMP
    utente_basic* b=new utente_basic;
    b->update_nome("Fabio");
    b->update_cognome("Ros");
    b->update_username("FabioRos90");
    b->aggiungi_esperienze_professionali(esperienza_professionale("az","po","lu","de",data(),data()));
    b->aggiungi_lingua("italiano","C2","C2","C2");
    b->aggiungi_competenze("XML");
    b->aggiungi_competenze("PHP");
    b->aggiungi_competenze("HTML");
    b->aggiungi_competenze("WordPress");

    smart_utente io(b);
    ptr_db->aggiungi_utente(io);



    utente_basic* user_mario=new utente_basic;
    user_mario->update_nome("Mario");
    user_mario->update_cognome("Rossi");
    user_mario->update_username("MarioRossi50");
    user_mario->aggiungi_utente_a_rete(&io);
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




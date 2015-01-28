#include "aggiungi_modifica_utenti.h"
#include "./MODEL/utente_basic.h"
#include "./MODEL/utente_business.h"
#include "./MODEL/utente_executive.h"
#include "./MODEL/lingua.h"

#include <sstream>

aggiungi_modifica_utenti::aggiungi_modifica_utenti(DB* ptr_database_ )
    :ptr_db(ptr_database_){}

aggiungi_modifica_utenti::aggiungi_modifica_utenti(users_repository* ptr_repo_ )
    :ptr_db(ptr_repo_->get_ptr_db()){}

void aggiungi_modifica_utenti::aggiungi_utente(smart_utente *ptr_smu){
    ptr_db->aggiungi_utente(*ptr_smu);
}

void aggiungi_modifica_utenti::aggiungi_utente(utente *ptr_u){
    ptr_db->aggiungi_utente(smart_utente(ptr_u));
}

void aggiungi_modifica_utenti::rimuovi_utente(const std::string& usrnm){
    ptr_db->rimuovi_utente(usrnm);
}

void aggiungi_modifica_utenti::cambia_tipo_utente(smart_utente *ptr_smu,
                          const std::string& tipo, const std::string& cc){
    ptr_smu->cambio_tipo_utente(tipo,cc);
}

utente* aggiungi_modifica_utenti::costruisci_utente(
        /*tutti i parametri*/const std::string& tipo,const std::string& u,
        const std::string& c, const std::string& n, const std::list<std::string>& comp ,
        const std::list<std::string>& lingue){
    //prendo i campi dati
    utente* nuovo_utente;

    if(tipo=="business"){
        nuovo_utente= new utente_business(n,c,u);
        //manca inserimento cc
    }else if(tipo=="executive"){
        nuovo_utente= new utente_executive(n,c,u);
        //manca inserimento cc
    }else{ //tipo basic
       nuovo_utente= new utente_basic(n,c,u);
    }

    nuovo_utente->aggiungi_competenze(comp);

    nuovo_utente->aggiungi_lingue(converti_tutte_le_lingue(lingue));

   //nuovo_utente->aggiungi_lingua();



    return nuovo_utente;
}

lingua aggiungi_modifica_utenti::esplodi_lingua(const std::string &stringa_lingua){

    string token,descrizione,scritto,parlato,comprensione;
    std::istringstream iss(stringa_lingua, std::istringstream::in);
    while( iss >>  token && token != "#")    {
        descrizione+=token;
    }
    if(iss >>  token)   comprensione=token;
    if(iss >>  token)   parlato=token;
    if(iss >>  token)   scritto=token;

    return lingua(descrizione,comprensione,parlato,scritto);
}

std::list<lingua> aggiungi_modifica_utenti::converti_tutte_le_lingue(
        const std::list<std::string> &ls){
    std::list<lingua> risultato;
    std::list<std::string>::const_iterator it=ls.begin();
    for(;it!=ls.end();++it){
        risultato.push_back(esplodi_lingua(*it));
    }
    return risultato;
}























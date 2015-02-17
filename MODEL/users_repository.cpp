#include "users_repository.h"



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

double users_repository::get_tariffa_business() const{
    utente_business u;
    return u.get_costo_annuale();
}

double users_repository::get_tariffa_executive() const{
    utente_executive u;
    return u.get_costo_annuale();
}

void users_repository::set_tariffa_business(const double& d){
    utente_business u;
    u.set_costo_annuale(d);
}

void users_repository::set_tariffa_executive(const double& d){
    utente_executive u;
    u.set_costo_annuale(d);
}

bool users_repository::is_username_valido(const std::string & s){
    return ptr_db->get_ptr_utente(s)==0;
}

std::list<utente *> users_repository::cerca(users_repository *ptr_repo, const std::string &s,
                                            const int &tipo) const{
    //int indice scelta tipo ricerca

    ///LEGENDA: 1_basic, 100_business, 101_executive

    std::list<utente*> risultato;
    std::list<smart_utente*> lista_ptr_smu=ptr_repo->get_database();
    std::list<smart_utente*>::const_iterator it=lista_ptr_smu.begin();
    switch (tipo) {
    case 1:{//BASIC
        for(;it!=lista_ptr_smu.end();++it){
            // cerca per username, nome o cognome
            utente* u=(*it)->get_ptr_utente();
            if(     (u->get_username().find(s)!=std::string::npos ||
                     u->get_cognome().find(s)!=std::string::npos  ||
                     u->get_nome().find(s)!=std::string::npos))
                risultato.push_back(u);
        }
    }break;
    case 100:{//BUSINESS
        for(;it!=lista_ptr_smu.end();++it){
            // cerca per username, nome o cognome, competenza una lingua.
            utente* u=(*it)->get_ptr_utente();
            if(     u->un_pezzo_di_competenza(s) ||
                    u->esiste_lingua(s) ||
                    u->get_username().find(s)!=std::string::npos ||
                    u->get_cognome().find(s)!=std::string::npos  ||
                    u->get_nome().find(s)!=std::string::npos)
                risultato.push_back(u);
        }
    }break;
    case 101:{  //EXECUTIVE
        for(;it!=lista_ptr_smu.end();++it){
            // cerca per username, nome o cognome o 1 competenza(anche parziale), lingua,
            // nome azienda in cui ha lavorato, posizione, luogo.
            utente* u=(*it)->get_ptr_utente();
            if(  u->un_pezzo_di_competenza(s) || u->ha_lavorato_nell_azienda(s) ||
                 u->ha_lavorato_nella_posizione(s)|| u->ha_lavorato_nella_citta(s) ||
                 u->esiste_lingua(s) ||u->ha_la_competenza(s) ||
                 u->get_username().find(s)!=std::string::npos ||
                 u->get_cognome().find(s)!=std::string::npos  ||
                 u->get_nome().find(s)!=std::string::npos)
                risultato.push_back(u);
        }
    }break;
    default:
        break;
    }
    return risultato;
}



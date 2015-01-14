#include "aggiungi_modifica_utenti.h"

aggiungi_modifica_utenti::aggiungi_modifica_utenti(DB* ptr_database_ )
    :ptr_db(ptr_database_){}

void aggiungi_modifica_utenti::aggiungi_utente(smart_utente *ptr_smu){
    ptr_db->aggiungi_utente(*ptr_smu);
}

void aggiungi_modifica_utenti::rimuovi_utente(const std::string& usrnm){
    ptr_db->rimuovi_utente(usrnm);
}

void aggiungi_modifica_utenti::cambia_tipo_utente(smart_utente *ptr_smu,
                          const std::string& tipo, const std::string& cc){
    ptr_smu->cambio_tipo_utente(tipo,cc);
}

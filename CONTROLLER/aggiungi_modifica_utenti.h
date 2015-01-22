#ifndef AGGIUNGI_MODIFICA_UTENTI_H
#define AGGIUNGI_MODIFICA_UTENTI_H

#include "./MODEL/db.h"
#include "./MODEL/utente.h"

class aggiungi_modifica_utenti{
    DB* ptr_db;
public:
    aggiungi_modifica_utenti(DB*);
    void aggiungi_utente(smart_utente*);
    void rimuovi_utente(const std::string&);
    void cambia_tipo_utente(smart_utente*, const std::string&, const std::string& ="");
    utente* costruisci_utente() const;
};

#endif // AGGIUNGI_MODIFICA_UTENTI_H

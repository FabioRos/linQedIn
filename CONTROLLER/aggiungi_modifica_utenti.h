#ifndef AGGIUNGI_MODIFICA_UTENTI_H
#define AGGIUNGI_MODIFICA_UTENTI_H

#include "./MODEL/db.h"
#include "./MODEL/utente.h"
#include "./MODEL/users_repository.h"

class aggiungi_modifica_utenti{
    DB* ptr_db;
public:
    aggiungi_modifica_utenti(DB*);
    aggiungi_modifica_utenti(users_repository*);
    void aggiungi_utente(smart_utente*);
    void aggiungi_utente(utente*);
    void rimuovi_utente(const std::string&);
    void cambia_tipo_utente(smart_utente*, const std::string&, const std::string& ="");
    static utente* costruisci_utente(const std::string& tipo,const std::string& username,
                              const std::string& cognome, const std::string& nome,
                              const std::list<std::string>&comp,
                              const std::list<std::string>& lingue);  //..da completare
    static lingua esplodi_lingua(const std::string&);  //da testare
    static std::list<lingua> converti_tutte_le_lingue(const std::list<std::string>&s); //da testare
};

#endif // AGGIUNGI_MODIFICA_UTENTI_H

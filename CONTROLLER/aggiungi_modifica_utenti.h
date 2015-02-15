#ifndef AGGIUNGI_MODIFICA_UTENTI_H
#define AGGIUNGI_MODIFICA_UTENTI_H

#include "../MODEL/db.h"
#include "../MODEL/utente.h"
#include "../MODEL/users_repository.h"

class aggiungi_modifica_utenti{
    DB* ptr_db;
public:
    //aggiungi_modifica_utenti(DB*);
    aggiungi_modifica_utenti(users_repository*);
    void aggiungi_utente(smart_utente*);
    void aggiungi_utente(utente*);
    void rimuovi_utente(const std::string&);
    void cambia_tipo_utente(smart_utente*, const std::string&, const std::string& ="");
    static utente* costruisci_utente( const std::string& tipo,
                                      const std::string& username,
                                      const std::string& cognome,
                                      const std::string& nome,
                                      const std::list<std::string>&comp,
                                      const std::list<std::string>& lingue,
                                      const std::list<std::string>& esperienze,
                                      const std::string& cc);
    static lingua esplodi_lingua(const std::string&);
    static esperienza_professionale esplodi_esperienza(const std::string&);
    static std::list<lingua> converti_tutte_le_lingue(const std::list<std::string>&s);
    static std::list<esperienza_professionale> converti_tutte_le_esperienze(
            const std::list<std::string>&s);//da fare
    void aggiungi_competenze_ad_utente(const std::list<std::string>&c, //da testare
                                       const std::string& u);
    void riscrivi_competenze_di_un_utente(const std::list<std::string>&c, //da testare
                                          const std::string& u);
    void aggiorna_nome(const std::string& usr, const std::string& n);
    void aggiorna_cognome(const std::string& usr, const std::string& c);
    void aggiungi_lingua_a_utente( const std::string &usr,  const std::string &d,
                                   const std::string &c,    const std::string &p,
                                   const std::string &s);
    void rimuovi_tutte_le_lingue(const std::string &usr);
    void aggiungi_esperienza(const std::string &usr,  const std::string &nome_azienda,
                             const std::string &posizione,    const std::string &luogo,
                             const std::string &descrizione, const std::string &data_inizio,
                             const std::string &data_fine);
    void rimuovi_tutte_le_esperienze(const std::string &usr);
    bool aggiungi_A_alla_rete_di_B(const std::string &username_A,const std::string &username_B);    //da testare
    bool rimuovi_A_alla_rete_di_B(const std::string &username_A,const std::string &username_B);     //da testare
    bool esiste_A_nella_rete_di_B(const std::string &username_A,const std::string &username_B);     // da testare
};

#endif // AGGIUNGI_MODIFICA_UTENTI_H

#ifndef UTENTE_H
#define UTENTE_H

#include <string>
#include <list>
#include <vector>
#include "esperienza_professionale.h"
#include "lingua.h"
#include "rete.h"

#include <QJsonArray>

#include <iostream>


//per virtualizzare il salvataggio
#include <QJsonObject>


//  {MODEL_utente}

class users_repository;
class utente{
    private:
        std::string nome;
        std::string cognome;
        std::string username;
        std::list<esperienza_professionale> esperienze_professionali;
        std::list<std::string> competenze;  //conviene mettere map per agevolare la ricerca
                                           //con la stringa della competenza/lingua
        std::map<std::string,lingua> lingue;
        rete rete_;
    public:
        //Costruttore a 0~3 argomenti
       explicit utente(const std::string& ="", const std::string& ="", const std::string& ="");
       //costruttore completo
       utente(  const std::string& n , const std::string& c,
                const std::string& usn ,
                const std::list<esperienza_professionale>& e,
                const std::list<std::string>& com,
                const std::map<std::string,lingua> l,
                const rete& r);

        // _GET_
        std::string get_nome() const;
        std::string get_cognome() const;
        std::string get_username() const;
        std::list<esperienza_professionale> get_esperienze_professionali() const;

        std::list<std::string> get_esperienze_professionali_txt() const;
        std::list<std::string> get_competenze() const;
        std::list<std::string> get_lingue() const;  // da testare

        // _SET_
        void update_nome(const std::string&) ;
        void update_cognome(const std::string&) ;
        void update_username(const std::string&) ;
        void aggiungi_esperienze_professionali(const esperienza_professionale&);
        void aggiungi_esperienze_professionali(const std::list<esperienza_professionale>&);
        bool rimuovi_esperienze_professionali(const esperienza_professionale&);   //op==
        void aggiungi_lingua(const std::string&, const std::string&,
                             const std::string&, const std::string&);
        void aggiungi_lingua(const lingua&);
        void aggiungi_lingue(const std::list<lingua>&);
        void rimuovi_lingua(const std::string&);
        void rimuovi_tutte_le_lingue(const std::string&); // da testare
        void rimuovi_tutte_le_esperienze(const std::string&); // da testare
        bool esiste_lingua(const std::string&) const;
        void aggiungi_competenze(const std::string&);
        void aggiungi_competenze(const std::list<std::string>&);
        void rimuovi_competenze(const std::string&);    //da completare
        void rimuovi_tutte_le_competenze(); //da testare
        bool ha_la_competenza (const std::string&) const;
        bool un_pezzo_di_competenza (const std::string&) const;
        bool ha_lavorato_nell_azienda(const std::string&) const;
        bool ha_lavorato_nella_posizione(const std::string&) const;
        bool ha_lavorato_nella_citta(const std::string&) const;
        virtual ~utente();//   da fare
        virtual std::list<utente*> cerca(users_repository*,const std::string&) const =0;

        bool esiste_nella_rete(const std::string&) const; //username


        //da testare
        //utente* operator=(utente*);
        std::list<utente*> get_all_rete() const;
        utente *aggiungi_utente_a_rete(smart_utente*);
        void *aggiungi_utente_a_rete(const std::string& username ,smart_utente* ptr_smu);
        utente *rimuovi_utente_da_rete(smart_utente*);
        void rimuovi_utente_da_rete(const std::string&);
        virtual utente* clona_utente() const =0 ;
        //genero record in json
        virtual void scrivi_json(QJsonObject &json) const;

};

#endif // UTENTE_H

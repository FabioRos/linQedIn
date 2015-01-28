#ifndef UTENTE_H
#define UTENTE_H

#include <string>
#include <list>
#include <vector>
#include "esperienza_professionale.h"
#include "lingua.h"
#include "rete.h"

//per virtualizzare il salvataggio
#include <QJsonObject>


//  {MODEL_utente}

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
        std::list<std::string> get_competenze() const;

        // _SET_
        void update_nome(const std::string&) ;
        void update_cognome(const std::string&) ;
        void update_username(const std::string&) ;
        void aggiungi_esperienze_professionali(const esperienza_professionale&);
        bool rimuovi_esperienze_professionali(const esperienza_professionale&);   //op==
        void aggiungi_lingua(const std::string&, const std::string&,
                             const std::string&, const std::string&);
        void aggiungi_lingua(const lingua&);
        void aggiungi_lingue(const std::list<lingua>&);
        void rimuovi_lingua(const std::string&);
        bool esiste_lingua(const std::string&) const;
        void aggiungi_competenze(const std::string&);
        void aggiungi_competenze(const std::list<std::string>&);
        void rimuovi_competenze(const std::string&);    //da completare
        bool ha_la_competenza (const std::string&) const;
        virtual ~utente();//   da fare
        virtual std::list<utente*> cerca()=0;

        bool esiste_nella_rete(const std::string&) const; //username


        //da testare
        //utente* operator=(utente*);
        std::list<utente*> get_all_rete() const;
        virtual utente *aggiungi_utente_a_rete(smart_utente*);
        virtual utente *rimuovi_utente_da_rete(smart_utente*);
        virtual utente *rimuovi_utente_da_rete(const std::string&);
        virtual utente* clona_utente() const =0 ;
        //genero record in json
        virtual void scrivi_json(QJsonObject &json) const;

};

#endif // UTENTE_H

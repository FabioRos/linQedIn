#ifndef UTENTE_H
#define UTENTE_H

#include <string>
#include <list>
#include "esperienza_professionale.h"
#include "lingua.h"
#include "rete.h"


//  {MODEL_utente}

class utente{
    private:
        std::string nome;
        std::string cognome;
        std::string username;
        std::list<esperienza_professionale> esperienze_professionali;
        std::list<std::string> competenze;  //conviene mettere map per agevolare la ricerca
        std::list<lingua> lingue;           //con la stringa della competenza/lingua
        rete rete_;
    public:
        //Costruttore a 0~3 argomenti
       explicit utente(const std::string& ="", const std::string& ="", const std::string& ="");
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
//        void aggiungi_competenze(const std::string&);
//        void rimuovi_competenze(const std::string&);

        virtual ~utente();
        virtual std::list<utente*> cerca()=0;
        //virtual utente* aggiungi_utente_a_rete()=0; //a rete
        //virtual utente* rimuovi_utente()=0;   // a rete
        virtual utente* clona_utente() const =0 ;
};

#endif // UTENTE_H

#include "aggiungi_modifica_utenti.h"


#include <sstream>


//temp
#include <iostream>
//temp

//aggiungi_modifica_utenti::aggiungi_modifica_utenti(DB* ptr_database_ )
//    :ptr_db(ptr_database_){}

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
        const std::list<std::string>& lingue, const std::list<std::string>& esperienze,
        const std::string& cc){
    //prendo i campi dati
    utente* nuovo_utente;



    if(tipo=="BUSINESS"){
        nuovo_utente= new utente_business(n,c,u);
        static_cast<utente_business*>(nuovo_utente)->set_carta_di_credito(cc);
    }else if(tipo=="EXECUTIVE"){
        nuovo_utente= new utente_executive(n,c,u);
        static_cast<utente_executive*>(nuovo_utente)->set_carta_di_credito(cc);
    }else{ //tipo basic
       nuovo_utente= new utente_basic(n,c,u);
    }

    nuovo_utente->aggiungi_competenze(comp);

    nuovo_utente->aggiungi_lingue(converti_tutte_le_lingue(lingue));

    nuovo_utente->aggiungi_esperienze_professionali(converti_tutte_le_esperienze(esperienze));

    return nuovo_utente;
}

lingua aggiungi_modifica_utenti::esplodi_lingua(const std::string &stringa_lingua){

    std::string token,descrizione,scritto,parlato,comprensione;
    std::istringstream iss(stringa_lingua, std::istringstream::in);
    while( iss >>  token && token != "#")    {
        descrizione+=token;
    }
    if(iss >>  token)   comprensione=token;
    if(iss >>  token)   parlato=token;
    if(iss >>  token)   scritto=token;

    return lingua(descrizione,comprensione,parlato,scritto);
}

esperienza_professionale aggiungi_modifica_utenti::esplodi_esperienza(const std::string &stringa_esperienza){
      std::string token,descrizione,luogo,nome_azienda,posizione;
      std::string giorno_i, mese_i, anno_i,giorno_f,mese_f,anno_f;

      std::istringstream iss(stringa_esperienza, std::istringstream::in);
      //metto i cicli while in serie cosi scarto i cancelletti ed accetto input di più parole
      while( iss >>  token && token != "#")    {
          descrizione+=token;
      }
      while( iss >>  token && token != "#")    {
          luogo+=token;
      }
      while( iss >>  token && token != "#")    {
          nome_azienda+=token;
      }
      while( iss >>  token && token != "#")    {
          posizione +=token;
      }
      //data inizio
      iss>>giorno_i;        //ho definito io il formato quindi so che sono
      iss>>mese_i;          //disposti così
      iss>>anno_i;
      //data fine
      iss>>giorno_f;
      iss>>mese_f;
      iss>>anno_f;

      //ora devo convertrire le date che al momento sono tutte stringhe.
      int gi,mi,ai,gf,mf,af;
      std::istringstream ( giorno_i ) >> gi;
      std::istringstream ( mese_i )   >> mi;
      std::istringstream ( anno_i )   >> ai;
      std::istringstream ( giorno_f ) >> gf;
      std::istringstream ( mese_f )   >> mf;
      std::istringstream ( anno_f )   >> af;

      data inizio(gi,mi,ai);
      data fine(gf,mf,af);

    return esperienza_professionale(nome_azienda,posizione,luogo,descrizione,inizio,fine);
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

std::list<esperienza_professionale> aggiungi_modifica_utenti::converti_tutte_le_esperienze(
        const std::list<std::string> &s){
    std::list<esperienza_professionale> risultato;
    std::list<std::string>::const_iterator it=s.begin();
    for(;it!=s.end();++it){
       // risultato.push_back(esplodi_esperienza(*it));
    }
    return risultato;
}

void aggiungi_modifica_utenti::aggiungi_competenze_ad_utente(
        const std::list<std::string> &c, const std::string &u){
    if(!c.empty()){
            utente* ptr_usr=ptr_db->get_ptr_utente(u);
            ptr_usr->aggiungi_competenze(c);
    }
}

void aggiungi_modifica_utenti::riscrivi_competenze_di_un_utente(const std::list<std::string> &c, const std::string &u){
    if(!c.empty()){
//        std::list<std::string>::const_iterator it=c.begin();
//        for(;it!=c.end();++it)
//            std::cout << *it;


        utente* ptr_usr=ptr_db->get_ptr_utente(u);
        ptr_usr->rimuovi_tutte_le_competenze();
        ptr_usr->aggiungi_competenze(c);
    }
//    else{
//        std::cout<<"lista vuota";
//    }
}

void aggiungi_modifica_utenti::aggiorna_nome(const std::string & usr,const std::string & n){
    std::cout<<"\n nome:   "<<n<<"\t \tu: "<<usr<<"\n";
    utente* ptr_usr=ptr_db->get_ptr_utente(usr);
    ptr_usr->update_nome(n);
}

void aggiungi_modifica_utenti::aggiorna_cognome(const std::string &usr, const std::string &c){
    std::cout<<"\n cognome: "<<c<<"\t \t u: "<<usr<<"\n";
    utente* ptr_usr=ptr_db->get_ptr_utente(usr);
    ptr_usr->update_cognome(c);
}

void aggiungi_modifica_utenti::aggiungi_lingua_a_utente(const std::string &usr,
                              const std::string &d, const std::string &c,
                              const std::string &p, const std::string &s){

    ptr_db->get_ptr_utente(usr)->aggiungi_lingua(d,c,p,s);
}

void aggiungi_modifica_utenti::rimuovi_tutte_le_lingue(const std::string &usr){
    ptr_db->get_ptr_utente(usr)->rimuovi_tutte_le_lingue(usr);
}

void aggiungi_modifica_utenti::aggiungi_esperienza(const std::string &usr,
    const std::string &nome_azienda, const std::string &posizione,
    const std::string &luogo, const std::string &descrizione,
    const std::string &data_inizio, const std::string &data_fine){
    data* d_inizio=new data;
    d_inizio->converti_da_string(data_inizio);
    data* d_fine=new data;
    d_fine->converti_da_string(data_fine);
    esperienza_professionale e(nome_azienda,posizione,luogo,descrizione,*d_inizio,*d_fine);
    ptr_db->get_ptr_utente(usr)->aggiungi_esperienze_professionali(e);
    delete d_inizio;
    delete d_fine;
}

void aggiungi_modifica_utenti::rimuovi_tutte_le_esperienze(const std::string &usr){
    ptr_db->get_ptr_utente(usr)->rimuovi_tutte_le_esperienze(usr);
}


bool aggiungi_modifica_utenti::aggiungi_A_alla_rete_di_B(const std::string &username_A, const std::string &username_B){
    utente* utente_host=ptr_db->get_ptr_utente(username_B);
    if(utente_host){
        utente_host->aggiungi_utente_a_rete(ptr_db->get_ptr_smart_utente(username_A));
        return true;
    }
    return false;
}

bool aggiungi_modifica_utenti::rimuovi_A_alla_rete_di_B(const std::string &username_A,
                                                        const std::string &username_B){
    utente* utente_host=ptr_db->get_ptr_utente(username_B);
    bool rimosso=false;
    if(utente_host)
        rimosso=utente_host->rimuovi_utente_da_rete(ptr_db->get_ptr_smart_utente(username_A));
                //aggiungi_utente_a_rete(ptr_db->get_ptr_smart_utente(username_A));

    return rimosso;
}

bool aggiungi_modifica_utenti::esiste_A_nella_rete_di_B(const std::string &username_A,
                                                        const std::string &username_B){
     return ptr_db->get_ptr_utente(username_B)->esiste_nella_rete(username_A);
}

#include "client_controller.h"




//temp
 #include <iostream>
//temp

client_controller::client_controller(users_repository* repo):ptr_repository(repo){
}

bool client_controller::login_autorizzato(const std::string &str) const{
    return(ptr_repository->get_ptr_smart_utente(str)!=0);
}

std::list<std::string> client_controller::get_info_utente(const std::string &username) const{
    std::list<std::string> lista_risultato;

    //[tipo_account,username,cognome,nome,...]


    utente* utente_corrente = ptr_repository->get_ptr_utente(username);
    utente_basic* ptr_utente_corrente =dynamic_cast<utente_basic*>(utente_corrente);
    if(ptr_utente_corrente){
        lista_risultato.push_back("BASIC");
    }else{
        utente_business* ptr_utente_corrente =dynamic_cast<utente_business*>(utente_corrente);
        if(ptr_utente_corrente)
            lista_risultato.push_back("BUSINESS");
        else{

            // faccio comunque il controllo perchè magari in futuro potranno essere
            // inserite nuove tipologie di account.

            utente_executive* ptr_utente_corrente =dynamic_cast<utente_executive*>(utente_corrente);
            if(ptr_utente_corrente)
                lista_risultato.push_back("EXECUTIVE");
        }
    }
    lista_risultato.push_back(utente_corrente->get_username());
    lista_risultato.push_back(utente_corrente->get_cognome());
    lista_risultato.push_back(utente_corrente->get_nome());

   // lista_risultato.push_back("#inizio_competenze#");
    std::list<std::string> lista_competenze=utente_corrente->get_competenze();
    std::list<std::string>::const_iterator it=lista_competenze.begin();
            for (;it!=lista_competenze.end();++it){
                 lista_risultato.push_back(*it);
            }
    lista_risultato.push_back("#fine_competenze#");

    lista_risultato.push_back("#inizio_lingue#");
    std::list<std::string> lista_lingue=utente_corrente->get_lingue();
    std::cout<<lista_lingue.size();
    it=lista_lingue.begin();
    for (;it!=lista_lingue.end();++it){
        lista_risultato.push_back(*it);
    }
    lista_risultato.push_back("#fine_lingue#");
    lista_risultato.push_back("#inizio_esperienze_professionali#");
    std::list<std::string> lista_esperienze=utente_corrente->get_esperienze_professionali_txt();
    it=lista_esperienze.begin();
    for (;it!=lista_esperienze.end();++it){
       // std::cout<<*it;
        lista_risultato.push_back(*it);
    }
    lista_risultato.push_back("#fine_esperienze_professionali#");

    return lista_risultato;

}

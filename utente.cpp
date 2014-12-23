#include "utente.h"

utente::utente(){}
utente::~utente(){}

std::string utente::get_nome() const{
    return nome;
}
std::string utente::get_cognome() const{
    return cognome;
}
std::string utente::get_username() const{
    return username;
}
std::list<esperienza_professionale> utente::get_esperienze_professionali() const{
    return esperienze_professionali;
}
std::list<std::string> utente::get_competenze() const{
    return competenze;
}
void utente::update_nome(const std::string & s){
    nome=s;
}
void utente::update_cognome(const std::string & s){
    cognome=s;
}
void utente::update_username(const std::string & s){
    username=s;
}
void utente::aggiungi_esperienze_professionali(const esperienza_professionale & e){
    esperienze_professionali.push_back(e);
}

//void utente::rimuovi_esperienze_professionali(const esperienza_professionale & e){
//    esperienze_professionali.remove(e);
//}




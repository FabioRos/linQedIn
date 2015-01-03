#include "utente.h"

utente::utente(const std::string & nome_ ,const std::string & cognome_,const std::string & username_)
    :nome(nome_),cognome(cognome_),username(username_){}
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
bool utente::rimuovi_esperienze_professionali(const esperienza_professionale & e){
    for(std::list<esperienza_professionale>::iterator it=esperienze_professionali.begin();
       it!=esperienze_professionali.end();++it){
        if(*it==e){
            esperienze_professionali.erase(it);
            return true;
        }

   }
    return false;
}

void utente::aggiungi_lingua(const std::string & d, const std::string &c,
                             const std::string &p, const std::string &s){
    lingue.push_front(lingua(d,c,p,s));
}

//void utente::rimuovi_esperienze_professionali(const esperienza_professionale & e){
//    esperienze_professionali.remove(e);
//}




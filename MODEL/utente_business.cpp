//#include "utente_business.h"
#include "users_repository.h"

utente_business::utente_business(){
}

utente_business::utente_business(const utente& ptr_u, const std::string& cc)
    :utente_a_pagamento(ptr_u,cc){}

utente_business::utente_business(const std::string &n, const std::string &c, const std::string &usn)
    :utente_a_pagamento(n,c,usn){}

double utente_business::costo_annuale =40;

std::list<utente *> utente_business::cerca(users_repository* ptr_repo, const std::string& s) const{
    std::list<utente*> risultato;
    std::list<smart_utente*> lista_ptr_smu=ptr_repo->get_database();
    std::list<smart_utente*>::const_iterator it=lista_ptr_smu.begin();
    for(;it!=lista_ptr_smu.end();++it){
        // cerca per username, nome o cognome, competenza una lingua.
        utente* u=(*it)->get_ptr_utente();
        if(     u->un_pezzo_di_competenza(s) ||
                u->esiste_lingua(s) ||
                u->get_username().find(s)!=std::string::npos ||
                u->get_cognome().find(s)!=std::string::npos  ||
                u->get_nome().find(s)!=std::string::npos)
            risultato.push_back(u);

    }
    return risultato;
}

utente *utente_business::clona_utente() const{
    return new utente_business(*this);
}

void utente_business::set_costo_annuale(const double &c){
    costo_annuale=c;
}

double utente_business::get_costo_annuale() const{
    return costo_annuale;
}

void utente_business::scrivi_json(QJsonObject &json) const{
    utente_a_pagamento::scrivi_json(json);
    json["tipo_account"] = QString::fromStdString("business");
}

//#include "utente_executive.h"
#include "users_repository.h"

utente_executive::utente_executive(){
}

utente_executive::utente_executive(const utente & ptr_u, const std::string &cc)
    :utente_a_pagamento(ptr_u,cc){}

utente_executive::utente_executive(const std::string &n, const std::string &c, const std::string &usn)
    :utente_a_pagamento(n,c,usn){}


double utente_executive::costo_annuale =120;

std::list<utente *> utente_executive::cerca(users_repository* ptr_repo, const std::string& s) const{
    return ptr_repo->cerca(ptr_repo,s,101);
}

utente *utente_executive::clona_utente() const{
    return new utente_executive(*this);
}


void utente_executive::set_costo_annuale(const double &c){
    costo_annuale=c;
}

double utente_executive::get_costo_annuale() const{
    return costo_annuale;
}

void utente_executive::scrivi_json(QJsonObject &json) const{
    utente_a_pagamento::scrivi_json(json);
    json["tipo_account"] = QString::fromStdString("executive");

}

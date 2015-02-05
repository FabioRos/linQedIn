#include "utente_business.h"

utente_business::utente_business(){
}

utente_business::utente_business(const utente& ptr_u, const std::string& cc)
    :utente_a_pagamento(ptr_u,cc){}

utente_business::utente_business(const std::string &n, const std::string &c, const std::string &usn)
    :utente_a_pagamento(n,c,usn){}

double utente_business::costo_annuale =40;

std::list<utente *> utente_business::cerca(){
    std::list<utente*> risultato;
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

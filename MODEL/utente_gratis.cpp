#include "utente_gratis.h"

utente_gratis::utente_gratis(){}

utente_gratis::utente_gratis(const std::string &n, const std::string &c, const std::string &usn)
    :utente(n,c,usn){}
utente_gratis::utente_gratis(const utente& u):utente(u){}

void utente_gratis::scrivi_json(QJsonObject &json) const{
    utente::scrivi_json(json);
}


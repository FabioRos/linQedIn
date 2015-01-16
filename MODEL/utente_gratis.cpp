#include "utente_gratis.h"

utente_gratis::utente_gratis(){}
utente_gratis::utente_gratis(const utente& u):utente(u){}

void utente_gratis::scrivi_json(QJsonObject &json) const{
    utente::scrivi_json(json);
}


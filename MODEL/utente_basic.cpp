#include "utente_basic.h"

utente_basic::utente_basic(){}

utente_basic::utente_basic(const std::string &n, const std::string &c, const std::string &usn)
    :utente_gratis(n,c,usn){}
utente_basic::utente_basic(const utente& u):utente_gratis(u){}
std::list<utente *> utente_basic::cerca(){
    std::list<utente*> risultato;
    return risultato;
}

utente *utente_basic::clona_utente() const{
    return new utente_basic(*this);
}

void utente_basic::scrivi_json(QJsonObject &json) const{
    json["tipo_account"] = QString::fromStdString("basic");
    utente::scrivi_json(json);

}

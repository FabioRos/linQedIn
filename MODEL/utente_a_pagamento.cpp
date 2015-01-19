#include "utente_a_pagamento.h"

utente_a_pagamento::utente_a_pagamento(const std::string& cc):carta_di_credito(cc){
}
utente_a_pagamento::utente_a_pagamento(const utente& u,const std::string& cc)
    :utente(u),carta_di_credito(cc){
}

utente_a_pagamento::utente_a_pagamento(const std::string &n, const std::string &c, const std::string &usn)
    :utente(n,c,usn){}

std::string utente_a_pagamento::get_carta_di_credito() const{
    return carta_di_credito;
}

void utente_a_pagamento::set_carta_di_credito(const std::string& cc){
    carta_di_credito=cc;
}

void utente_a_pagamento::scrivi_json(QJsonObject &json) const{
   utente::scrivi_json(json);
   json["carta_di_credito"] = QString::fromStdString(carta_di_credito);
}


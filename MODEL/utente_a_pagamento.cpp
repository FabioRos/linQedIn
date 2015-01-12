#include "utente_a_pagamento.h"

utente_a_pagamento::utente_a_pagamento(const std::string& cc):carta_di_credito(cc){
}
utente_a_pagamento::utente_a_pagamento(const utente& u,const std::string& cc)
    :utente(u),carta_di_credito(cc){
}
std::string utente_a_pagamento::get_carta_di_credito() const{
    return carta_di_credito;
}

void utente_a_pagamento::set_carta_di_credito(const std::string& cc){
    carta_di_credito=cc;
}


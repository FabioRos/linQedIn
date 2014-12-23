#include "utente_basic.h"

utente_basic::utente_basic(){}

std::list<utente *> utente_basic::cerca(){
    std::list<utente*> risultato;
    return risultato;
}

utente *utente_basic::clona_utente() const{
    return new utente_basic(*this);
}

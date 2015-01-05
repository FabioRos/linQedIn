#include "utente_business.h"

utente_business::utente_business(){
}

std::list<utente *> utente_business::cerca(){
    std::list<utente*> risultato;
    return risultato;
}

utente *utente_business::clona_utente() const{
    return new utente_business(*this);
}

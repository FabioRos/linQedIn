#include "utente_executive.h"

utente_executive::utente_executive()
{
}

std::list<utente *> utente_executive::cerca(){
    std::list<utente*> risultato;
    return risultato;
}

utente *utente_executive::clona_utente() const{
    return new utente_executive(*this);
}

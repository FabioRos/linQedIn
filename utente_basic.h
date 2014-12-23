#ifndef UTENTE_BASIC_H
#define UTENTE_BASIC_H

#include "utente_gratis.h"
class utente_basic:public utente_gratis{
private:

public:
    utente_basic();
    std::list<utente*> cerca();
    utente* clona_utente() const;   //virtual
};

#endif // UTENTE_BASIC_H

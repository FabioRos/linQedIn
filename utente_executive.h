#ifndef UTENTE_EXECUTIVE_H
#define UTENTE_EXECUTIVE_H

#include "utente_a_pagamento.h"

class utente_executive : public utente_a_pagamento
{
public:
    utente_executive();
    std::list<utente*> cerca();
    utente* clona_utente() const;   //virtual
};

#endif // UTENTE_EXECUTIVE_H

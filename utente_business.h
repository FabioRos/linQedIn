#ifndef UTENTE_BUSINESS_H
#define UTENTE_BUSINESS_H

#include "utente_a_pagamento.h"

class utente_business : public utente_a_pagamento
{
public:
    utente_business();
    std::list<utente*> cerca();
    utente* clona_utente() const;   //virtual
};

#endif // UTENTE_BUSINESS_H

#ifndef UTENTE_BUSINESS_H
#define UTENTE_BUSINESS_H

#include "utente_a_pagamento.h"

class utente_business : public utente_a_pagamento{
private:
    static double costo_annuale;
    void set_costo_annuale(const double &);
public:

    utente_business();
    utente_business(const utente&, const std::string& cc ="");
    std::list<utente*> cerca();
    utente* clona_utente() const;   //virtual
    double get_costo_annuale() const;
};

#endif // UTENTE_BUSINESS_H

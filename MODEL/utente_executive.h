#ifndef UTENTE_EXECUTIVE_H
#define UTENTE_EXECUTIVE_H

#include "utente_a_pagamento.h"

class utente_executive : public utente_a_pagamento{
private:
    static double costo_annuale;
    void set_costo_annuale(const double &);
public:
    utente_executive();
    utente_executive(const utente&, const std::string& cc ="");
   // utente_executive(const utente&);
    std::list<utente*> cerca();
    utente* clona_utente() const;   //virtual
    double get_costo_annuale() const;

};

#endif // UTENTE_EXECUTIVE_H

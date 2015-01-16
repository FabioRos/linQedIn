#ifndef UTENTE_A_PAGAMENTO_H
#define UTENTE_A_PAGAMENTO_H

#include "utente.h"
#include <map>

class utente_a_pagamento : public utente{
private:
    std::string carta_di_credito;
public:
    utente_a_pagamento(const std::string& ="");
    utente_a_pagamento(const utente&,const std::string& ="");
    std::string get_carta_di_credito() const;
    void set_carta_di_credito(const std::string&);
    virtual void set_costo_annuale(const double&) =0;
    virtual double get_costo_annuale()const =0 ;

    void scrivi_json(QJsonObject &json) const;
};

#endif // UTENTE_A_PAGAMENTO_H

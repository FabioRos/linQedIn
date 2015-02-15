#ifndef UTENTE_EXECUTIVE_H
#define UTENTE_EXECUTIVE_H

#include "utente_a_pagamento.h"

class utente_executive : public utente_a_pagamento{
private:
    static double costo_annuale;
public:
    utente_executive();
    utente_executive(const utente&, const std::string& cc ="");
    utente_executive(const std::string&, const std::string&, const std::string&);
   // utente_executive(const utente&);
    std::list<utente*> cerca(users_repository*,const std::string&) const;
    utente* clona_utente() const;   //virtual
    double get_costo_annuale() const;
    //genero record in json
    void scrivi_json(QJsonObject &json) const;
    void set_costo_annuale(const double &);

};

#endif // UTENTE_EXECUTIVE_H

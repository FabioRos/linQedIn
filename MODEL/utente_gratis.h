#ifndef UTENTE_GRATIS_H
#define UTENTE_GRATIS_H

#include "utente.h"

class utente_gratis : public utente
{
public:
    utente_gratis();
    utente_gratis(const utente&);

    void scrivi_json(QJsonObject &json) const;
};

#endif // UTENTE_GRATIS_H

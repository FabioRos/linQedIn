#ifndef UTENTE_BASIC_H
#define UTENTE_BASIC_H

#include "utente_gratis.h"
class utente_basic:public utente_gratis{
private:

public:
    utente_basic();
    utente_basic( const std::string& n, const std::string& c,
                  const std::string& usn );

    utente_basic(const utente&);
    std::list<utente*> cerca();
    utente* clona_utente() const;   //virtual
    //genero record in json
    void scrivi_json(QJsonObject &json) const;
};

#endif // UTENTE_BASIC_H

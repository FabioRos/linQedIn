#ifndef ATTIVITA_H
#define ATTIVITA_H

#include <string>
#include "data.h"
#include <QJsonObject>

class attivita
{
private:
    std::string luogo;
    std::string descrizione;
    data inizio;
    data fine;
public:
    //non voglio costruttori di default
    explicit attivita( const std::string&,const std::string&, const data&, const data&);

    std::string get_luogo() const;
    std::string get_descrizione() const;
    data get_inizio() const;
    data get_fine() const;

    void update_luogo(const std::string&);
    void update_descrizione(const std::string&);
    void update_inizio(const data&);
    void update_fine(const data&);

    bool operator==(const attivita&);

    virtual void scrivi_json(QJsonObject &json) const;
};



#endif // ATTIVITA_H

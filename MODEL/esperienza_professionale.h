#ifndef ESPERIENZA_PROFESSIONALE_H
#define ESPERIENZA_PROFESSIONALE_H

#include <string>
#include "data.h"
#include "attivita.h"


class esperienza_professionale:public attivita{
private:
    //[luogo, descrizione, inizio, fine] ereditati da attivita
    std::string nome_azienda;
    std::string posizione;

public:
    //non voglio costruttori di default
    explicit esperienza_professionale(const std::string&, const std::string&, const std::string&,
                             const std::string&, const data&, const data&);
    std::string get_nome_azienda() const;
    std::string get_posizione() const;

    void aggiorna_nome_azienda(const std::string&);
    void aggiorna_posizione(const std::string&);

    bool operator==(const esperienza_professionale&);
    bool operator!=(const esperienza_professionale&);

};

#endif // ESPERIENZA_PROFESSIONALE_H

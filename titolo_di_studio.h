#ifndef TITOLO_DI_STUDIO_H
#define TITOLO_DI_STUDIO_H

#include "attivita.h"

class titolo_di_studio:public attivita
{
private:
    std::string ente_erogante;
public:
    //   //[luogo, descrizione, inizio, fine] ereditati da attivita
    /*
        considero il titolo di studio come un'estensione di attività poichè
        tengo conto del periodo che è stato necessario al conseguimento,
    */
    titolo_di_studio(const std::string&, const std::string&, const std::string&,const data&,const data&);
    std::string get_ente_erogante () const;
    void aggiorna_ente_erogante(const std::string& );
};

#endif // TITOLO_DI_STUDIO_H

#ifndef SMART_UTENTE_H
#define SMART_UTENTE_H

#include "utente.h"
class smart_utente
{private:
    utente* ptr_utente;
public:
    smart_utente();
    smart_utente(utente*);
    smart_utente(const smart_utente&);
    ~smart_utente();
    smart_utente& operator=(const smart_utente&);
    void set_ptr_utente(utente*);
    utente* get_ptr_utente() const;
};

#endif // SMART_UTENTE_H

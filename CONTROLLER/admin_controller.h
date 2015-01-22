#ifndef ADMIN_CONTROLLER_H
#define ADMIN_CONTROLLER_H

#include "./MODEL/db.h"
#include "./VIEW/modulo_visualizzazione_utenti.h"

class admin_controller{
private:
    DB* ptr_database;
public:
    admin_controller(DB* db_);
    std::list<smart_utente *> get_model_db();
    void salva_db() const;      //da testare    ~~~~
    DB* carica_db();           //da testare

};

#endif // ADMIN_CONTROLLER_H

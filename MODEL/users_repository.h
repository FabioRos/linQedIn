#ifndef USERS_REPOSITORY_H
#define USERS_REPOSITORY_H

#include "db.h"
#include "input_output.h"


//  [READ ONLY]<<< eccetto menu_amministrazione>>>
class users_repository{     //metodi getter verso il db
friend class menu_amministrazione;  //per avere accesso al puntatore al DB
private:
        DB* ptr_db;
        DB* get_ptr_db() const;
public:
    ~users_repository();
    users_repository(DB* p_db =0);
    smart_utente* get_ptr_smart_utente(const std::string&);
    utente* get_ptr_utente(const std::string&);
    std::list<smart_utente*> get_database() const;   //sola lettura -> const
    void carica_dati(); //carica usando metodo di input_output.h
    int size() const;
    bool empty() const;

};

#endif // USERS_REPOSITORY_H

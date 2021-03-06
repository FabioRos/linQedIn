#ifndef USERS_REPOSITORY_H
#define USERS_REPOSITORY_H

#include "db.h"
#include "input_output.h"


//  [READ ONLY MODE]<<< eccetto menu_amministrazione e aggiungi_modifica_utenti>>>
class users_repository{     //metodi getter verso il db

    friend class menu_amministrazione;  //per avere accesso al puntatore al DB
    friend class amministrazione;
    friend class aggiungi_modifica_utenti;
    friend class admin_controller;

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
    double get_tariffa_business() const;
    double get_tariffa_executive() const;
    void set_tariffa_business(const double&);
    void set_tariffa_executive(const double&);
    bool is_username_valido(const std::string&);

     std::list<utente*> cerca(users_repository*,const std::string&, const int&) const;

};

#endif // USERS_REPOSITORY_H

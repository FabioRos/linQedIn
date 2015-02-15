#ifndef CLIENT_CONTROLLER_H
#define CLIENT_CONTROLLER_H

#include "../MODEL/smart_utente.h"
#include "../MODEL/users_repository.h"

class client_controller{
private:
    users_repository* ptr_repository;
public:
    client_controller(users_repository*);
    bool login_autorizzato(const std::string&) const;
    std::list<std::string> get_info_utente(const std::string&) const;//incompleto
    utente_a_pagamento* isAPagamento(const std::string&) const;
};

#endif // CLIENT_CONTROLLER_H

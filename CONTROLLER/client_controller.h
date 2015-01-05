#ifndef CLIENT_CONTROLLER_H
#define CLIENT_CONTROLLER_H

#include <string>

class client_controller{
public:
    client_controller();
    bool login_autorizzato(const std::string&) const;
};

#endif // CLIENT_CONTROLLER_H

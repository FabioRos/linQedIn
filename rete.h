#ifndef RETE_H
#define RETE_H

#include <map>
#include <string>

class smart_utente; //dichiarazione incompleta per evitare inclusioni circolari

class rete{
private:
    std::map<std::string,smart_utente*> lista;
public:
    rete();
};

#endif // RETE_H

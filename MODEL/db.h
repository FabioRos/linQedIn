#ifndef DB_H
#define DB_H
#include <map>
#include <string>
#include "smart_utente.h"

using std::string;
using std::map;

class DB
{private:
    //map-> la chiave deve avere almeno un operatore per il confronto.
    map<string, smart_utente> database; //string-> username->unique_key, smart_utente value
public:
    DB();
};

#endif // DB_H

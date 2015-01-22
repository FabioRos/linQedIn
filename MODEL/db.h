#ifndef DB_H
#define DB_H
#include <map>
#include <string>
#include <list>
#include "smart_utente.h"


using std::string;
using std::map;

class DB
{private:
    //map-> la chiave deve avere almeno un operatore per il confronto.
    map<std::string, smart_utente*> database; //string-> username->unique_key, smart_utente value
public:
    DB();
    ~DB();
    bool aggiungi_utente(const smart_utente&);
    void rimuovi_utente(const std::string&);
    int size() const;
    smart_utente* get_ptr_smart_utente(const std::string&);
    utente* get_ptr_utente(const std::string&);
    std::list<smart_utente*> get_database() const;   //sola lettura -> const
    bool empty() const;
    void rimuovi_utente_da_tutte_le_reti(const std::string& );  // da testare
    void rimuovi_utente_da_tutte_le_reti(smart_utente*);        // da testare


    std::list<std::string> get_tutte_le_chiavi() const;
};

#endif // DB_H

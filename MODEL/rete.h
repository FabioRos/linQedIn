#ifndef RETE_H
#define RETE_H

#include <map>
#include <string>
#include <list>


class utente;
class smart_utente; //dichiarazioni incomplete per evitare inclusioni circolari->solo rif e punt

class rete{
private:
    std::map<std::string,smart_utente*> lista;
public:
    rete();
    void aggiungi_elemento(const smart_utente&);
    void rimuovi_elemento(const std::string&);
    bool esiste_elemento(const std::string&) const;
    smart_utente* get_ptr_smart_utente(const std::string &);
    utente* get_ptr_utente(const std::string &);
    std::list<utente*> get_all_ptr_utente() const;
    std::list<std::string> get_all_usernames() const;

    bool empty() const;

};

#endif // RETE_H

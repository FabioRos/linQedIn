#include "rete.h"
#include "smart_utente.h"

rete::rete(){
}

void rete::aggiungi_elemento(const smart_utente &s){    //se ptr_utente ==0 ->ecc
    lista.insert (std::pair<std::string,smart_utente*>(s.get_ptr_utente()->get_username(),new smart_utente(s)) );
}

void rete::rimuovi_elemento(const std::string &chiave){
    std::map<std::string,smart_utente*>::iterator it=lista.begin();
    it=lista.find(chiave);
    lista.erase(it);
}

bool rete::esiste_elemento(const std::string &chiave) const{
    std::map<std::string,smart_utente*>::const_iterator it=lista.begin();
    it=lista.find(chiave);
    return (it!=lista.end())?true:false;

}

utente* rete::get_ptr_utente(const std::string &chiave){
    /* find: Searches the container for an element with a key equivalent to k and returns
       an iterator to it if found, otherwise it returns an iterator to map::end.*/
    if(lista.find(chiave)!=lista.end())
        return (lista[chiave])->get_ptr_utente();
    return 0;
}

std::list<utente *> rete::get_all_ptr_utente() const{

     std::list<utente*> elenco;
     for(std::map<std::string,smart_utente*>::const_iterator it=lista.begin();it!=lista.end();++it){
        elenco.push_back((it)->second->get_ptr_utente());
     }
     return elenco;
}

std::list<std::string> rete::get_all_usernames() const{

    std::list<std::string>  usernames;
    std::map<std::string,smart_utente*>::const_iterator it=lista.begin();
      for(;it!=lista.end();++it){
        usernames.push_back(it->first);
      }
      return usernames;

}

bool rete::empty() const{
    return lista.empty();
}

//or(std::map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
//{
//	int key = it->first;
//	int value = it->second;
//	//Do something
//}

smart_utente *rete::get_ptr_smart_utente(const std::string &chiave){
    if(lista.find(chiave)!=lista.end())
        return (lista[chiave]);
    return 0;
}



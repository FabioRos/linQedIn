#include "db.h"

DB::DB(){}

smart_utente *DB::get_ptr_smart_utente(const std::string& username){
    if(database.find(username)!=database.end())
        return (database[username]);
    return 0;
}

utente *DB::get_ptr_utente(const std::string& username){
    return this->get_ptr_smart_utente(username)->get_ptr_utente();
}


std::list<smart_utente*> DB::get_database() const{
    std::list<smart_utente *> db_to_list;
    for(std::map<std::string,smart_utente*>::const_iterator it=database.begin();
        it != database.end(); ++it) {
        db_to_list.push_back(it->second);
    }
    return db_to_list;
}

bool DB::aggiungi_utente(const smart_utente & smart_u){
    if(smart_u.get_ptr_utente()==0) return false;
    database.insert(std::pair<std::string,smart_utente*>(smart_u.get_ptr_utente()->get_username(),new smart_utente(smart_u)));
    return true;
}

void DB::rimuovi_utente(const std::string& username){
    std::map<std::string,smart_utente*>::iterator it=database.begin();
    it=database.find(username);
    database.erase(it);
}

int DB::size() const{
    return database.size();
}

bool DB::empty() const{
    return database.empty();
}

std::list<std::string> DB::get_tutte_le_chiavi() const{
    std::list<std::string>  chiavi;
    std::map<std::string,smart_utente*>::const_iterator it=database.begin();
      for(;it!=database.end();++it){
        chiavi.push_back(it->first);
      }
      return chiavi;
}


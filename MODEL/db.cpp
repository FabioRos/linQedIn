#include "db.h"

DB::DB(){}

DB::~DB(){
    //delete &database;
}

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
    rimuovi_utente_da_tutte_le_reti(username);  //da testare
    database.erase(it);
}

int DB::size() const{
    return database.size();
}

bool DB::empty() const{
    return database.empty();
}

void DB::rimuovi_utente_da_tutte_le_reti(smart_utente * smu){
    for(std::map<std::string,smart_utente*>::iterator it=database.begin();
        it != database.end(); ++it) {
        if(it->second->get_ptr_utente()->esiste_nella_rete(smu->get_ptr_utente()->get_username())){
            it->second->get_ptr_utente()->rimuovi_utente_da_rete(smu);
        }

    }
}

void DB::rimuovi_utente_da_tutte_le_reti(const std::string& s){
    for(std::map<std::string,smart_utente*>::iterator it=database.begin();
        it != database.end(); ++it) {
        if(it->second->get_ptr_utente()->esiste_nella_rete(s)){
            it->second->get_ptr_utente()->rimuovi_utente_da_rete(s);
        }

    }

}

std::list<std::string> DB::get_tutte_le_chiavi() const{
    std::list<std::string>  chiavi;
    std::map<std::string,smart_utente*>::const_iterator it=database.begin();
      for(;it!=database.end();++it){
        chiavi.push_back(it->first);
      }
      return chiavi;
}

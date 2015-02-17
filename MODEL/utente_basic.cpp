//#include "utente_basic.h"
#include "users_repository.h"

utente_basic::utente_basic(){}

utente_basic::utente_basic(const std::string &n, const std::string &c, const std::string &usn)
    :utente_gratis(n,c,usn){}
utente_basic::utente_basic(const utente& u):utente_gratis(u){}
std::list<utente *> utente_basic::cerca(users_repository* ptr_repo, const std::string& s) const{
     return ptr_repo->cerca(ptr_repo,s,1);
    //    std::list<utente*> risultato;
//    std::list<smart_utente*> lista_ptr_smu=ptr_repo->get_database();
//    std::list<smart_utente*>::const_iterator it=lista_ptr_smu.begin();
//    for(;it!=lista_ptr_smu.end();++it){
//        // cerca per username, nome o cognome
//        utente* u=(*it)->get_ptr_utente();
//        if(     (u->get_username().find(s)!=std::string::npos ||
//                u->get_cognome().find(s)!=std::string::npos  ||
//                u->get_nome().find(s)!=std::string::npos)
//                && u!= this)    //per escludere se stesso dai risultati
//            risultato.push_back(u);
//    }

////    s1.find(s2) != std::string::npos
//    return risultato;
}

utente *utente_basic::clona_utente() const{
    return new utente_basic(*this);
}

void utente_basic::scrivi_json(QJsonObject &json) const{
    json["tipo_account"] = QString::fromStdString("basic");
    utente::scrivi_json(json);

}

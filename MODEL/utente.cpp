#include "utente.h"
#include "smart_utente.h"

utente::utente(const std::string & nome_ ,const std::string & cognome_,const std::string & username_)
    :nome(nome_),cognome(cognome_),username(username_){}

utente::utente(const std::string &n, const std::string &c, const std::string &usn,
               const std::list<esperienza_professionale> &e, const std::list<std::string> &com,
               const std::map<std::string, lingua> l, const rete &r)
    :nome(n),cognome(c),username(usn),esperienze_professionali(e),
      competenze(com),lingue(l),rete_(r){}
utente::~utente(){}


std::string utente::get_nome() const{
    return nome;
}
std::string utente::get_cognome() const{
    return cognome;
}
std::string utente::get_username() const{
    return username;
}
std::list<esperienza_professionale> utente::get_esperienze_professionali() const{
    return esperienze_professionali;
}

std::list<std::string> utente::get_esperienze_professionali_txt() const{
    // nome_azienda#posizione#luogo#descrizione#data_inizio#data_fine
    std::list<std::string> risultato;
    if (!esperienze_professionali.empty()){
        std::list<esperienza_professionale>::const_iterator it=esperienze_professionali.begin();
        for(;it!=esperienze_professionali.end();++it){
            std::string s=it->get_nome_azienda();
            s+="#";
            s+=it->get_posizione();
            s+="#";
            s+=it->get_luogo();
            s+="#";
            s+=it->get_descrizione();
            s+="#";
            s+=it->get_inizio().toString();
            s+="#";
            s+=it->get_fine().toString();
            risultato.push_back(s);
        }
    }
    return risultato;
}

std::list<std::string> utente::get_competenze() const{
    return competenze;
}

std::list<std::string> utente::get_lingue() const{ //portare la f() dentro lingua.h/.cpp
    //"lingua#L1#L2#L3"
    std::list<std::string> lista_lingue;
    if (!lingue.empty()){
        std::map<std::string,lingua>::const_iterator it=lingue.begin();
        for(;it!=lingue.end();++it){
            std::string s=(*it).second.get_descrizione();
            s+="#";
            s+=(*it).second.get_livello_comprensione();
            s+="#";
            s+=(*it).second.get_livello_parlato();
            s+="#";
            s+=(*it).second.get_livello_scritto();
            lista_lingue.push_back(s);
            //         std::cout<<s;
        }
    }

    return lista_lingue;
}



void utente::update_nome(const std::string & s){
    nome=s;
}
void utente::update_cognome(const std::string & s){
    cognome=s;
}
void utente::update_username(const std::string & s){
    username=s;
}
void utente::aggiungi_esperienze_professionali(const esperienza_professionale & e){
    esperienze_professionali.push_back(e);
}

void utente::aggiungi_esperienze_professionali(const std::list<esperienza_professionale> &l){
    std::list<esperienza_professionale>::const_iterator it=l.begin();
    for(;it!=l.end();++it){
        esperienze_professionali.push_back(*it);
    }
}


bool utente::rimuovi_esperienze_professionali(const esperienza_professionale & e){
    for(std::list<esperienza_professionale>::iterator it=esperienze_professionali.begin();
        it!=esperienze_professionali.end();++it){
        if(*it==e){
            esperienze_professionali.erase(it);
            return true;
        }

    }
    return false;
}

void utente::aggiungi_lingua(const std::string & d, const std::string &c,
                             const std::string &p, const std::string &s){
    // lingue.push_front(lingua(d,c,p,s));
    lingue.insert(std::pair<std::string,lingua>(d,lingua(d,c,p,s)));

    //lista.insert (std::pair<std::string,smart_utente*>(s.get_ptr_utente()->get_username(),new smart_utente(s)) );
}

void utente::aggiungi_lingua(const lingua &l){
    aggiungi_lingua(l.get_descrizione(),l.get_livello_comprensione(),l.get_livello_parlato(),
                    l.get_livello_scritto());
}

void utente::aggiungi_lingue(const std::list<lingua> &l){
    std::list<lingua>::const_iterator it=l.begin();
    for(;it!=l.end();++it){
        aggiungi_lingua(*it);
    }
}

void utente::rimuovi_lingua(const std::string &chiave){
    std::map<std::string,lingua>::iterator it=lingue.begin();
    it=lingue.find(chiave);
    lingue.erase(it);
}

void utente::rimuovi_tutte_le_lingue(const std::string &){
    std::map<std::string,lingua>::iterator it=lingue.begin();
    for(;it!=lingue.end();++it)
        lingue.erase(it);
}

void utente::rimuovi_tutte_le_esperienze(const std::string &){
        esperienze_professionali.clear();
}

bool utente::esiste_lingua(const std::string &chiave) const{
    std::map<std::string,lingua>::const_iterator it=lingue.begin();
    it=lingue.find(chiave);
    return (it!=lingue.end())?true:false;
}

void utente::aggiungi_competenze(const std::string &s){//controllo univocità, trim
    if(!ha_la_competenza(s))
        competenze.push_front(s);
}

void utente::aggiungi_competenze(const std::list<std::string> &competenze_da_aggiungere){
    std::list<std::string>::const_iterator it=competenze_da_aggiungere.begin();
    for(;it!=competenze_da_aggiungere.end();++it)
        aggiungi_competenze(*it);
}

void utente::rimuovi_competenze(const std::string &s){
    if(ha_la_competenza(s))
        competenze.remove(s);
}

void utente::rimuovi_tutte_le_competenze(){
    if(!competenze.empty()){
        //std::list<std::string>::iterator it=competenze.begin();
        //for(;it!=competenze.end();++it){
            competenze.erase(competenze.begin(),competenze.end());
       // }
   }
}

bool utente::un_pezzo_di_competenza(const std::string & s) const{
    for(std::list<std::string>::const_iterator it=competenze.begin();it!=competenze.end();++it){
        if((*it).find(s)!=std::string::npos){
            return true;
        }
    }
    return false;
}

bool utente::ha_lavorato_nella_posizione(const std::string &s) const{
    for(std::list<esperienza_professionale>::const_iterator it=esperienze_professionali.begin();it!=esperienze_professionali.end();++it){
        if((*it).get_posizione().find(s)!=std::string::npos){
            return true;
        }
    }
    return false;
}

bool utente::ha_lavorato_nella_citta(const std::string &s) const{
    for(std::list<esperienza_professionale>::const_iterator it=esperienze_professionali.begin();it!=esperienze_professionali.end();++it){
        if((*it).get_luogo().find(s)!=std::string::npos){
            return true;
        }
    }
    return false;
}


bool utente::ha_lavorato_nell_azienda(const std::string &s) const{
    for(std::list<esperienza_professionale>::const_iterator it=esperienze_professionali.begin();it!=esperienze_professionali.end();++it){
        if((*it).get_nome_azienda().find(s)!=std::string::npos){
            return true;
        }
    }
    return false;
}

bool utente::ha_la_competenza(const std::string & s) const{
    for(std::list<std::string>::const_iterator it=competenze.begin();it!=competenze.end();++it){
        if((*it).compare(s)==0){
            return true;
        }
    }
    return false;
}


utente *utente::aggiungi_utente_a_rete(smart_utente* smart_u){
    rete_.aggiungi_elemento(*smart_u);
    return smart_u->get_ptr_utente();
}

void *utente::aggiungi_utente_a_rete(const std::string &username, smart_utente *ptr_smu){
    rete_.aggiungi_elemento_via_ptr_smu(username,ptr_smu);
}

utente *utente::rimuovi_utente_da_rete(smart_utente* smart_u){
    rete_.rimuovi_elemento(smart_u->get_ptr_utente()->get_username());
    return smart_u->get_ptr_utente();
}

void utente::rimuovi_utente_da_rete(const std::string &s){
    rete_.rimuovi_elemento(s);
}

void utente::scrivi_json(QJsonObject &json) const{


    json["username"] = QString::fromStdString(username);
    json["nome"] =     QString::fromStdString(nome);
    json["cognome"] =  QString::fromStdString(cognome);


    //*** ESPERIENZE_PROFESSIONALI ***
    QJsonArray array_esperienze;
    //array_esperienze.append("ciao");
    std::list<esperienza_professionale>::const_iterator it= esperienze_professionali.begin();
    for(;it!=esperienze_professionali.end();++it){
        //esperienze_professionali.scrivi_json(json);
        QJsonObject temp;
        it->scrivi_json(temp);
        array_esperienze.append(temp);
    }
    json["esperienze_professionali"]= array_esperienze;

    //*** LINGUE ***
    QJsonArray array_lingue;
    std::map<std::string,lingua>::const_iterator it2= lingue.begin();
    for(;it2!=lingue.end();++it2){
        //esperienze_professionali.scrivi_json(json);
        QJsonObject temp;
        it2->second.scrivi_json(temp);
        array_lingue.append(temp);
    }

    json["lingue"]= array_lingue;

    //*** COMPETENZE ***
    QJsonArray array_competenze;
    std::list<std::string>::const_iterator it_comp=competenze.begin();
    for(;it_comp!=competenze.end();++it_comp){
        array_competenze.append(QString::fromStdString(*it_comp));
    }
    json["competenze"]=array_competenze;

    //*** RETE ***
    QJsonArray array_rete;
    std::list<std::string> usernames=rete_.get_all_usernames();
    std::list<std::string>::const_iterator it_rete=usernames.begin();
    for(;it_rete!=usernames.end();++it_rete){
        //esperienze_professionali.scrivi_json(json);
        array_rete.append(QString::fromStdString(*it_rete));
        // array_rete.append(temp);
    }
    json["rete"]=array_rete;


}

bool utente::esiste_nella_rete(const std::string &username) const{
    return rete_.esiste_elemento(username);
}

//utente *utente::operator=(utente *u){
//    cognome=u->cognome;
//    nome=u->nome;
//    username=u->username;
//    competenze=u->competenze;
//    esperienze_professionali=u->esperienze_professionali;
//    lingue=u->lingue;
//    rete_=u->rete_;
//}

std::list<utente*> utente::get_all_rete() const{
    return rete_.get_all_ptr_utente();
}


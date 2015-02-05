#include "lingua.h"

std::string lingua::livelli[6]= {"A1","A2","B1","B2","C1","C2"};



lingua::lingua(const std::string & d, const std::string & c, const std::string & p, const std::string & s)
    :descrizione(d),livello_comprensione(c),livello_parlato(p),livello_scritto(s){
    //verifica conformità c,p,s
}

std::string lingua::get_descrizione() const{
    return descrizione;
}

std::string lingua::get_livello_comprensione() const{
    return livello_comprensione;
}

std::string lingua::get_livello_parlato() const{
    return livello_parlato;
}

std::string lingua::get_livello_scritto() const{
    return livello_scritto;
}

void lingua::set_descrizione(const std::string& s){
   descrizione=s;
}

void lingua::set_livello_comprensione(const std::string& s){
   livello_comprensione=s;
}

void lingua::set_livello_parlato(const std::string& s){
    livello_parlato=s;
}

void lingua::set_livello_scritto(const std::string& s){
    livello_scritto=s;
}

bool lingua::sanitize(const lingua &l){
    if( l.get_descrizione()!="" &&
       (l.get_livello_comprensione()=="A1"   || l.get_livello_comprensione()=="A2"  ||
        l.get_livello_comprensione()=="B1"   || l.get_livello_comprensione()=="B2"  ||
        l.get_livello_comprensione()=="C1"   || l.get_livello_comprensione()=="C2"
        ) &&
       (l.get_livello_parlato()=="A1"        || l.get_livello_parlato()=="A2"       ||
        l.get_livello_parlato()=="B1"        || l.get_livello_parlato()=="B2"       ||
        l.get_livello_parlato()=="C1"        || l.get_livello_parlato()=="C2"
        ) &&
       (l.get_livello_scritto()=="A1"        || l.get_livello_scritto()=="A2"       ||
        l.get_livello_scritto()=="B1"        || l.get_livello_scritto()=="B2"       ||
        l.get_livello_scritto()=="C1"        || l.get_livello_scritto()=="C2"
        )
      )
        return true;
    else
        return false;
}

void lingua::scrivi_json(QJsonObject &json) const{
    json["descrizione"]         =  QString::fromStdString(descrizione);
    json["livello_scritto"]     =  QString::fromStdString(livello_scritto);
    json["livello_parlato"]     =  QString::fromStdString(livello_parlato);
    json["livello_comprensione"]=  QString::fromStdString(livello_comprensione);
}

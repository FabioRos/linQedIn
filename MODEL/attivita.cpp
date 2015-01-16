#include "attivita.h"

attivita::attivita(const std::string & l, const std::string & d, const data & i, const data & f)
    :luogo(l),descrizione(d),inizio(i),fine(f){}




std::string attivita::get_luogo() const{
    return luogo;
}

std::string attivita::get_descrizione() const{
    return descrizione;
}

data attivita::get_inizio() const{
    return inizio;
}

data attivita::get_fine() const{
    return fine;
}

void attivita::update_luogo(const std::string& s){
    luogo=s;
}

void attivita::update_descrizione(const std::string& s){
    descrizione=s;
}

void attivita::update_inizio(const data & d){
    inizio=d;
}

void attivita::update_fine(const data & d){
    fine=d;
}

bool attivita::operator==(const attivita & a){
    return (luogo==a.get_luogo() && descrizione==a.get_descrizione() &&
            inizio==a.get_inizio() && fine==a.get_fine());
}

void attivita::scrivi_json(QJsonObject &json) const{
    json["luogo"]       =  QString::fromStdString(luogo);
    json["descrizione"] =  QString::fromStdString(descrizione);
    json["inizio"]      =  QString::fromStdString(inizio.toString());
    json["fine"]        =  QString::fromStdString(fine.toString());
    //mancano date
}

#include "input_output.h"
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonArray>


//std::string input_output::file_path ="/home/fabio/Development/C++/PaO_2014_15/LinQedIn/LinQedIn/PERSISTENT/database.json";

input_output::input_output(){
}

bool input_output::carica_da_file(){
    return true;
}

bool input_output::salva_su_file(DB* ptr_db_locale_corrente){
    std::list<smart_utente*> database=ptr_db_locale_corrente->get_database();

    //serializza db

    //scrivo sul file
    //smart_utente* s=ptr_db_locale_corrente->get_ptr_smart_utente("FabioRos90");
    //void saveJson(QJsonDocument document, QString fileName) {



    QFile output_file(file_path);
        output_file.open(QFile::WriteOnly);

        //metto una lista con solo gli usename cosi
        // nel caricamento creerò la mappa con tutti gli username
        // giusti e 0 sul campo ptr_utente degli smart_utenti in modo da
        // non avere problemi nel referenziare nella rete utenti non ancora esistenti

        //USERNAMES
        QJsonArray array_usernames;
        array_usernames=elenco_username(ptr_db_locale_corrente->get_tutte_le_chiavi());

        //UTENTI
        QJsonObject db_testuale;
        QJsonArray array_utenti;
        array_utenti=serializza_db(database);


        //aggiungo al file
        db_testuale["usernames"]=array_usernames;
        db_testuale["utenti"]=array_utenti;
        QJsonDocument doc(db_testuale);

        output_file.write(doc.toJson());
    return true;
}

void input_output::scrivi_un_utente(smart_utente *ptr_smu, QJsonObject &json_obj){
    ptr_smu->get_ptr_utente()->scrivi_json(json_obj);
}

QJsonArray input_output::elenco_username(std::list<std::string> lista) const {
    QJsonArray elenco;

    std::list<std::string>::const_iterator it=lista.begin();
    for(;it!=lista.end();++it){

        elenco.append(QString::fromStdString((*it)));
    }
    return elenco;

}

QJsonArray input_output::serializza_db(const std::list<smart_utente*>& database_) const{
    //genero sottoforma di stringa in contenuto da scrivere sul file json
    QJsonArray utenti;


    for(std::list<smart_utente*>::const_iterator it=database_.begin();it!=database_.end();++it){
        QJsonObject temp;
        (*it)->get_ptr_utente()->scrivi_json(temp);
        utenti.append(temp);
    }
    return utenti;

}

std::string input_output::get_file_path() const{
    return file_path;
}

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
    smart_utente* s=ptr_db_locale_corrente->get_ptr_smart_utente("FabioRos90");
    //void saveJson(QJsonDocument document, QString fileName) {



    QFile output_file(file_path);
        output_file.open(QFile::WriteOnly);

        //temp

//        QJsonObject nuovo_utente;
//        scrivi_un_utente(s,nuovo_utente);

//        QJsonDocument doc(nuovo_utente);

        QJsonObject db_testuale;
        QJsonArray array_utenti;
        array_utenti=serializza_db(database);
        db_testuale["utenti"]=array_utenti;
        QJsonDocument doc(db_testuale);



        /*
         *
        QJsonObject db_testuale(QString::fromStdString(serializza_db(database)));
        QJsonDocument doc(db_testuale);

         *
         * */

        output_file.write(doc.toJson());
    //}
    return true;
}

void input_output::scrivi_un_utente(smart_utente *ptr_smu, QJsonObject &json_obj)
{
    ptr_smu->get_ptr_utente()->scrivi_json(json_obj);
//    if(ptr_smu!=0){
//        json_obj["username"] =ptr_smu->get_ptr_utente()->get_username();
//        json_obj["cognome"] = ptr_smu->get_ptr_utente()->get_cognome();
//        json_obj["nome"] = ptr_smu->get_ptr_utente()->get_nome();
////        //jsonObj["id"] = this->id();
//        }
}

QJsonArray input_output::serializza_db(const std::list<smart_utente*>& database_) const{
    //genero sottoforma di stringa in contenuto da scrivere sul file json
    QJsonObject oggetto;
    QJsonArray utenti;


    for(std::list<smart_utente*>::const_iterator it=database_.begin();it!=database_.end();++it){
        QJsonObject temp;
        (*it)->get_ptr_utente()->scrivi_json(temp);
        utenti.append(temp);
       // array_esperienze.append(temp);
    }
    return utenti;

}

std::string input_output::get_file_path() const{
    return file_path;
}

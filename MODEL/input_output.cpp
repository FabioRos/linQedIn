#include "input_output.h"



input_output::input_output(){
}

DB* input_output::carica_da_file(){
    QFile input_file(file_path);
    input_file.open(QIODevice::ReadOnly | QIODevice::Text);

    //contenuto testuale contiene in plain_text il contenuto del file
    QString contenuto_testuale = input_file.readAll();
    input_file.close();

    //doc contiene il file con la lente di un file json
    QJsonDocument doc = QJsonDocument::fromJson(contenuto_testuale.toUtf8());

    //estraggo l'oggetto radice che contiene tutto
    QJsonObject oggetto_root= doc.object();

    //mi prendo l'array usernames
    QJsonArray usernames = oggetto_root.value("usernames").toArray();

    //ora quello degli utenti
    QJsonArray utenti = oggetto_root.value("utenti").toArray();


    // creo una tutti gli smartutenti con campo ptr_utente=0 (valore di default)
    // e li metto in una mappa con gli username
    std::map<std::string,smart_utente*> tutti_gli_smart_utenti;

    int numero_utenti=usernames.size();
    for (int i=0;i<numero_utenti;i++){
        tutti_gli_smart_utenti.insert (std::pair<std::string,smart_utente*>(usernames[i].toString().toStdString(),new smart_utente()));
    }//toString-> QString, poi uso QString::toStdString

    //ora ho tutti gli smart_utenti

    //creo gli utenti stando tranquillo per la rete
    DB* db_da_file=new DB();
    for (int i=0;i<numero_utenti;i++){
        //mi creo un oggetto di tipo QJsonObject a partire dalla stringa
        QJsonObject oggetto_utente_corrente(utenti[i].toObject());
        std::string j_username =oggetto_utente_corrente.value("username").toString().toStdString();
        std::string j_nome =oggetto_utente_corrente.value("nome").toString().toStdString();
        std::string j_cognome =oggetto_utente_corrente.value("cognome").toString().toStdString();
        std::string j_tipo_account =oggetto_utente_corrente.value("tipo_account").toString().toStdString();

        utente* u;
        //riconoscimento tipo DA FARE
        if(j_tipo_account=="basic"){
            u= new utente_basic(j_nome,j_cognome,j_username);
            u=static_cast<utente_basic*>(u);
        } else if(j_tipo_account=="business"){
            u= new utente_business(j_nome,j_cognome,j_username);
            u=static_cast<utente_business*>(u);
        } else if(j_tipo_account=="executive"){
            u= new utente_executive(j_nome,j_cognome,j_username);
            u=static_cast<utente_executive*>(u);
        }

        //competenze
       QJsonArray competenze = oggetto_utente_corrente.value("competenze").toArray();
       for (int i=0;i<competenze.size();i++){
            //std::cout<<competenze[i].toString().toStdString(); //ok
           u->aggiungi_competenze(competenze[i].toString().toStdString());
       }

       //lingue
       QJsonArray lingue = oggetto_utente_corrente.value("lingue").toArray();
       for (int i=0;i<lingue.size();i++){//dentro ad una lingua
            QJsonObject oggetto_innestato_lingua = lingue[i].toObject();
            std::string jdescrizione=oggetto_innestato_lingua.value("descrizione").toString().toStdString();
            std::string jcomprensione = oggetto_innestato_lingua.value("livello_comprensione").toString().toStdString();
            std::string jscritto =oggetto_innestato_lingua.value("livello_scritto").toString().toStdString();
            std::string jparlato =oggetto_innestato_lingua.value("livello_parlato").toString().toStdString();
            u->aggiungi_lingua(jdescrizione,jcomprensione,jparlato,jscritto);
           // std::cout<<"jdescrizione:"<<jdescrizione<<", jcomprensione:"<<jcomprensione; //ok
           // std::cout<<", jparlato:"<<jparlato<<", jscritto:"<<jscritto<<std::endl;
       }//se non c'è nessuna lingua non entra neanche nel ciclo e quindo non fa mai costruzioni
        //con valori sballati


       //esperienze_professionali
        QJsonArray esp = oggetto_utente_corrente.value("esperienze_professionali").toArray();
        for (int i=0;i<esp.size();i++){//dentro ad una lingua
             QJsonObject oggetto_innestato_esp = esp[i].toObject();
             std::string jdescrizione = oggetto_innestato_esp.value("descrizione").toString().toStdString();
             std::string jinizio = oggetto_innestato_esp.value("inizio").toString().toStdString();
             std::string jfine = oggetto_innestato_esp.value("fine").toString().toStdString();
             std::string jluogo = oggetto_innestato_esp.value("luogo").toString().toStdString();
             std::string jnome_azienda = oggetto_innestato_esp.value("nome_azienda").toString().toStdString();
             std::string jposizione = oggetto_innestato_esp.value("posizione").toString().toStdString();
             data j__data_inizio = data::converti_da_string(jinizio);
             data j__data_fine = data::converti_da_string(jfine);

             u->aggiungi_esperienze_professionali(
                         esperienza_professionale(jnome_azienda,jposizione,jluogo,
                            jdescrizione,j__data_inizio,j__data_fine));

        }


        //Rete
        QJsonArray array_rete = oggetto_utente_corrente.value("rete").toArray();
        //per tutti i contatti che ho nella mia rete:
        for (int i=0;i<array_rete.size();i++){
            //mi prendo l'username associato
            std::string username_contatto=array_rete[i].toString().toStdString();
            //prendo lo smart_utente dalla collezione che ho generato prima
            smart_utente* smu_di_questo_utente = tutti_gli_smart_utenti.find(username_contatto)->second;
            //e lo uso per aggiungere quell'utente alla rete.
            u->aggiungi_utente_a_rete(username_contatto,smu_di_questo_utente);
            //u->aggiungi_utente_a_rete(smu_di_questo_utente);    // da testare
        }

        //aggiorno il puntatore nello smart_utente da 0 a questo utente
       // smart_utente* tmp_ptr_smu= tutti_gli_smart_utenti.find(j_username)->second=new smart_utente(u);
       // db_da_file->aggiungi_utente(*tmp_ptr_smu);
        tutti_gli_smart_utenti.find(j_username)->second->set_ptr_utente(u);
        db_da_file->aggiungi_utente(*(tutti_gli_smart_utenti.find(j_username)->second));


    }// foreach-utenti _END_

    input_file.close();
    return db_da_file;
}

bool input_output::salva_su_file(DB* ptr_db_locale_corrente){
    std::list<smart_utente*> database=ptr_db_locale_corrente->get_database();
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
        output_file.close();
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

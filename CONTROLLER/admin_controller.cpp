#include "admin_controller.h"


admin_controller::admin_controller(DB* ptr_db):ptr_database(ptr_db){}

admin_controller::admin_controller(users_repository * db_)
    :ptr_database(db_->get_ptr_db()){}

std::list<smart_utente*> admin_controller::get_model_db(){
    return ptr_database->get_database();
}

void admin_controller::salva_db_senza_conferma() const{
    input_output io;
    io.salva_su_file(ptr_database);
}

void admin_controller::salva_db() const{
    input_output io;
    io.salva_su_file(ptr_database);

    info_salvataggio_eseguito();

//    //delay 3 secondi
//    while( QTime::currentTime() < QTime::currentTime().addSecs(3) )
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

DB* admin_controller::carica_db(){
    return input_output::carica_da_file();
}

void admin_controller::rimuovi_utenti(const std::list<std::string> &lista){
    std::list<std::string>::const_iterator it=lista.begin();
    for(;it!=lista.end();++it){
        ptr_database->rimuovi_utente(*it);
    }
}

void admin_controller::info_salvataggio_eseguito() const{
    QLabel *mbox = new QLabel("<b><center>Salvataggio eseguito con successo.</center></b>");
    mbox->setStyleSheet("color:green;");
    mbox->setGeometry(320,320,350,50);

    mbox->show();
}






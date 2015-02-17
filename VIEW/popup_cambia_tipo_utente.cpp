#include "popup_cambia_tipo_utente.h"

popup_cambia_tipo_utente::popup_cambia_tipo_utente(const std::string& usn,
              users_repository* ptr_repo, QWidget *parent) :
              username(usn),ptr_repository(ptr_repo),QWidget(parent){


   this->setWindowIcon(QIcon("popup_icon.png"));
   combo_tipo=new QComboBox(this);
   tipi_account << "BASIC" << "BUSINESS" << "EXECUTIVE";
   combo_tipo->addItems(tipi_account);
   btn_annulla=new QPushButton("annulla");
   btn_conferma=new QPushButton("conferma");
   nuovo_tipo="BASIC";
   layout=new QVBoxLayout(this);
   QString s="<center><i> Cambia tipo all'utente:</i><br />\"";
   s.append(QString::fromStdString(username));
   s.append("\"< br /></center>");
   layout->addWidget(new QLabel(s));
   layout->addWidget(combo_tipo);
   layout_bottoni= new QHBoxLayout;
   layout_bottoni->addWidget(btn_annulla);
   layout_bottoni->addWidget(btn_conferma);
   layout->addLayout(layout_bottoni);




   //connessioni
   connect(combo_tipo,SIGNAL(currentTextChanged(QString)),this,SLOT(aggiorna_tipo(QString)));
   connect(btn_conferma,SIGNAL(clicked()),this,SLOT(cambia_tipo()));
   connect(btn_annulla,SIGNAL(clicked()),this,SLOT(close()));
   }

void popup_cambia_tipo_utente::aggiorna_tipo(QString t){
    nuovo_tipo=t.toStdString();
}

void popup_cambia_tipo_utente::cambia_tipo(){
    //nome utente e tipo arrivano corretti
    aggiungi_modifica_utenti* controller=new aggiungi_modifica_utenti(ptr_repository);
    controller->cambia_tipo_utente(ptr_repository->get_ptr_smart_utente(username),nuovo_tipo);
    //la carta di credito se la mette lui
}

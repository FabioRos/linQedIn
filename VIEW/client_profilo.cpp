#include "client_profilo.h"
#include "./CONTROLLER/client_controller.h"
#include <QLayoutItem>


#include <iostream>


client_profilo::client_profilo(users_repository* repo, const std::string& user, QWidget *parent) :
    QWidget(parent), ptr_repository(repo), username_(user){
    btn_modifica_profilo =new QPushButton("Modifica Profilo");
    btn_salva_modifiche= new QPushButton("Salva modifiche");
    layout_top=new QGridLayout(this);
    nome=new QLineEdit("");
    cognome=new QLineEdit("");
    username=new QLineEdit("");
    lbl_tipo_account=new QLabel("Tipo Account: ");
    tipo_account=new QLabel();
    lbl_username=new QLabel("Username: ");
    lbl_cognome=new QLabel("Cognome: ");
    lbl_nome=new QLabel("Nome: ");
    lbl_competenze=new QLabel("Competenze: ");

    layout_top->addWidget(lbl_nome,0,0);
    layout_top->addWidget(nome,0,1);
    layout_top->addWidget(lbl_cognome,1,0);
    layout_top->addWidget(cognome,1,1);
    layout_top->addWidget(lbl_username,2,0);
    layout_top->addWidget(username,2,1);
    layout_top->addWidget(btn_modifica_profilo,0,3);
    layout_top->addWidget(lbl_tipo_account,3,0);
    layout_top->addWidget(tipo_account,3,1);
    layout_top->addWidget(lbl_competenze,4,0);
    //di default diabilitati, li abilito per la modifica.
    disabilita_tutto();

    //popolo i Widgets
    client_controller* c_controller= new client_controller(ptr_repository);

    std::list<std::string> user_data = c_controller->get_info_utente(username_);
    std::list<std::string>::const_iterator it=user_data.begin();
    if(it!=user_data.end()) {
        //*it := tipo account
        tipo_account->setText(QString::fromStdString(*it));
    }
    ++it;
    if(it!=user_data.end()) {
        //username
        username->setText(QString::fromStdString(*it));
    }
    ++it;
    if(it!=user_data.end()) {
        //cognome
        cognome->setText(QString::fromStdString(*it));
    }
    ++it;
    if(it!=user_data.end()) {
        //nome
        nome->setText(QString::fromStdString(*it));
    }
    ++it;
    riga_inizio_competenze=4;
    int indice_riga=4;
    if(it!=user_data.end()) {
        //competenze
        numero_competenze=0;
        int indice_colonna=0;
        for(;it!=user_data.end() && *it != "#fine_competenze#";++it){
            numero_competenze++;    // mi serve per il calcolo degli indici
            QLineEdit* item= new QLineEdit(QString::fromStdString(*it));
            item->setDisabled(true);
            indice_colonna++;
            if(indice_colonna%4==0){
                indice_riga++;
                indice_colonna++;   //così ne metto sempre 3 lasciando il primo posto libero.
            }
            layout_top->addWidget(item,indice_riga,indice_colonna%4);
        }
    }

    //qui devo inserire dalla riga "indice_riga+1"






    //connessioni
    connect(btn_modifica_profilo,SIGNAL(clicked()),this,SLOT(abilita_modifiche()));
    connect(btn_salva_modifiche,SIGNAL(clicked()),this,SLOT(salva_modifiche()));
}

void client_profilo::abilita_modifiche(){
    abilita_tutto();
    btn_modifica_profilo->hide();
    btn_salva_modifiche->show();
    layout_top->removeWidget(btn_modifica_profilo);
    layout_top->addWidget(btn_salva_modifiche,0,3);
}

void client_profilo::salva_modifiche(){
    disabilita_tutto();
    btn_modifica_profilo->show();
    btn_salva_modifiche->hide();
    //salva
    layout_top->removeWidget(btn_salva_modifiche);
    layout_top->addWidget(btn_modifica_profilo,0,3);

}


void client_profilo::disabilita_tutto(){    //eccetto tasto btn_modifica_profilo
    nome->setDisabled(true);
    cognome->setDisabled(true);;
    username->setDisabled(true);
    //competenze
    disabilita_competenze(true);


}

void client_profilo::abilita_tutto(){
    nome->setDisabled(false);
    cognome->setDisabled(false);
    username->setDisabled(false);
    //competenze
    disabilita_competenze(false);


    //layout_top->itemAtPosition(r,c)
}

void client_profilo::disabilita_competenze(const bool &value){
    //per recuperare i widgets mi conviene usare
    //"QLayoutItem * QGridLayout::itemAtPosition ( int row, int column ) const"
    int r=riga_inizio_competenze;

    /*
        algoritmo:
            es r=4:, numero_competenze=8
            mi servono: (4,1),(4,2),(4,3),(5,1),(5,2),(5,3),(6,1),(6,2)
    */
    int numero_iterazioni=numero_competenze+static_cast<int>(numero_competenze/4+1);
    bool prima_volta=true;
    for(int i=0;i<numero_iterazioni;i++){
        if(i%4==0){
            if(!prima_volta)
                r+=1;
            else
                prima_volta=false;
        }else{
        //!!MODO PER PRENDERSI WIDGETS ANONIMI DAL LAYOUT!!
            std::cout<<"("<<r<<","<<i%4<<")   ";
            layout_top->itemAtPosition(r,i%4)->widget()->setDisabled(value);
        }
    }
}

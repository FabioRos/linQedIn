#include "tool_bar.h"
#include <QApplication>
#include <QTime>

tool_bar::tool_bar(users_repository* repo, QWidget *parent) :
    QWidget(parent){
    controller=new admin_controller(repo);
    btn_exit=new QPushButton("Esci",this);

    layout_toolbar=new QHBoxLayout(this);
    layout_toolbar->addWidget(btn_exit);


    //per il bottone esci
    connect(btn_exit,SIGNAL(clicked()),parent,SLOT(close()));
    //per gestire le shortcut
    connect(qApp,SIGNAL(aboutToQuit()),this,SLOT(chiudi()));
}

tool_bar::~tool_bar(){
    delete controller;
    delete btn_exit;
    delete layout_toolbar;
}

void tool_bar::chiudi(){
    QMessageBox::StandardButton scelta;
    scelta= QMessageBox::information(this,"Attenzione","Stai uscendo dal programma. \n Vuoi salvare il tuo lavoro?",QMessageBox::Yes,QMessageBox::No);
    if (scelta == QMessageBox::Yes) {
       controller->salva_db_senza_conferma();
     }
     //a prescindere dalla scelta poi chiudo l'applicazione.
     QApplication::quit();
}

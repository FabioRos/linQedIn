#include "menu_bar.h"
#include "login.h"
#include "finestraprincipale.h"
#include <qapplication.h>    //per qApp, puntatore statico all'applicazione up.
#include <QDebug>
menu_bar::menu_bar(QWidget *parent):QWidget(parent){

    //Inizializzazione campi dati
    btn_profilo=new QPushButton("Profilo",this);
    btn_rete=new QPushButton("Rete",this);
    btn_log_out=new QPushButton("Log-out",this);
    btn_cerca=new QPushButton("Cerca",this);
    btn_exit=new QPushButton("Esci",this);
    //sicuro_uscire=new QMessageBox(this);


    //istanzio il layout
    layout_menu=new QVBoxLayout(this);

    //aggiungo i widgets al layout
    layout_menu->addWidget(btn_profilo);
    layout_menu->addWidget(btn_rete);
    layout_menu->addWidget(btn_log_out);
    layout_menu->addWidget(btn_cerca);
    layout_menu->addWidget(btn_exit);

    //faccio le connessioni


    //connect(btn_exit,SIGNAL(clicked()),sicuro_uscire,SLOT(show()));
    //connect(btn_exit,SIGNAL(clicked()),qApp,SLOT(quit()));
    connect(btn_exit,SIGNAL(clicked()),this,SLOT(chiudi()));
    connect(btn_log_out,SIGNAL(clicked()),this,SLOT(log_out()));
}

void menu_bar::log_out(){
    this->hide();
    login* login_view=new login(static_cast<QWidget*>(parent()));
    login_view->show();
}

void menu_bar::chiudi(){

//    QMessageBox* sicuro_uscire=new QMessageBox(this);
//    sicuro_uscire->setWindowTitle("Attenzione");

//    //configurazione MessageBox
//    sicuro_uscire->setInformativeText("Stai uscrndo dal programma. \n Vuoi salvare il tuo lavoro?");
//    sicuro_uscire->setStandardButtons(QMessageBox::Yes | QMessageBox::No);

    QMessageBox::StandardButton scelta;
    scelta= QMessageBox::information(this,"Attenzione","Stai uscendo dal programma. \n Vuoi salvare il tuo lavoro?",QMessageBox::Yes,QMessageBox::No);


     if (scelta == QMessageBox::Yes) {
       //qDebug() << "[YES]";

     } /*else {
       //qDebug() << "[NO]";
     }*/
     //a prescindere dalla scelta poi chiudo l'applicazione.
     QApplication::quit();
}




#include "tool_bar.h"
#include <QApplication>

tool_bar::tool_bar(QWidget *parent) :
    QWidget(parent){
    btn_exit=new QPushButton("Esci",this);

    layout_toolbar=new QHBoxLayout(this);
    layout_toolbar->addWidget(btn_exit);


    connect(btn_exit,SIGNAL(clicked()),this,SLOT(chiudi()));
    //connect(qApp,SIGNAL(aboutToQuit()),this,SLOT(chiudi()));
}

void tool_bar::chiudi(){

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

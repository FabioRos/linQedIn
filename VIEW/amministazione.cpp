#include "amministazione.h"

amministazione::amministazione(QWidget *parent):QWidget(parent){
    btn1=new QPushButton("carica",this);
    btn2=new QPushButton("salva",this);
    exit= new QPushButton(tr("exit"),this);
    layout=new QHBoxLayout(this);
    layout->addWidget(btn1);
    layout->addWidget(btn2);
    layout->addWidget(exit);
    this->setGeometry(50,50,800,600);
    //connessioni
    connect(exit,SIGNAL(clicked()),this,SLOT(close()));

    //messageBox
    sicuro_caricare=new QMessageBox;
    sicuro_salvare=new QErrorMessage;
    sicuro_caricare->setText("Sei sicuro di voler caricare?");//domanda
    sicuro_caricare->setWindowTitle("Attenzione");
    sicuro_caricare->setInformativeText("Se premi annulla il DB non verrà modificato");
    sicuro_caricare->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    connect(btn1,SIGNAL(clicked()),sicuro_caricare,SLOT(show()));//devo mandare un segnale a icuro_caricare di mostrarsi
    //connect(btn2,SIGNAL(clicked()),sicuro_salvare,SLOT(showMessage("Sovrascriverai il DB")));
}

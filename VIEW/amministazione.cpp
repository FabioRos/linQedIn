#include "amministazione.h"

amministazione::amministazione(QWidget *parent):QWidget(parent){
    //IMPOSTAZIONI FINESTRA
    this->setWindowTitle("Pannello Amministrazione");

    main_layout=new QVBoxLayout(this);
    QWidget* menu=new QWidget;


    //per fare la/e colonna/e di destra, basta aggiungere un widget e metterci dentro le cose

    //  I/O + EXIT _BEGIN           --> meglio portare fuori, in un altra classe
    btn1=new QPushButton("carica",menu);
    btn2=new QPushButton("salva",menu);
    exit= new QPushButton("chiudi finestra",menu);
    layout_I_O=new QHBoxLayout(menu);
    layout_I_O->addWidget(btn1);
    layout_I_O->addWidget(btn2);

    this->setGeometry(100,30,300,600);
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

    //  I/O + EXIT _END


    // menu opzioni

    pannello_opzioni=new menu_amministrazione(this);

    //Aggiungo effettivamente i widget
    main_layout->addWidget(pannello_opzioni);   //sopra
    main_layout->addWidget(menu);               //sotto
    main_layout->addWidget(exit);
}

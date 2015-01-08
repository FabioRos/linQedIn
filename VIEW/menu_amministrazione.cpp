#include "menu_amministrazione.h"
#include <QVBoxLayout>
menu_amministrazione::menu_amministrazione(QWidget *parent):QWidget(parent){

    //ISTANZIO MEMBRI
    btn_aggiungi_utente=new QPushButton("Aggiungi utente",this);
    btn_cambia_account=new QPushButton("Cambia tipo utente",this);
    btn_cerca=new QPushButton("Cerca",this);
    btn_dump_db=new QPushButton("Visualizza utenti",this);
    btn_rimuovi_utente=new QPushButton("Rimuovi utenti",this);



    main_menu_layout=new QVBoxLayout;

    QWidget* menu=new QWidget;


    //per fare la/e colonna/e di destra, basta aggiungere un widget e metterci dentro le cose

    //  I/O + EXIT _BEGIN           --> meglio portare fuori, in un altra classe
    btn1=new QPushButton("carica",menu);
    btn2=new QPushButton("salva",menu);
    //exit= new QPushButton("chiudi finestra",menu);
    layout_I_O=new QHBoxLayout(menu);
    layout_I_O->addWidget(btn1);
    layout_I_O->addWidget(btn2);

    //connessioni
    //connect(exit,SIGNAL(clicked()),this,SLOT(close()));

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

    QVBoxLayout* local_menu_layout=new QVBoxLayout(this);
    local_menu_layout->addWidget(btn_aggiungi_utente);
    local_menu_layout->addWidget(btn_rimuovi_utente);
    local_menu_layout->addWidget(btn_cambia_account);
    local_menu_layout->addWidget(btn_cerca);
    local_menu_layout->addWidget(btn_dump_db);
    local_menu_layout->addWidget(menu);
    //local_menu_layout->addWidget(exit);
    setLayout(local_menu_layout);


}

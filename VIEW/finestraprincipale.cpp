#include "finestraprincipale.h"

FinestraPrincipale::FinestraPrincipale(QWidget *parent) : QMainWindow(parent){

    this->setWindowTitle("Emulatore Browser Client");

    emulatore_browser=new QTabWidget(this);
    setCentralWidget(emulatore_browser);
    //layout_browser=new QHBoxLayout(this);

    //FINESTRE ESTERNE
    amministazione* view_amministrazione= new amministazione;
    //view_amministrazione->show();
    testing* view_testing=new testing;
    view_testing->show();
    this->setGeometry(100,30,850,600);


    view_client=new client_manager(emulatore_browser);
    emulatore_browser->addTab(view_amministrazione, "Amministrazione");
    emulatore_browser->addTab(view_client,"Client");

  }

FinestraPrincipale::~FinestraPrincipale(){}


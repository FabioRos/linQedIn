#include "finestraprincipale.h"
#include <QApplication>
#include <QMessageBox>
#include <QVBoxLayout>

FinestraPrincipale::FinestraPrincipale(bool test_mode, QWidget *parent) : QMainWindow(parent){
    //this->showFullScreen();
    this->setWindowTitle("Emulatore Browser");

    //FINESTRE ESTERNE
    if (test_mode){
        testing* view_testing=new testing(0);
        view_testing->show();
    }

    contenitore=new QWidget(this);
    tab_pricipale=new Tab_wrapper(this);
    tb=new tool_bar(this);
    this->setGeometry(50,30,800,600);
    layout_verticale=new QVBoxLayout;
    layout_verticale->addWidget(tab_pricipale);
    layout_verticale->addWidget(tb);
    layout_verticale->setStretch(0, 10); //tab_widget è grande 10 volte il tasto esci per VLayout
    //tab_pricipale->show();
    //tb->show();
    //layout_verticale=new QVBoxLayout(contenitore);
    //layout_verticale->addWidget(tab_pricipale);
    //layout_verticale->addWidget(tb);

    contenitore->setLayout(layout_verticale);
    setCentralWidget(contenitore);

  }

FinestraPrincipale::~FinestraPrincipale(){}


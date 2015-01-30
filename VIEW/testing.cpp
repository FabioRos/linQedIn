#include "./testing.h"
#include "./TEST/test_manager.h"

testing::testing(QWidget *parent):QWidget(parent){
    layout=new QVBoxLayout(this);

    chiudi_finestra=new QPushButton("chiudi finestra",this);

    esito_testuale=new QLabel(this);
    esito_testuale->setStyleSheet("QLabel {color : white;}");
    this->setWindowTitle("Stato Test");
    this->setGeometry(990,30,300,600);

    run_tests();

    //connessioni
    connect(chiudi_finestra,SIGNAL(clicked()),this,SLOT(close()));
}

testing::~testing(){
    delete layout;
    delete chiudi_finestra;
    delete esito_testuale;
}

void testing::run_tests(){
     test_manager* tester=new test_manager;
     bool tutto_bene=tester->run_tests();
            if(tutto_bene){
        esito_testuale->setStyleSheet("background-color:green;font-weight:bold;color:white;padding:15px");    // CSS
        esito_testuale->setText("Tutti i test sono Passati");
        layout->addWidget(esito_testuale);
    }else{
        esito_testuale->setStyleSheet("background-color:red;font-weight:bold;color:white;padding:15px");
        esito_testuale->setText("Il codice non ha superato la fase di test,\n guardare l'output su terminale \nper maggiori informazioni.");
        layout->addWidget(esito_testuale);
    }
     //chiudi_finestra->setAutoFillBackground(true);
     layout->addWidget(chiudi_finestra);
     delete tester;
}

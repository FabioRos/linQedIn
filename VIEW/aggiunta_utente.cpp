#include "aggiunta_utente.h"
//#include <QApplication>

aggiunta_utente::aggiunta_utente(QWidget *parent) :
    QWidget(parent){
    layout_form=new QFormLayout(this);

    QHBoxLayout* layout_footer= new QHBoxLayout;

    //costruisco campi dati
    btn_conferma=new QPushButton("inserisci",this);
    lbl_cognome=new QLabel("Cognome",this);
    lbl_nome=new QLabel("Nome",this);
    lbl_username=new QLabel("Username",this);
    lbl_competenze=new QLabel("Competenze inserite",this);
    cognome= new QLineEdit(this);
    txt_nuova_competenza= new QLineEdit(this);
    btn_nuova_competenza=new QPushButton("inserisci competenza",this);
    nome= new QLineEdit(this);
    username= new QLineEdit(this);
    competenze= new QListWidget(this);
    btn_rimuovi_competenze=new QPushButton("rimuovi competenze",this);

    QHBoxLayout* sotto_layout_competenze= new QHBoxLayout;
    sotto_layout_competenze->addWidget(txt_nuova_competenza);
    sotto_layout_competenze->addWidget(btn_nuova_competenza);


    QVBoxLayout* layout_competenze= new QVBoxLayout;
    layout_competenze->addWidget(new QLabel("<b><center>COMPETENZE</center></b>"));
    layout_competenze->addLayout(sotto_layout_competenze);

    blocco_lingua=new modulo_lingua(this);

    layout_form->addRow(lbl_cognome,cognome);
    layout_form->addRow(lbl_nome,nome);
    layout_form->addRow(lbl_username,username);
    layout_form->addRow(layout_competenze);
    layout_form->addRow(lbl_competenze,competenze);
    layout_form->addRow(new QLabel("Rimuovi competenze selezionate"),btn_rimuovi_competenze);
    layout_form->addRow(new QLabel("<b><center>LINGUE</center></b>"));
    layout_form->addRow(blocco_lingua);


    layout_form->addRow(layout_footer);

    layout_footer->addWidget(btn_conferma);


    //connessioni
    connect(btn_nuova_competenza, SIGNAL(clicked()), this, SLOT(aggiungi_competenza()));
    connect(btn_rimuovi_competenze, SIGNAL(clicked()), this, SLOT(rimuovi_competenza()));
}

void aggiunta_utente::aggiungi_competenza(){
    competenze->addItem(txt_nuova_competenza->text());
}


void aggiunta_utente::rimuovi_competenza(){
    qDeleteAll(competenze->selectedItems());
    //sempre uno solo, ma se volessi metterne di più funzionerebbe comunque
}

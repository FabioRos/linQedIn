#include "modulo_competenza.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>

modulo_competenza::modulo_competenza(QWidget *parent) :
    QWidget(parent){

    competenze= new QListWidget(this);
    btn_rimuovi_competenze=new QPushButton("rimuovi competenze",this);
    btn_nuova_competenza= new QPushButton("inserisci competenza",this);
    txt_nuova_competenza = new QLineEdit(this);


    QFormLayout* layout_form_competenza=new QFormLayout(this);

    layout_form_competenza->addRow(new QLabel("<b><center>COMPETENZE</center></b>"));
    layout_form_competenza->addRow("Competenza:",txt_nuova_competenza);
    layout_form_competenza->addRow(btn_nuova_competenza);
    layout_form_competenza->addRow("Competenze inserite: ",competenze);
    layout_form_competenza->addRow(btn_rimuovi_competenze);

    //connessioni
    connect(btn_nuova_competenza, SIGNAL(clicked()), this, SLOT(controllore()));
    connect(btn_rimuovi_competenze, SIGNAL(clicked()), this, SLOT(rimuovi_competenza()));
    connect(this,SIGNAL(segnale_err_txt()),this,SLOT(errore_testo_vuoto()));




}


void modulo_competenza::aggiungi_competenza(){
    competenze->addItem(txt_nuova_competenza->text());
}


void modulo_competenza::rimuovi_competenza(){
    qDeleteAll(competenze->selectedItems());
    //sempre uno solo, ma se volessi metterne di più funzionerebbe comunque
}


void modulo_competenza::controllore(){
    if(txt_nuova_competenza->text()=="")
        emit segnale_err_txt();
    else
        aggiungi_competenza();
}

void modulo_competenza::errore_testo_vuoto(){
    QMessageBox* errore= new QMessageBox(this);
    errore->setText("Il campo descrizione per la sezione competenza non può essere vuoto.");
    errore->setIcon(QMessageBox::Warning);
    errore->setWindowTitle("Attenzione");
    errore->exec();
}
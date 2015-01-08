#include "modulo_lingua.h"
#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>


modulo_lingua::modulo_lingua(QWidget *parent) :
    QWidget(parent){

    descrizione_lingua=new QLineEdit;
    QPushButton* inserisci_lingua= new QPushButton("inserisci lingua");

    //select_box opzioni_________

    select_parlato =new QComboBox();
    select_comprensione =new QComboBox();
    select_scritto =new QComboBox();
    lingue = new QListWidget(this);

    //popolo
    QStringList livelli;
        livelli << "A1" << "A2" << "B1" << "B2"<< "C1" << "C2";
        select_parlato->addItems(livelli);
        select_comprensione->addItems(livelli);
        select_scritto->addItems(livelli);

    //___________________________


    QFormLayout* layout_form_lingua= new QFormLayout(this);
    layout_form_lingua->addRow("<u>Lingua</u>:",descrizione_lingua);
    layout_form_lingua->addRow("Livello comprensione",select_comprensione);
    layout_form_lingua->addRow("Livello sritto",select_scritto);
    layout_form_lingua->addRow("Livello parlato",select_parlato);
    layout_form_lingua->addRow(inserisci_lingua);



     //connessioni
     connect(inserisci_lingua, SIGNAL(clicked()), this, SLOT(aggiungi_lingua()));
     //connect(btn_rimuovi_competenze, SIGNAL(clicked()), this, SLOT(rimuovi_competenza()));



}

void modulo_lingua::aggiungi_lingua(){  // da testare
    QString record=descrizione_lingua->text();
    record.append(",comprensione:");
    record.append(select_comprensione->itemText(select_comprensione->currentIndex()));
    record.append(",scritto:");
    record.append(select_scritto->itemText(select_scritto->currentIndex()));
    record.append(",parlato:");
    record.append(select_parlato->itemText(select_parlato->currentIndex()));
    lingue->addItem(record);
}

void modulo_lingua::rimuovi_lingua(){

}

//void aggiunta_utente::aggiungi_competenza(){
//    competenze->addItem(txt_nuova_competenza->text());
//}


//void aggiunta_utente::rimuovi_competenza(){
//    qDeleteAll(competenze->selectedItems());
//    //sempre uno solo, ma se volessi metterne di più funzionerebbe comunque
//}

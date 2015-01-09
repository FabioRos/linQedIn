#include "modulo_lingua.h"
#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>

modulo_lingua::modulo_lingua(QWidget *parent) :
    QWidget(parent){

    descrizione_lingua=new QLineEdit;
    inserisci_lingua= new QPushButton("inserisci lingua");
    btn_rimuovi_lingua= new QPushButton("rimuovi lingua");
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
    layout_form_lingua->addRow(new QLabel("<b><center>LINGUE</center></b>"));
    layout_form_lingua->addRow("<u>Lingua</u>:",descrizione_lingua);
    layout_form_lingua->addRow("Livello comprensione",select_comprensione);
    layout_form_lingua->addRow("Livello sritto",select_scritto);
    layout_form_lingua->addRow("Livello parlato",select_parlato);
    layout_form_lingua->addRow(inserisci_lingua);
    layout_form_lingua->addRow("Lingue inserite: ",lingue);
    layout_form_lingua->addRow("Rimuovi lingua selezionata:", btn_rimuovi_lingua);


     //connessioni
     connect(inserisci_lingua, SIGNAL(clicked()), this, SLOT(controllore()));
     connect(btn_rimuovi_lingua, SIGNAL(clicked()), this, SLOT(rimuovi_lingua()));
     connect(this,SIGNAL(segnale_err_txt()),this,SLOT(errore_testo_vuoto()));
}

void modulo_lingua::aggiungi_lingua(){  // da testare
    QString record=descrizione_lingua->text();
    record.append("\n-comprensione:");
    record.append(select_comprensione->itemText(select_comprensione->currentIndex()));
    record.append("\n-scritto:");
    record.append(select_scritto->itemText(select_scritto->currentIndex()));
    record.append("\n-parlato:");
    record.append(select_parlato->itemText(select_parlato->currentIndex()));
    record.append("\n");
    lingue->addItem(record);
}

void modulo_lingua::rimuovi_lingua(){
    qDeleteAll(lingue->selectedItems());
}


void modulo_lingua::controllore(){
    if(descrizione_lingua->text()=="")
        emit segnale_err_txt();
    else
        aggiungi_lingua();
}

void modulo_lingua::errore_testo_vuoto(){
    QMessageBox* errore= new QMessageBox(this);
    errore->setText("Il campo descrizione non può essere vuoto.");
    errore->setIcon(QMessageBox::Warning);
    errore->setWindowTitle("Attenzione");
    errore->exec();
}

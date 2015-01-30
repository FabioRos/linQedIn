#include "modulo_lingua.h"
#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>

#include <QJsonArray>
#include <QJsonObject>

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
    lingue->setMinimumHeight(250);

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
    layout_form_lingua->addRow("Livello scritto",select_scritto);
    layout_form_lingua->addRow("Livello parlato",select_parlato);
    layout_form_lingua->addRow(inserisci_lingua);
    layout_form_lingua->addRow("Lingue inserite: ",lingue);
    layout_form_lingua->addRow("Rimuovi lingua selezionata:", btn_rimuovi_lingua);


     //connessioni
     connect(inserisci_lingua, SIGNAL(clicked()), this, SLOT(controllore()));
     connect(btn_rimuovi_lingua, SIGNAL(clicked()), this, SLOT(rimuovi_lingua()));
     connect(this,SIGNAL(segnale_err_txt()),this,SLOT(errore_testo_vuoto()));
}

void  modulo_lingua::aggiungi_lingua(){  // da testare

    QString descrizione_=descrizione_lingua->text();
    QString comprensione_=select_comprensione->itemText(select_comprensione->currentIndex());
    QString scritto_=select_scritto->itemText(select_scritto->currentIndex());
    QString parlato_=select_parlato->itemText(select_parlato->currentIndex());

//    QString record="{\n \"descrizione\": \"";
//    record.append(descrizione_);
//    record.append("\",\n \"comprensione\": \"");
//    record.append(comprensione_);
//    record.append("\",\n \"scritto\": \"");
//    record.append(scritto_);
//    record.append("\",\n \"parlato\": \"");
//    record.append(parlato_);
//    record.append("\"\n}");
    QString record=descrizione_;
    record.append(" # ");   //sentinella per non avere problemi con gli spazi nelle descrizioni
    record.append(comprensione_);
    record.append(" ");
    record.append(scritto_);
    record.append(" ");
    record.append(parlato_);
    lingue->addItem(record);

    //Ho messo in questo formato per andare meglio a fare il parsing
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


std::list<std::string> modulo_lingua::get_lista_lingue() const{
    //mando la stringa intera e demando il parse al controller
    std::list<std::string> tutte_le_lingue;

    for(int i = 0; i < lingue->count(); ++i)
    {
        QListWidgetItem* item = lingue->item(i);
        tutte_le_lingue.push_back(item->text().toStdString());
    }
    return tutte_le_lingue;
}

modulo_lingua::~modulo_lingua(){
    delete lingue;
    delete descrizione_lingua;
    delete select_parlato;
    delete select_scritto;
    delete select_comprensione;
    delete btn_rimuovi_lingua;
    delete inserisci_lingua;
}

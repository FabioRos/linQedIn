#include "modulo_esperienza_professionale.h"
#include <QFormLayout>
#include <QLabel>
#include <QMessageBox>

modulo_esperienza_professionale::modulo_esperienza_professionale(QWidget *parent) :
    QWidget(parent){

    //istanzio oggetti:
    luogo=new QLineEdit(this);
    descrizione=new QLineEdit(this);
    nome_azienda=new QLineEdit(this);
    posizione=new QLineEdit(this);
    data_inizio=new QCalendarWidget(this);
    data_fine=new QCalendarWidget(this);
    data_inizio->setMaximumWidth(350);
    data_fine->setMaximumWidth(350);
    btn_inserisci_esperienza=new QPushButton("inserisci esperienza",this);
    btn_rimuovi_esperienza=new QPushButton("rimuovi esperienza selezionata",this);
    esperienze= new QListWidget(this);
    esperienze->setMinimumHeight(200);



    QFormLayout* layout_form_esperienza= new QFormLayout(this);
    layout_form_esperienza->addRow(new QLabel("<b><center>ESPERIENZE PROFESSIONALI</center></b>"));
    layout_form_esperienza->addRow("descrizione: ",descrizione);
    layout_form_esperienza->addRow("luogo: ",luogo);
    layout_form_esperienza->addRow("nome azienda: ",nome_azienda);
    layout_form_esperienza->addRow("posizione: ",posizione);
    layout_form_esperienza->addRow("data inizio: ",data_inizio);
    layout_form_esperienza->addRow("data fine: ",data_fine);
    layout_form_esperienza->addRow(btn_inserisci_esperienza);
    layout_form_esperienza->addRow("esperienze inserite: ",esperienze);
    layout_form_esperienza->addRow(btn_rimuovi_esperienza);

    //connessioni
    connect(btn_inserisci_esperienza, SIGNAL(clicked()), this, SLOT(controllore()));
    connect(btn_rimuovi_esperienza, SIGNAL(clicked()), this, SLOT(rimuovi_esperienza()));
    connect(this,SIGNAL(segnale_err_txt()),this,SLOT(errore_testo_vuoto()));

}


void modulo_esperienza_professionale::aggiungi_esperienza(){
    QString record("\n descrizione: ");
    record.append(descrizione->text());
    record.append("\n posizione: ");
    record.append(posizione->text());
    record.append("\n luogo: ");
    record.append(luogo->text());
    record.append("\n nome azienda: ");
    record.append(nome_azienda->text());
    record.append("\n dal giorno: ");
    //record.append(data_inizio);
    //record.append("\n al giorno: ");
    //record.append(data_fine);
    //record.append("\n");

    esperienze->addItem(record);
}


void modulo_esperienza_professionale::rimuovi_esperienza(){
    qDeleteAll(esperienze->selectedItems());
    //sempre uno solo, ma se volessi metterne di più funzionerebbe comunque
}


void modulo_esperienza_professionale::controllore(){
    if(descrizione->text()=="")
        emit segnale_err_txt();
    else
        aggiungi_esperienza();
}

void modulo_esperienza_professionale::errore_testo_vuoto(){
    QMessageBox* errore= new QMessageBox(this);
    errore->setText("Il campo descrizione per la sezione competenza non può essere vuoto.");
    errore->setIcon(QMessageBox::Warning);
    errore->setWindowTitle("Attenzione");
    errore->exec();
}

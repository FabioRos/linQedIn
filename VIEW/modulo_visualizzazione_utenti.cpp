#include "modulo_visualizzazione_utenti.h"
#include "amministrazione.h"

//temp
#include <iostream>

//---


modulo_visualizzazione_utenti::modulo_visualizzazione_utenti(users_repository* repo,QWidget *parent)
    :ptr_repository(repo), QWidget(parent){
    numero_elementi=0;
    tabella = new QTableWidget(this);
    tabella->setMinimumWidth(510);
//    tabella->setMinimumHeight(600);
//    tabella->setMaximumHeight(600);
    tabella->setSizeAdjustPolicy(QScrollArea::AdjustToContents);
    inizializza_tabella();

    //popolazione
   if(ptr_repository!=0)
        popola_tabella(ptr_repository->get_database());
}

void modulo_visualizzazione_utenti::inizializza_tabella(){
    tabella->setColumnCount(3);
    tabella->setHorizontalHeaderLabels(QStringList() << "Username" << "Cognome" << "Nome");
    tabella->horizontalHeader()->setStretchLastSection(1);
    tabella->setColumnWidth(0,150);
    tabella->setColumnWidth(1,150);
    tabella->setColumnWidth(2,150);
    popola_tabella(ptr_repository->get_database());

    //tabella->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
}

QTableWidget *modulo_visualizzazione_utenti::get_ptr_tabella() const{
    return tabella;
}

void modulo_visualizzazione_utenti::popola_tabella(std::list<smart_utente*> lista_record){
    tabella->setRowCount(ptr_repository->size());
    int offset=0;
    for(std::list<smart_utente*>::iterator it=lista_record.begin();
        it!=lista_record.end();++it){
        inserisci_riga((*it)->get_ptr_utente(),offset);
        offset++;
    }
    numero_elementi=offset;
}

void modulo_visualizzazione_utenti::rimuovi_tutti(){

    tabella->clearContents();
}



void modulo_visualizzazione_utenti::inserisci_riga(utente* riga,int indice_riga){
    //->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable
    QTableWidgetItem* item_username =new QTableWidgetItem(QString::fromStdString(riga->get_username()));
    QTableWidgetItem* item_cognome =new QTableWidgetItem(QString::fromStdString(riga->get_cognome()));
    QTableWidgetItem* item_nome=new QTableWidgetItem(QString::fromStdString(riga->get_nome()));
    QTableWidgetItem* item_tipo_account=new QTableWidgetItem(QString::fromStdString("da implementare"));

    //flags
    item_username->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    item_cognome->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    item_nome->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    item_tipo_account->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);

    //inserimento effettivo entry
    tabella->setItem(indice_riga,0,item_username);
    tabella->setItem(indice_riga,1,item_cognome);
    tabella->setItem(indice_riga,2,item_nome);
    //tabella->setItem(indice_riga,3,item_tipo_account);

   // connect()
}


void modulo_visualizzazione_utenti::refresh(){
    if(tabella!=0){
        tabella->clear();
    }else{
        tabella=new QTableWidget(this);
    }
    inizializza_tabella();
    tabella->setColumnCount(3);
    tabella->setHorizontalHeaderLabels(QStringList() << "Username" << "Cognome" << "Nome");
    //popolazione
    popola_tabella(ptr_repository->get_database());



    // std::cout<<(ptr_repository==0)<<std::endl;
    //popola_tabella(ptr_repository->get_database());
}

modulo_visualizzazione_utenti::~modulo_visualizzazione_utenti(){
        delete tabella;
}

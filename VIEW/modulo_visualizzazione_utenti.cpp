#include "modulo_visualizzazione_utenti.h"
#include <QStringList>
#include <QHeaderView>

//temp
#include <iostream>

//---
void modulo_visualizzazione_utenti::inizializza_tabella(){
    tabella->setColumnCount(4);
    tabella->setHorizontalHeaderLabels(QStringList() << "Username" << "Cognome" << "Nome" << "tipo account");
    tabella->horizontalHeader()->setStretchLastSection(1);
    popola_tabella(ptr_repository->get_database());
    //tabella->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
}

void modulo_visualizzazione_utenti::popola_tabella(std::list<smart_utente*> lista_record){
    tabella->setRowCount(ptr_repository->size());
    int offset=0;
    for(std::list<smart_utente*>::iterator it=lista_record.begin();
        it!=lista_record.end();++it){
        inserisci_riga((*it)->get_ptr_utente(),offset);
        offset++;
    }
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
    tabella->setItem(indice_riga,0,item_username);
    tabella->setItem(indice_riga,1,item_cognome);
    tabella->setItem(indice_riga,2,item_nome);
    tabella->setItem(indice_riga,3,item_tipo_account);

   // connect()
}

modulo_visualizzazione_utenti::modulo_visualizzazione_utenti(users_repository* repo,QWidget *parent)
    :ptr_repository(repo), QWidget(parent){
    tabella = new QTableWidget(this);
    tabella->setMinimumWidth(510);
    tabella->setMaximumWidth(510);
    inizializza_tabella();
    //popolazione fittizia temporanea


    //tabella->insertRow(20);


//    tabella->setRowCount(10);
//    tabella->setColumnCount(4);


}

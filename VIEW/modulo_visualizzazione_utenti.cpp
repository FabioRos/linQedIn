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
}

void modulo_visualizzazione_utenti::popola_tabella(std::list<smart_utente*> lista_record){
tabella->setRowCount(lista_record.size());
//tabella->setItem(0, 1, new QTableWidgetItem("Hello"));
}

modulo_visualizzazione_utenti::modulo_visualizzazione_utenti(QWidget *parent)
    : QWidget(parent){
    tabella = new QTableWidget(this);
    tabella->setMinimumWidth(510);
    tabella->setMaximumWidth(510);
    inizializza_tabella();
    //popolazione fittizia temporanea


    //tabella->insertRow(20);


//    tabella->setRowCount(10);
//    tabella->setColumnCount(4);


}

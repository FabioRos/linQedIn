#include "modulo_rimozione_utenti.h"
#include <QDebug>

modulo_rimozione_utenti::modulo_rimozione_utenti(users_repository* repo, admin_controller* ac,
                                                 QWidget *parent) :controller(ac),
                                                 modulo_visualizzazione_utenti(repo,parent){
    ptr_tabella=get_ptr_tabella();
    ptr_tabella->setMaximumHeight(450);
    btn_rimuovi_utente=new QPushButton("Rimuovi utente selezionato",this);
    btn_rimuovi_utente->show();
    btn_rimuovi_utente->setGeometry(10,460,490,50);

    //connessioni

    //recupero indici e chiamo funzione per selezionare la riga
    connect(ptr_tabella,SIGNAL(cellClicked(int,int)),this,SLOT(seleziona_riga(int,int)));
    connect(btn_rimuovi_utente,SIGNAL(clicked()),this,SLOT(rimuovi_utenti()));
}

std::list<std::string> modulo_rimozione_utenti::get_selected_usernames() const{

    std::list<std::string> usernames;

    std::list<QModelIndex> l=ptr_tabella->selectionModel()->selectedRows().toStdList();



    std::list<QModelIndex>::const_iterator it=l.begin();
    for(;it!=l.end();++it){
        //qDebug() << ptr_tabella->item( (it)->row(),0)->text();
        usernames.push_back(ptr_tabella->item( (it)->row(),0)->text().toStdString());
    }

//    for (int i=0; i<ptr_tabella->rowCount(); ++i)
//    {   //if(ptr_tabella->rowAt(i))
//        ptr_tabella->item(i,0)->text();
//        qDebug() << ptr_tabella->item(i, 0)->text();
//    }

     return usernames;
}

modulo_rimozione_utenti::~modulo_rimozione_utenti(){
    delete btn_rimuovi_utente;
}

void modulo_rimozione_utenti::seleziona_riga(int riga, int colonna) const{
    ptr_tabella->selectRow(riga);
}

void modulo_rimozione_utenti::rimuovi_utenti() const{
    controller->rimuovi_utenti(get_selected_usernames());
}

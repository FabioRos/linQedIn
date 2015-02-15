#include "cerca.h"

cerca::cerca(users_repository * repo, const std::string& usr, QWidget *parent)
    :ptr_repository(repo),username_corrente(usr),QWidget(parent){
    tabella=new modulo_visualizzazione_utenti(ptr_repository,this);
    tabella->get_ptr_tabella()->setMaximumHeight(320);
    tabella->get_ptr_tabella()->setMinimumWidth(600);
    tabella->get_ptr_tabella()->setMaximumWidth(600);
    tabella->get_ptr_tabella()->setColumnWidth(0,180);
    tabella->get_ptr_tabella()->setColumnWidth(1,180);
    tabella->get_ptr_tabella()->setColumnWidth(2,180);
    input_ricerca=new QLineEdit;
    input_ricerca->setPlaceholderText("inserisci qui una competenza, l'username, il nome oppure il cognome");
    lbl_titolo = new QLabel("<center><h4><b> CERCA </b></h4></center>");
    lbl_titolo->setMaximumHeight(40);
    lbl_how_to = new QLabel("<center><i> Inserisci una sola parola e clicca su una cella per avere maggiori opzioni </></center>");
    lbl_how_to->setMaximumHeight(40);
    layout_vericale=new QVBoxLayout(this);
    layout_vericale->addWidget(lbl_titolo);
    layout_vericale->addWidget(input_ricerca);
    layout_vericale->addWidget(tabella);
    layout_vericale->addWidget(lbl_how_to);
    tabella->rimuovi_tutti();

    connect(input_ricerca,SIGNAL(textChanged(QString)),this,SLOT(popola(QString)));
    connect(tabella->get_ptr_tabella(),SIGNAL(cellClicked(int,int)),this,SLOT(esplodi_opzioni(int,int)));
}

void cerca::popola(QString qs){
    //pulisco
    tabella->rimuovi_tutti();
    if(qs!=""){
        //ricreo
        utente* u=ptr_repository->get_ptr_utente(username_corrente);
        std::list<utente *> lista=u->cerca(ptr_repository,qs.toStdString());
        //delete tabella;
        int i=0;
        std::list<utente *>::const_iterator it=lista.begin();
        for(;it!=lista.end();++it){
            tabella->inserisci_riga(*it,i++);
        }
    }


    //tabella->inserisci_riga(u,i);
}

void cerca::esplodi_opzioni(const int &r, const int &c){
    if(tabella->get_ptr_tabella()->item(r,c)!=0 && tabella->get_ptr_tabella()->item(r,c)->text()!=""){
        tabella->get_ptr_tabella()->selectRow(r);
        QList<QTableWidgetItem *> lista=tabella->get_ptr_tabella()->selectedItems();
        std::string username_con_focus= lista.front()->text().toStdString();
        //std::string username_con_focus= tabella->get_ptr_tabella()->itemAt(r,1)->text().toStdString();
        profilo_popup* popup_profilo= new profilo_popup(ptr_repository,username_corrente, username_con_focus);
        // popup_profilo->modalita_sola_lettura();
        if(popup_profilo)
            popup_profilo->show();
     }
}


#include "admin_cerca.h"

admin_cerca::admin_cerca(users_repository *ptr_repo, QWidget *parent):
    ptr_repository(ptr_repo),QWidget(parent){

    input_ricerca= new QLineEdit(this);
    input_ricerca->setPlaceholderText("inserisci qui il testo");

    tabella=new modulo_visualizzazione_utenti(ptr_repository,this);
    tabella->rimuovi_tutti();
    layout= new QVBoxLayout(this);
    layout->addWidget(input_ricerca);
    layout->addWidget(tabella);





    connect(input_ricerca,SIGNAL(textChanged(QString)),this,SLOT(popola(QString)));
    connect(tabella->get_ptr_tabella(),SIGNAL(cellClicked(int,int)),this,SLOT(esplodi_opzioni(int,int)));
}

void admin_cerca::popola(QString qs){
    //pulisco
    tabella->rimuovi_tutti();
    if(qs!=""){
        //ricreo
        std::list<utente *> lista=ptr_repository->cerca(ptr_repository,qs.toStdString(),101);
        //delete tabella;
        int i=0;
        std::list<utente *>::const_iterator it=lista.begin();
        for(;it!=lista.end();++it){
            tabella->inserisci_riga(*it,i++);
        }
    }
}

void admin_cerca::esplodi_opzioni(const int &r, const int &c){
    if(tabella->get_ptr_tabella()->item(r,c)!=0 && tabella->get_ptr_tabella()->item(r,c)->text()!=""){
        tabella->get_ptr_tabella()->selectRow(r);
        QList<QTableWidgetItem *> lista=tabella->get_ptr_tabella()->selectedItems();
        std::string username_con_focus= lista.front()->text().toStdString();
        //std::string username_con_focus= tabella->get_ptr_tabella()->itemAt(r,1)->text().toStdString();
        profilo_popup* popup_profilo= new profilo_popup(ptr_repository,username_con_focus);
        // popup_profilo->modalita_sola_lettura();
        if(popup_profilo)
            popup_profilo->show();
     }

}

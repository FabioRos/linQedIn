#include "client_rete.h"

client_rete::client_rete(const std::string &username, users_repository *ptr_repo, QWidget *parent):
    utente_corrente(username),ptr_repository(ptr_repo),QWidget(parent){
    tabella=new modulo_visualizzazione_utenti(ptr_repo);
    tabella->rimuovi_tutti();
    tabella->popola_tabella(get_all_smu_rete());
    QLabel* lbl_suggerimento=new QLabel("<center><i>Per rimuovere un contatto selezionalo e conferma.</i></center>");
    QLabel *titolo=new QLabel("<center><h3>RETE</h3></center>");
    titolo->setMaximumHeight(50);
    titolo->setMaximumHeight(70);
    layout=new QVBoxLayout(this);
    layout->addWidget(titolo);
    layout->addWidget(tabella);
    layout->addWidget(lbl_suggerimento);


    //connessioni
      connect(tabella->get_ptr_tabella(),SIGNAL(cellClicked(int,int)),this,SLOT(esplodi_opzioni(int,int)));
}



std::list<smart_utente *> client_rete::get_all_smu_rete() const{
    std::list<smart_utente *> risultato;
    std::list<utente *> lista_utenti = ptr_repository->get_ptr_utente(utente_corrente)->get_all_rete();
    std::list<utente *>::const_iterator it=lista_utenti.begin();
    for(;it!=lista_utenti.end();++it){
        risultato.push_back(new smart_utente(*it));

    }
return risultato;
}

void client_rete::esplodi_opzioni(const int &r, const int &c){
    if(tabella->get_ptr_tabella()->item(r,c)!=0 && tabella->get_ptr_tabella()->item(r,c)->text()!=""){
        tabella->get_ptr_tabella()->selectRow(r);
        const QString titolo="Rimuovi utente da rete";

        QList<QTableWidgetItem *> lista=tabella->get_ptr_tabella()->selectedItems();
        std::string username_con_focus= lista.front()->text().toStdString();
        popup_rimuovi_utente_da_rete* popup= new popup_rimuovi_utente_da_rete(utente_corrente,username_con_focus,ptr_repository,0);
        popup->show();
    }
}

void client_rete::refresh(){
    tabella->rimuovi_tutti();
    tabella->popola_tabella(get_all_smu_rete());
}

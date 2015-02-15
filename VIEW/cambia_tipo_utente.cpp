#include "cambia_tipo_utente.h"

cambia_tipo_utente::cambia_tipo_utente(users_repository * repo, QWidget *parent)
    :ptr_repository(repo),QWidget(parent){


    tabella=new modulo_visualizzazione_utenti(ptr_repository);
    btn_salva=new QPushButton("salva modifiche");
    input_ricerca=new QLineEdit;
    input_ricerca->setPlaceholderText("inserisci qui l'username, il nome oppure il cognome");
    lbl_titolo =new QLabel("<center><b> CAMBIO TIPO ACCOUNT </b></center>");
    lbl_titolo->setMaximumHeight(40);
    layout_vericale=new QVBoxLayout(this);
    layout_vericale->addWidget(lbl_titolo);
    layout_vericale->addWidget(input_ricerca);
    layout_vericale->addWidget(tabella);
    layout_vericale->addWidget(btn_salva);


    //connessioni
     connect(tabella->get_ptr_tabella(),SIGNAL(cellClicked(int,int)),this,SLOT(esplodi_opzioni(int,int)));

}

void cambia_tipo_utente::esplodi_opzioni(const int &r, const int &c){

    if(tabella->get_ptr_tabella()->item(r,c)!=0 && tabella->get_ptr_tabella()->item(r,c)->text()!=""){
        tabella->get_ptr_tabella()->selectRow(r);
        QList<QTableWidgetItem *> lista=tabella->get_ptr_tabella()->selectedItems();
        std::string username_con_focus= lista.front()->text().toStdString();

        popup_cambia_tipo_utente* popup_tipo= new popup_cambia_tipo_utente(username_con_focus,ptr_repository);
        if(popup_tipo)
            popup_tipo->show();
    }



}

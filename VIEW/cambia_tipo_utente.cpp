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

}

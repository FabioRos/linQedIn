#include "aggiunta_utente.h"

aggiunta_utente::aggiunta_utente(QWidget *parent) :
    QWidget(parent){
    layout_form=new QFormLayout(this);

    QHBoxLayout* layout_footer= new QHBoxLayout;

    //costruisco campi dati
    btn_conferma=new QPushButton("inserisci",this);
    lbl_cognome=new QLabel("Cognome");
    lbl_nome=new QLabel("Nome");
    cognome= new QLineEdit();
    nome= new QLineEdit();

    layout_form->addRow(lbl_cognome,cognome);
    layout_form->addRow(lbl_nome,nome);
    layout_form->addRow(layout_footer);

    layout_footer->addWidget(btn_conferma);
}

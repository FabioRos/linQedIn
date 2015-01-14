#include "aggiunta_utente.h"

aggiunta_utente::aggiunta_utente(users_repository *repo, QWidget *parent)
    : ptr_repository(repo) ,QWidget(parent){
    layout_form=new QFormLayout(this);
    QHBoxLayout* layout_footer= new QHBoxLayout;

    btn_conferma=new QPushButton("inserisci",this);
    cognome= new QLineEdit(this);
    nome= new QLineEdit(this);
    username= new QLineEdit(this);

    tipologia_account=new QComboBox(this);
    QStringList tipi;
    tipi << "BASIC" << "BUSINESS" << "EXECUTIVE";
    tipologia_account->addItems(tipi);



    //Istanzio componenti

    blocco_lingua=new modulo_lingua(this);
    blocco_competenza= new modulo_competenza(this);
    blocco_esperienza_professionale= new modulo_esperienza_professionale(this);

    layout_form->addRow("Cognome:",cognome);
    layout_form->addRow("Nome:",nome);
    layout_form->addRow("Username:",username);
    layout_form->addRow("Tipo di account: ",tipologia_account);

    layout_form->addRow(blocco_competenza);
    layout_form->addRow(blocco_lingua);
    layout_form->addRow(blocco_esperienza_professionale);


    layout_form->addRow(layout_footer);

    layout_footer->addWidget(btn_conferma);
}

#include "aggiunta_utente.h"

aggiunta_utente::aggiunta_utente(users_repository *repo, QWidget *parent)
    : ptr_repository(repo) ,QWidget(parent){
    layout_form=new QFormLayout(this);
    QHBoxLayout* layout_footer= new QHBoxLayout;

    btn_conferma=new QPushButton("inserisci",this);
    cognome= new QLineEdit(this);
    nome= new QLineEdit(this);
    username= new QLineEdit(this);
    carta_di_credito= new QLineEdit(this);
    carta_di_credito->setDisabled(true);
    tipologia_account=new QComboBox(this);
    QStringList tipi;
    tipi << "BASIC" << "BUSINESS" << "EXECUTIVE";
    tipologia_account->addItems(tipi);



    //Istanzio componenti

    blocco_lingua=new modulo_lingua(this);
    blocco_competenza= new modulo_competenza(this);
    blocco_esperienza_professionale= new modulo_esperienza_professionale(this);
    layout_form->addRow("",new QLabel("<h3><b><center>INSERIMENTO UTENTE</center></b></h3>"));
    layout_form->addRow("Cognome:",cognome);
    layout_form->addRow("Nome:",nome);
    layout_form->addRow("Username:",username);
    layout_form->addRow("Tipo di account: ",tipologia_account);
    layout_form->addRow("Carta di credito:",carta_di_credito);

    layout_form->addRow(blocco_competenza);
    layout_form->addRow(blocco_lingua);
    layout_form->addRow(blocco_esperienza_professionale);


    layout_form->addRow(layout_footer);

    layout_footer->addWidget(btn_conferma);

    //connessioni
    connect(btn_conferma,SIGNAL(clicked()),this,SLOT(aggiungi_utente_a_db()));
    connect(tipologia_account,SIGNAL(currentIndexChanged(int)),this,SLOT(cc_manager(int)));
}



void aggiunta_utente::aggiungi_utente_a_db(){
        //prendo i campi dati
        std::string username_ = username->text().toStdString();
        std::string cognome_ = cognome->text().toStdString();
        std::string nome_ = nome->text().toStdString();
        //tipo account
        QString tipo_a=tipologia_account->currentText();
        std::string tipo_account=tipo_a.toStdString();
        //competenze
        std::list<std::string> competenze_ =blocco_competenza->get_lista_competenze();
        //lingue
        std::list<std::string> lingue_=blocco_lingua->get_lista_lingue();
        //esperienze
        std::list<std::string> esperienze_=blocco_esperienza_professionale->get_lista_esperienze_txt();
        //carta di credito
        std::string cc=carta_di_credito->text().toStdString();
        if(cc=="") cc="<<< NON INSERITA >>>";

        /* * * * * * * * * * * * * * * * * * * * * * * * * * * *
         *                                                     *
         *              MANCANO GLI ALTRI CAMPI DATI!!!        *
         *                                                     *
         * * * * * * * * * * * * * * * * * * * * * * * * * * * */


        //...

        //chiamo la procedura del controller
        aggiungi_modifica_utenti controller_handler(ptr_repository);
        controller_handler.aggiungi_utente(aggiungi_modifica_utenti::costruisci_utente(tipo_account,
                                                username_,cognome_,nome_,competenze_,lingue_,
                                                esperienze_, cc));

        //inserisco tramite lo smartutente*
}

void aggiunta_utente::cc_manager(int i){

    QString s= carta_di_credito->text();
    if(i==1 || i==2)
        carta_di_credito->setDisabled(false);
    else    //0
        carta_di_credito->setDisabled(true);
}

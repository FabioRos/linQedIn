#include "menu_amministrazione.h"
#include "./CONTROLLER/admin_controller.h"
#include "./VIEW/amministrazione.h"

#include <QVBoxLayout>


#include <iostream>




menu_amministrazione::menu_amministrazione(QWidget *parent,users_repository* repo)
    :QWidget(parent),ptr_repo(repo),parent_ptr(parent){

    //ISTANZIO MEMBRI
    btn_aggiungi_utente=new QPushButton("Aggiungi utente",this);
    btn_cambia_account=new QPushButton("Cambia tipo utente",this);
    btn_cerca=new QPushButton("Cerca",this);
    btn_dump_db=new QPushButton("Visualizza utenti",this);
    btn_rimuovi_utente=new QPushButton("Rimuovi utenti",this);



    main_menu_layout=new QVBoxLayout;

    //per fare la/e colonna/e di destra, basta aggiungere un widget e metterci dentro le cose

    //  I/O + EXIT _BEGIN           --> meglio portare fuori, in un altra classe
    btn_caricamento=new QPushButton("carica",this);
    btn2_salvataggio=new QPushButton("salva",this);
    //exit= new QPushButton("chiudi finestra",menu);

    ///CONNESSIONI

    //connect(exit,SIGNAL(clicked()),this,SLOT(close()));
    //messageBox
    sicuro_caricare=new QMessageBox;
    sicuro_salvare=new QErrorMessage;
    sicuro_caricare->setText("Sei sicuro di voler caricare?");//domanda
    sicuro_caricare->setWindowTitle("Attenzione");
    sicuro_caricare->setInformativeText("Se premi annulla il DB non verrà modificato");
    sicuro_caricare->setStandardButtons(QMessageBox::Yes | QMessageBox::No);

    connect(btn_caricamento,SIGNAL(clicked()),this,SLOT(conferma_caricamento()));//sicuro_caricare,SLOT(show()));//devo mandare un segnale a sicuro_caricare di mostrarsi
    //connect(sicuro_caricare,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(carica_db_da_file()));

    connect(btn2_salvataggio,SIGNAL(clicked()),this,SLOT(salva_su_file()));

    //connect(btn2,SIGNAL(clicked()),sicuro_salvare,SLOT(showMessage("Sovrascriverai il DB")));
    connect(btn_aggiungi_utente,SIGNAL(clicked()),parent,SLOT(mostra_pag_aggiunta_utenti()));
    connect(btn_dump_db,SIGNAL(clicked()),parent,SLOT(mostra_pag_visualizzazione_utenti()));

    //  I/O + EXIT _END

    QVBoxLayout* local_menu_layout=new QVBoxLayout(this);
    local_menu_layout->addWidget(btn_aggiungi_utente);
    local_menu_layout->addWidget(btn_rimuovi_utente);
    local_menu_layout->addWidget(btn_cambia_account);
    local_menu_layout->addWidget(btn_cerca);
    local_menu_layout->addWidget(btn_dump_db);

    QHBoxLayout* layout_carica_salva=new QHBoxLayout;
    layout_carica_salva->addWidget(btn_caricamento);
    layout_carica_salva->addWidget(btn2_salvataggio);

    local_menu_layout->addLayout(layout_carica_salva);

    connect(this,SIGNAL(refresh_tabella()),parent,SLOT(refresh()));
}



void menu_amministrazione::conferma_caricamento() {
    sicuro_caricare->show();
   // connect(this,SIGNAL(refresh_tabella()),parent(),SLOT(refresh()));
    if(sicuro_caricare->exec() == QMessageBox::Yes){
        carica_db_da_file();
        //se il widget nella scrollarea è quello di visualizzazione
        emit refresh_tabella();
    }

}
void menu_amministrazione::carica_db_da_file(){
    //creo un'istanza del controller con un puntatore al db che si copia il puntatore dalla
    // variabile ptr_repo. Il metodo è privato ma ci accedo per amicizia.
   admin_controller controller(ptr_repo->get_ptr_db());
   //dealloco il vecchio DB
   delete ptr_repo;
  // carico il nuovo DB
   ptr_repo=new users_repository(controller.carica_db());

}

void menu_amministrazione::salva_su_file() const{
    //admin_controller cntrl()
   // admin_controller::salva_db();
}

#include "menu_amministrazione.h"
#include <QVBoxLayout>
menu_amministrazione::menu_amministrazione(QWidget *parent):QWidget(parent){

    //ISTANZIO MEMBRI
    btn_aggiungi_utente=new QPushButton("Aggiungi utente",this);
    btn_cambia_account=new QPushButton("Cambia tipo utente",this);
    btn_cerca=new QPushButton("Cerca",this);
    btn_dump_db=new QPushButton("Visualizza utenti",this);
    btn_rimuovi_utente=new QPushButton("Rimuovi utenti",this);

    QVBoxLayout* local_menu_layout=new QVBoxLayout(this);
    local_menu_layout->addWidget(btn_aggiungi_utente);
    local_menu_layout->addWidget(btn_rimuovi_utente);
    local_menu_layout->addWidget(btn_cambia_account);
    local_menu_layout->addWidget(btn_cerca);
    local_menu_layout->addWidget(btn_dump_db);
    setLayout(local_menu_layout);
}

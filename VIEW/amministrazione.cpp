#include "amministrazione.h"
#include <QScrollBar>


amministrazione::amministrazione(users_repository* repo, QWidget *parent)
            :ptr_repository(repo),QWidget(parent){
    //IMPOSTAZIONI FINESTRA
    this->setWindowTitle("Pannello Amministrazione");

    // menu opzioni

    admin_controller* ac=new admin_controller(repo->get_ptr_db());
    pannello_opzioni=new menu_amministrazione(ac,this,ptr_repository);

    // scroll area

    scroll_area=new QScrollArea(this);
    scroll_area->setHorizontalScrollBarPolicy( Qt::ScrollBarAsNeeded);
    scroll_area->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn);
    scroll_area->setWidgetResizable(true);
    scroll_area->setFrameStyle(QFrame::NoFrame);
    scroll_area->setMaximumHeight(530);

    //creo il layout a due colonne, sx menu, dx area lavoro
    layout_due_colonne= new QHBoxLayout(this);
    layout_due_colonne->addWidget(pannello_opzioni);
    layout_due_colonne->addWidget(scroll_area);
}

void amministrazione::mostra_pag_rimozione_utenti(){
    admin_controller* ac=new admin_controller(ptr_repository->get_ptr_db());
    pagina_rimozione_utenti=new modulo_rimozione_utenti(ptr_repository, ac ,this);
    scroll_area->setWidget(pagina_rimozione_utenti);
}

void amministrazione::mostra_pag_aggiunta_utenti(){
    pagina_aggiunta_utente= new aggiunta_utente(ptr_repository,this);
    scroll_area->setWidget(pagina_aggiunta_utente);
}

void amministrazione::mostra_pag_visualizzazione_utenti(){
    pagina_visualizzazione_utenti=new modulo_visualizzazione_utenti(ptr_repository,this);
    scroll_area->setWidget(pagina_visualizzazione_utenti);

}

void amministrazione::refresh(){
    mostra_pag_visualizzazione_utenti();
    if(pagina_visualizzazione_utenti)
        pagina_visualizzazione_utenti->refresh();

}

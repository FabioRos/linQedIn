#include "amministazione.h"
#include <QScrollBar>

amministazione::amministazione(QWidget *parent):QWidget(parent){
    //IMPOSTAZIONI FINESTRA
    this->setWindowTitle("Pannello Amministrazione");

    // menu opzioni

    pannello_opzioni=new menu_amministrazione(this);

    // scroll area

    scroll_area=new QScrollArea(this);
    scroll_area->setHorizontalScrollBarPolicy( Qt::ScrollBarAsNeeded);
    scroll_area->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn);
    scroll_area->setWidgetResizable(true);
    scroll_area->setFrameStyle(QFrame::NoFrame);
    scroll_area->setMaximumHeight(530);


    pagina_aggiunta_utente= new aggiunta_utente();
    scroll_area->setWidget(pagina_aggiunta_utente);

    //creo il layout a due colonne, sx menu, dx area lavoro
    layout_due_colonne= new QHBoxLayout(this);
    layout_due_colonne->addWidget(pannello_opzioni);
    layout_due_colonne->addWidget(scroll_area);
}

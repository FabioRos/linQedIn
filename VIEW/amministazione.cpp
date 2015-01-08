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

    /*PROVA PROVA PROVA*/

    pagina_aggiunta_utente= new aggiunta_utente();
    scroll_area->setWidget(pagina_aggiunta_utente);
   /* QWidget* prova_container= new QWidget;
    scroll_area->setWidget(prova_container);    //!! si fa cosi per aggiungere widgets ad una scroll area!!!
    QVBoxLayout* l= new QVBoxLayout(prova_container);
    menu_amministrazione* prova= new menu_amministrazione(scroll_area);

    menu_amministrazione* prova1= new menu_amministrazione(scroll_area);

    menu_amministrazione* prova2= new menu_amministrazione(scroll_area);

    l->addWidget(prova);
    l->addWidget(prova1);
    l->addWidget(prova2);
*/
    /*PROVA PROVA PROVA*/


    //creo il layout a due colonne, sx menu, dx area lavoro
    layout_due_colonne= new QHBoxLayout(this);
    layout_due_colonne->addWidget(pannello_opzioni);
    layout_due_colonne->addWidget(scroll_area);
}

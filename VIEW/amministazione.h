#ifndef AMMINISTAZIONE_H
#define AMMINISTAZIONE_H
#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QErrorMessage>
#include <QScrollArea>
#include "menu_amministrazione.h"
#include "aggiunta_utente.h"
#include "modulo_visualizzazione_utenti.h"
#include "./CONTROLLER/admin_controller.h"

class amministazione: public QWidget
{private:
    Q_OBJECT
    QHBoxLayout  *layout_due_colonne;
    menu_amministrazione* pannello_opzioni;
    QScrollArea* scroll_area;
    aggiunta_utente* pagina_aggiunta_utente;
    modulo_visualizzazione_utenti* pagina_visualizzazione_utenti;
public:
    amministazione(QWidget* =0);    //QWidget* =0 sempre
public slots:
    void mostra_pag_aggiunta_utenti();
    void mostra_pag_visualizzazione_utenti();
};

#endif // AMMINISTAZIONE_H

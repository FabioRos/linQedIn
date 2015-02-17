#ifndef AMMINISTRAZIONE_H
#define AMMINISTRAZIONE_H

#include "aggiunta_utente.h"
#include "modulo_rimozione_utenti.h"
#include "cambia_tipo_utente.h"
#include "admin_gestisci_tariffe.h"
#include "admin_cerca.h"

#include <QWidget>
#include <QLayout>
#include <QMessageBox>
#include <QErrorMessage>
#include <QScrollArea>

//class modulo_visualizzazione_utenti;

class menu_amministrazione;
class amministrazione: public QWidget
{private:
    Q_OBJECT
    users_repository* ptr_repository;   //read_only
    QHBoxLayout  *layout_due_colonne;
    menu_amministrazione* pannello_opzioni;
    QScrollArea* scroll_area;
    aggiunta_utente* pagina_aggiunta_utente;
    modulo_visualizzazione_utenti* pagina_visualizzazione_utenti;
    modulo_rimozione_utenti* pagina_rimozione_utenti;
    cambia_tipo_utente* pagina_cambia_tipo_utente;
    admin_gestisci_tariffe* pagina_gestione_tariffe;
public:
    amministrazione( users_repository* =0, QWidget* =0);    //QWidget* =0 sempre
    ~amministrazione();
public slots:
    void mostra_pag_aggiunta_utenti();
    void mostra_pag_visualizzazione_utenti();
    void mostra_pag_rimozione_utenti();
    void mostra_pag_cambio_tipo_utenti();
    void mostra_pag_gestione_tariffe();
    void mostra_pag_ricerca();
    void refresh();
};

#endif // AMMINISTRAZIONE_H

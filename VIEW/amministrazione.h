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
#include "modulo_rimozione_utenti.h"
#include "./CONTROLLER/admin_controller.h"

#include "./MODEL/users_repository.h"

class amministrazione: public QWidget
{private:
    Q_OBJECT
    QHBoxLayout  *layout_due_colonne;
    menu_amministrazione* pannello_opzioni;
    QScrollArea* scroll_area;
    aggiunta_utente* pagina_aggiunta_utente;
    modulo_visualizzazione_utenti* pagina_visualizzazione_utenti;
    modulo_rimozione_utenti* pagina_rimozione_utenti;
    users_repository* ptr_repository;   //read_only

public:
    amministrazione( users_repository* =0, QWidget* =0);    //QWidget* =0 sempre
    ~amministrazione();
public slots:
    void mostra_pag_aggiunta_utenti();
    void mostra_pag_visualizzazione_utenti();
    void mostra_pag_rimozione_utenti();
    void refresh();
};

#endif // AMMINISTAZIONE_H

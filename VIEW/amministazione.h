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

class amministazione: public QWidget
{private:
    Q_OBJECT
    QHBoxLayout  *layout_due_colonne;
    menu_amministrazione* pannello_opzioni;
    QScrollArea* scroll_area;
    aggiunta_utente* pagina_aggiunta_utente;
public:
    amministazione(QWidget* =0);    //QWidget* =0 sempre
};

#endif // AMMINISTAZIONE_H

#ifndef AMMINISTAZIONE_H
#define AMMINISTAZIONE_H
#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QErrorMessage>
#include "menu_amministrazione.h"

class amministazione: public QWidget
{private:
    Q_OBJECT
    QPushButton* btn1, *btn2;
    QPushButton* exit;
    QVBoxLayout *main_layout;
    QHBoxLayout *layout_I_O;
    //per esseri sicuri di salvare/caricare
    QMessageBox*sicuro_caricare;
    QErrorMessage* sicuro_salvare;
    menu_amministrazione* pannello_opzioni;
public:
    amministazione(QWidget* =0);    //QWidget* =0 sempre
};

#endif // AMMINISTAZIONE_H

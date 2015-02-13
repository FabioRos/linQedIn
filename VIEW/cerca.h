#ifndef CERCA_H
#define CERCA_H


#include "modulo_visualizzazione_utenti.h"
#include "profilo_popup.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QMessageBox>


class cerca : public QWidget{
    Q_OBJECT
private:
    users_repository* ptr_repository;
    QLabel* lbl_titolo,*lbl_how_to;
    modulo_visualizzazione_utenti* tabella;
    QLineEdit* input_ricerca;
    QVBoxLayout * layout_vericale;
    std::string username_corrente;

public:
    explicit cerca(users_repository*,const std::string& usr,QWidget *parent = 0);

signals:

public slots:
    void popola(QString qs);
    void esplodi_opzioni(const int& r,const int& c);
};

#endif // CERCA_H

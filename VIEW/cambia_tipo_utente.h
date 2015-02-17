#ifndef CAMBIA_TIPO_UTENTE_H
#define CAMBIA_TIPO_UTENTE_H


#include "modulo_visualizzazione_utenti.h"
#include "popup_cambia_tipo_utente.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>


class cambia_tipo_utente : public QWidget{
    Q_OBJECT
private:
    users_repository* ptr_repository;
    QLabel* lbl_titolo;
    modulo_visualizzazione_utenti* tabella;
    QPushButton* btn_salva;
    QLineEdit* input_ricerca;
    QVBoxLayout * layout_vericale;
public:
    explicit cambia_tipo_utente(users_repository*,QWidget *parent = 0);

signals:

public slots:
    void popola(QString);
     void esplodi_opzioni(const int& r,const int& c);

};

#endif // CAMBIA_TIPO_UTENTE_H

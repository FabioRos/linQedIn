#ifndef AGGIUNTA_UTENTE_H
#define AGGIUNTA_UTENTE_H

#include <QWidget>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include "modulo_lingua.h"
#include "modulo_competenza.h"
#include "modulo_esperienza_professionale.h"

#include "./MODEL/users_repository.h"

class aggiunta_utente : public QWidget{
    Q_OBJECT
private:
    users_repository* ptr_repository;
public:
    explicit aggiunta_utente(users_repository* =0,QWidget *parent = 0);
    QFormLayout* layout_form;
    QLineEdit* nome, *cognome, *username;//, *txt_nuova_competenza;
    QPushButton* btn_conferma;
    QComboBox* tipologia_account;
    modulo_lingua* blocco_lingua;
    modulo_competenza* blocco_competenza;
    modulo_esperienza_professionale* blocco_esperienza_professionale;

signals:

public slots:
    void aggiungi_utente_a_db();// da testare //INCOMPLETO!!!
};

#endif // AGGIUNTA_UTENTE_H

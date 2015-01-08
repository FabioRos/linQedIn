#ifndef AGGIUNTA_UTENTE_H
#define AGGIUNTA_UTENTE_H

#include <QWidget>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include "modulo_lingua.h"

class aggiunta_utente : public QWidget
{
    Q_OBJECT
public:
    explicit aggiunta_utente(QWidget *parent = 0);
    QFormLayout* layout_form;
    QLabel* lbl_nome, *lbl_cognome, *lbl_username, *lbl_competenze;
    QLineEdit* nome, *cognome, *username, *txt_nuova_competenza;
    QPushButton* btn_conferma, *btn_nuova_competenza, *btn_rimuovi_competenze;
    QListWidget* competenze;

    modulo_lingua* blocco_lingua;//FARE ANCHE PER COMPETENZE

signals:

public slots:
    void aggiungi_competenza();
    void rimuovi_competenza();
};

#endif // AGGIUNTA_UTENTE_H

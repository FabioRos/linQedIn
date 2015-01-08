#ifndef AGGIUNTA_UTENTE_H
#define AGGIUNTA_UTENTE_H

#include <QWidget>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

class aggiunta_utente : public QWidget
{
    Q_OBJECT
public:
    explicit aggiunta_utente(QWidget *parent = 0);
    QFormLayout* layout_form;
    QLabel* lbl_nome, *lbl_cognome;
    QLineEdit* nome, *cognome;
    QPushButton* btn_conferma;

signals:

public slots:

};

#endif // AGGIUNTA_UTENTE_H

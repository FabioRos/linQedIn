#ifndef POPUP_CAMBIA_TIPO_UTENTE_H
#define POPUP_CAMBIA_TIPO_UTENTE_H

#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "../CONTROLLER/aggiungi_modifica_utenti.h"

class popup_cambia_tipo_utente : public QWidget{
    Q_OBJECT
private:
    users_repository* ptr_repository;
    std::string username, nuovo_tipo;
    QComboBox* combo_tipo;
    QStringList tipi_account;
    QVBoxLayout* layout;
    QHBoxLayout* layout_bottoni;
    QPushButton* btn_conferma, *btn_annulla;
public:

public:
    explicit popup_cambia_tipo_utente(const std::string& username,
                                      users_repository* ptr_repo, QWidget *parent = 0);

signals:

public slots:
    void aggiorna_tipo(QString);   //aggiorna la variabile di classe
    void cambia_tipo();     //invoca il metodo del controller che fa effettivamente la modifica
};

#endif // POPUP_CAMBIA_TIPO_UTENTE_H

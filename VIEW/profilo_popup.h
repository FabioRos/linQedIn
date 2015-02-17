#ifndef PROFILO_POPUP_H
#define PROFILO_POPUP_H

#include <QWidget>
#include <QScrollArea>

#include "client_profilo.h"

class profilo_popup : public QWidget{
    Q_OBJECT
private:
    QLabel* titolo;
    std::string username_corrente;
    std::string username_da_visualizzare;
    users_repository *ptr_repository;
    client_profilo* informazioni;
    QScrollArea* frame_principale;
    QPushButton* btn_aggiungi_a_rete;
    QPushButton* btn_rimuovi_dalla_rete;
    aggiungi_modifica_utenti* controller;
    QVBoxLayout* layout;
    void inizializza();
public:
    explicit profilo_popup(users_repository*,const std::string& corrente,const std::string& target,QWidget *parent = 0);
    explicit profilo_popup(users_repository*,const std::string& target,QWidget *parent = 0);

signals:

public slots:
    void aggiungi_a_rete();
    void rimuovi_dalla_rete();  // da testare
};

#endif // PROFILO_POPUP_H

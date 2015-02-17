#ifndef CLIENT_ENVIRONMENT_H
#define CLIENT_ENVIRONMENT_H

#include <QApplication>    //per qApp, puntatore statico all'applicazione up.
#include "client_profilo.h"

#include "login.h"
#include "finestraprincipale.h"
#include "cerca.h"
#include "client_rete.h"
#include "client_modifica_cc.h"
#include "client_manage_esperienza.h"



#include <QLayout>
#include <QScrollArea>

class client_environment : public QWidget{
private:
    Q_OBJECT
    QPushButton* btn_profilo, *btn_rete, *btn_log_out, *btn_cerca, *btn_modifica_cc;
    QPushButton* btn_esperienze;
    QHBoxLayout* layout_due_colonne;
    QVBoxLayout* layout_menu;
    QScrollArea* scroll_area;
    users_repository* ptr_repository;
    std::string username_corrente;
    client_controller* controller;
public:
    client_environment(users_repository* , const std::string& utente_corrente, QWidget* parent =0);
    ~client_environment();
public slots:
    void log_out();
    void mostra_profilo();
    void mostra_pag_ricerca();
    void mostra_pag_rete();
    void mostra_pag_modifica_cc();
    void mostra_pag_esperienze();
};

#endif // CLIENT_ENVIRONMENT_H

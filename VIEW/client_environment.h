#ifndef CLIENT_ENVIRONMENT_H
#define CLIENT_ENVIRONMENT_H

#include <QApplication>    //per qApp, puntatore statico all'applicazione up.
#include "client_profilo.h"

#include "login.h"
#include "finestraprincipale.h"
#include "cerca.h"

#include <QLayout>
#include <QScrollArea>

class client_environment : public QWidget{
private:
    Q_OBJECT
    QPushButton* btn_profilo, *btn_rete, *btn_log_out, *btn_cerca;
    QHBoxLayout* layout_due_colonne;
    QVBoxLayout* layout_menu;
    QScrollArea* scroll_area;
    users_repository* ptr_repository;
    std::string username_corrente;
public:
    client_environment(users_repository* , const std::string& utente_corrente, QWidget* parent =0);
    ~client_environment();
public slots:
    void log_out();
    void mostra_profilo();
    void mostra_pag_ricerca();
};

#endif // CLIENT_ENVIRONMENT_H

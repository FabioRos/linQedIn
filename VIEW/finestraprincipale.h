#ifndef FINESTRAPRINCIPALE_H
#define FINESTRAPRINCIPALE_H

#include <QMainWindow>

#include "client_manager.h"
#include "tool_bar.h"
#include "tab_wrapper.h"

#include "./MODEL/users_repository.h"

class FinestraPrincipale : public QMainWindow{
    Q_OBJECT
    QVBoxLayout* layout_verticale; //sopra:tab, sotto barra
    Tab_wrapper* tab_pricipale;
    tool_bar* tb;
    QWidget* contenitore;
    users_repository* ptr_repository;
public:
    FinestraPrincipale(users_repository* ,bool test_mode =true,QWidget *parent = 0);
    FinestraPrincipale(DB* ,bool test_mode =true,QWidget *parent = 0);
    ~FinestraPrincipale();

public slots:
};

#endif // FINESTRAPRINCIPALE_H

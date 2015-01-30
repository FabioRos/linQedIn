#ifndef TAB_WRAPPER_H
#define TAB_WRAPPER_H

#include <QWidget>
#include <QTabWidget>
#include <QHBoxLayout>

#include "client_manager.h"
#include "amministrazione.h"

#include "MODEL/users_repository.h"

class Tab_wrapper : public QWidget{
private:

    Q_OBJECT
    QTabWidget* emulatore_browser;  //Layout a schede
    QHBoxLayout* layout_browser;    //lauout orizzontale barra sx e dx dentro le tab
    users_repository* ptr_repository;
    //new
    client_manager* view_client;
    amministrazione* view_amministrazione;
public:
    explicit Tab_wrapper(users_repository* =0,QWidget *parent = 0);
    ~Tab_wrapper();

signals:

public slots:

};

#endif // TAB_WRAPPER_H

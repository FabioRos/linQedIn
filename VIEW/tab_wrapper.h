#ifndef TAB_WRAPPER_H
#define TAB_WRAPPER_H

#include <QWidget>
#include <QTabWidget>
#include <QHBoxLayout>

#include "client_manager.h"
#include "amministazione.h"

class Tab_wrapper : public QWidget{
private:

    Q_OBJECT
    QTabWidget* emulatore_browser;  //Layout a schede
    QHBoxLayout* layout_browser;    //lauout orizzontale barra sx e dx dentro le tab

    //new
    client_manager* view_client;
    amministazione* view_amministrazione;
public:
    explicit Tab_wrapper(QWidget *parent = 0);

signals:

public slots:

};

#endif // TAB_WRAPPER_H

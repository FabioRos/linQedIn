#ifndef FINESTRAPRINCIPALE_H
#define FINESTRAPRINCIPALE_H

#include <QMainWindow>

#include "client_manager.h"

class FinestraPrincipale : public QMainWindow{
    Q_OBJECT
    QTabWidget* emulatore_browser;
    QHBoxLayout* layout_browser;

    //new
    client_manager* view_client;

public:
    FinestraPrincipale(QWidget *parent = 0);
    ~FinestraPrincipale();
public slots:
};

#endif // FINESTRAPRINCIPALE_H

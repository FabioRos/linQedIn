#ifndef FINESTRAPRINCIPALE_H
#define FINESTRAPRINCIPALE_H

#include <QMainWindow>

#include "VIEW/amministazione.h"

class FinestraPrincipale : public QMainWindow
{
    Q_OBJECT

public:
    FinestraPrincipale(QWidget *parent = 0);
    ~FinestraPrincipale();
};

#endif // FINESTRAPRINCIPALE_H

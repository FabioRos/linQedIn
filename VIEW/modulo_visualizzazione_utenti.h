#ifndef MODULO_VISUALIZZAZIONE_DATI_H
#define MODULO_VISUALIZZAZIONE_DATI_H

#include <QWidget>
#include <QTableWidget>
#include <QStringList>
#include "./CONTROLLER/admin_controller.h"

class modulo_visualizzazione_utenti : public QWidget{
private:
    Q_OBJECT
    QTableWidget* tabella;
protected:
    void inizializza_tabella();

public:
    explicit modulo_visualizzazione_utenti(QWidget *parent = 0);
    void popola_tabella(std::list<smart_utente*>);
signals:

public slots:

};

#endif // MODULO_VISUALIZZAZIONE_DATI_H

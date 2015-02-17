#ifndef ADMIN_CERCA_H
#define ADMIN_CERCA_H

#include <QLineEdit>
#include <QVBoxLayout>
#include "modulo_visualizzazione_utenti.h"
#include "profilo_popup.h"

class admin_cerca : public QWidget{
    Q_OBJECT
private:
    users_repository* ptr_repository;
    modulo_visualizzazione_utenti* tabella;
    QLineEdit* input_ricerca;
    QVBoxLayout* layout;
public:
    explicit admin_cerca(users_repository* ptr_repo, QWidget *parent = 0);

signals:

public slots:
    void popola(QString qs);
    void esplodi_opzioni(const int& r,const int& c);
};

#endif // ADMIN_CERCA_H

#ifndef MODULO_VISUALIZZAZIONE_DATI_H
#define MODULO_VISUALIZZAZIONE_DATI_H

#include "./CONTROLLER/admin_controller.h"

#include <QWidget>
#include <QTableWidget>
#include <QStringList>



class modulo_visualizzazione_utenti : public QWidget{
private:
    Q_OBJECT
    QTableWidget* tabella;
    users_repository* ptr_repository;
protected:
    void inizializza_tabella();
    QTableWidget* get_ptr_tabella() const;

public:
    explicit modulo_visualizzazione_utenti(users_repository* =0, QWidget *parent = 0);
    void refresh();
    void inserisci_riga(utente* riga,int indice_riga);
    void popola_tabella(std::list<smart_utente*>);
    ~modulo_visualizzazione_utenti();
signals:

public slots:
    //void seleziona_tutta_la_riga(int indice_riga);

};

#endif // MODULO_VISUALIZZAZIONE_DATI_H

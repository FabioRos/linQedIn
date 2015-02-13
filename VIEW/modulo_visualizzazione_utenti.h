#ifndef MODULO_VISUALIZZAZIONE_UTENTI_H
#define MODULO_VISUALIZZAZIONE_UTENTI_H

#include "../CONTROLLER/admin_controller.h"


#include <QWidget>
#include <QTableWidget>
#include <QStringList>
#include <QHeaderView>



class modulo_visualizzazione_utenti : public QWidget{
private:
    Q_OBJECT
    QTableWidget* tabella;
    users_repository* ptr_repository;
    int numero_elementi;

public:
    explicit modulo_visualizzazione_utenti(users_repository* =0, QWidget *parent = 0);
    void refresh();
    void inserisci_riga(utente* riga,int indice_riga);
    void popola_tabella(std::list<smart_utente*>);
    void rimuovi_tutti();
    QTableWidget* get_ptr_tabella() const;
    ~modulo_visualizzazione_utenti();
    void inizializza_tabella();
signals:

public slots:
    //void seleziona_tutta_la_riga(int indice_riga);

};

#endif // MODULO_VISUALIZZAZIONE_UTENTI_H

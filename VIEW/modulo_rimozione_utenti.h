#ifndef MODULO_RIMOZIONE_UTENTI_H
#define MODULO_RIMOZIONE_UTENTI_H

#include "modulo_visualizzazione_utenti.h"

#include <QPushButton>

class modulo_rimozione_utenti : public modulo_visualizzazione_utenti {
    Q_OBJECT
private:
    QTableWidget* ptr_tabella;
    QPushButton* btn_rimuovi_utente;
    admin_controller* controller;

public:
    explicit modulo_rimozione_utenti(users_repository* =0,admin_controller* =0, QWidget *parent = 0);
    std::list<std::string> get_selected_usernames() const;
        ~modulo_rimozione_utenti();
signals:

public slots:
    void seleziona_riga(int,int) const;
    void rimuovi_utenti();
};

#endif // MODULO_RIMOZIONE_UTENTI_H

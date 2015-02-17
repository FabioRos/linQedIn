#ifndef CLIENT_MANAGE_ESPERIENZA_H
#define CLIENT_MANAGE_ESPERIENZA_H

#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QCalendarWidget>

#include <QPushButton>

#include "../CONTROLLER/aggiungi_modifica_utenti.h"

class client_manage_esperienza : public QWidget{
    Q_OBJECT
private:
    users_repository* ptr_repository;
    std::string username_corrente;
    void aggiungi_controlli_esperienza_professionale();
    QGridLayout* layout_top;
    QLineEdit* input_nuova_azienda, *input_nuova_posizione, *input_nuovo_luogo;
    QTextEdit* input_nuova_descrizione;
    QCalendarWidget* cal_data_inizio,*cal_data_fine;
    QPushButton* btn_inserisci_esperienza;
    aggiungi_modifica_utenti* edit_controller;
public:
    explicit client_manage_esperienza(users_repository* ptr_repo, const std::string& usn, QWidget *parent = 0);

signals:

public slots:
    void aggiungi_esperienza();
    void messaggio_conferma();

};

#endif // CLIENT_MANAGE_ESPERIENZA_H

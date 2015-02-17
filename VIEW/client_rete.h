#ifndef CLIENT_RETE_H
#define CLIENT_RETE_H

#include "modulo_visualizzazione_utenti.h"
#include "popup_rimuovi_utente_da_rete.h"
#include <QVBoxLayout>

class client_rete : public QWidget{
    Q_OBJECT
private:
    std::string utente_corrente;
    users_repository* ptr_repository;
    modulo_visualizzazione_utenti* tabella;
    std::list<smart_utente*> get_all_smu_rete() const;
    QVBoxLayout* layout;
public:
    explicit client_rete(const std::string& username,users_repository* ptr_repo ,QWidget *parent = 0);

signals:

public slots:
    void esplodi_opzioni(const int &r, const int &c);
    void refresh();
};

#endif // CLIENT_RETE_H

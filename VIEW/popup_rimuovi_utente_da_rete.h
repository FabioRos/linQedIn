#ifndef POPUP_RIMUOVI_UTENTE_DA_RETE_H
#define POPUP_RIMUOVI_UTENTE_DA_RETE_H

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>


#include "../CONTROLLER/aggiungi_modifica_utenti.h"

class popup_rimuovi_utente_da_rete : public QWidget{
    Q_OBJECT
private:
      std::string username_corrente, username_da_rimuovere;
      users_repository* ptr_repository;
      QVBoxLayout* layout;
      QHBoxLayout* layout_bottoni;
      QLabel* testo;
      QPushButton* btn_conferma, *btn_annulla;
      bool tutto_bene;
public:
    explicit popup_rimuovi_utente_da_rete(const std::string& username_corrente,
                                          const std::string& username_da_rimuovere,
                                          users_repository* ptr_repo, QWidget *parent = 0);

signals:

public slots:
    void rimuovi_da_rete();
    void rimosso_con_successo();
};

#endif // POPUP_RIMUOVI_UTENTE_DA_RETE_H

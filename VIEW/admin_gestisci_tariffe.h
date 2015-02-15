#ifndef ADMIN_GESTISCI_TARIFFE_H
#define ADMIN_GESTISCI_TARIFFE_H

#include <QLabel>
#include <QPushButton>
#include <QFormLayout>
#include <QDoubleSpinBox>

#include "../MODEL/users_repository.h"

class admin_gestisci_tariffe : public QWidget{
    Q_OBJECT
private:
    users_repository* ptr_repository;
    QLabel* lbl_titolo;
    QPushButton* btn_salva_modifiche;
    QDoubleSpinBox* input_tariffa_business, *input_tariffa_executive;
    QFormLayout* layout;
public:
    explicit admin_gestisci_tariffe(users_repository* ptr_repo, QWidget *parent = 0);

signals:

public slots:
    void salva();
};

#endif // ADMIN_GESTISCI_TARIFFE_H

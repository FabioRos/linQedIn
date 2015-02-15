#ifndef CLIENT_MODIFICA_CC_H
#define CLIENT_MODIFICA_CC_H

#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QFormLayout>
#include "../CONTROLLER/client_controller.h"

#include "../MODEL/users_repository.h"

class client_modifica_cc : public QWidget{
    Q_OBJECT
private:
    bool is_a_pagamento;
    users_repository* ptr_repository;
    std::string username_;
    QLineEdit* input_cc;
    QPushButton* btn_conferma;
    QFormLayout* layout;
    client_controller* controller;
public:
    explicit client_modifica_cc(users_repository* ,const std::string& username ,QWidget *parent = 0);

signals:

public slots:
    void salva();
};

#endif // CLIENT_MODIFICA_CC_H

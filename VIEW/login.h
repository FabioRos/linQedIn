#ifndef LOGIN_H
#define LOGIN_H

#include "client_environment.h"
#include "./MODEL/users_repository.h"

#include <QHBoxLayout>

class login : public QWidget{
private:
    Q_OBJECT

    QLineEdit* input_username;
    QVBoxLayout* layout_verticale;
    QPushButton* btn_login;
    users_repository* ptr_repository;
public:
    login(users_repository*,QWidget* parent =0);

public slots:
    void login_autorizzato();
};

#endif // LOGIN_H

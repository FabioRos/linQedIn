#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

#include <QWidget>


#include "amministrazione.h"
#include "testing.h"
#include "login.h"
#include "client_enviroment.h"

class client_manager : public QWidget{
private:
    Q_OBJECT
    users_repository* ptr_repository;
   // QHBoxLayout* layout_browser;
public:
    explicit client_manager(users_repository*, QWidget *parent = 0);

signals:

public slots:

};

#endif // CLIENT_MANAGER_H

#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

#include <QWidget>


#include "amministazione.h"
#include "testing.h"
#include "login.h"
#include "menu_bar.h"

class client_manager : public QWidget{
private:
    Q_OBJECT
   // QHBoxLayout* layout_browser;
public:
    explicit client_manager(QWidget *parent = 0);

signals:

public slots:

};

#endif // CLIENT_MANAGER_H

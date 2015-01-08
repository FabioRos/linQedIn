#include "client_manager.h"

client_manager::client_manager(QWidget *parent) : QWidget(parent){
    //this->setGeometry(10,10,500,550);
    //this->setMinimumWidth(650);
    //varie view da chiamare
    login* view_login=new login(this);
    view_login->show();
}

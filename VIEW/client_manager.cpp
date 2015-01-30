#include "client_manager.h"

client_manager::client_manager(users_repository* r, QWidget *parent) :
    QWidget(parent), ptr_repository(r){
    //this->setGeometry(10,10,500,550);
    //this->setMinimumWidth(650);
    //varie view da chiamare
    login* view_login=new login(ptr_repository,this);
    view_login->show();
}

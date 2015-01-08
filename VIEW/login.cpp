#include "login.h"
#include "menu_bar.h"

/* TEMP */
#include <iostream>
/**/


login::login(QWidget *parent): QWidget(parent){
    //CAMPI PROPRI
    input_username = new QLineEdit(this);
    layout_login = new QHBoxLayout(this);
    btn_login = new QPushButton("Login",this);
    layout_login->addWidget(btn_login);
    layout_login->addWidget(input_username);

    connect(btn_login,SIGNAL(clicked()),this, SLOT(login_autorizzato()));


}

void login::login_autorizzato(){
    //if autorizzato
    this->hide();
    menu_bar* mb=new menu_bar(static_cast<QWidget*>(parent()));
    mb->show();
}



#include "login.h"
#include "client_enviroment.h"
#include "./CONTROLLER/client_controller.h"
#include <QMessageBox>


login::login(users_repository*repo, QWidget *parent):
    ptr_repository(repo),QWidget(parent){
    //CAMPI PROPRI
    input_username = new QLineEdit(this);
    layout_login = new QHBoxLayout(this);
    btn_login = new QPushButton("Login",this);
    layout_login->addWidget(btn_login);
    layout_login->addWidget(input_username);

    connect(btn_login,SIGNAL(clicked()),this, SLOT(login_autorizzato()));


}

void login::login_autorizzato(){
    std::string user=input_username->text().toStdString();
    client_controller cc(ptr_repository);
    if(cc.login_autorizzato(user)){
        this->hide();
        client_enviroment* mb=new client_enviroment(ptr_repository,user, static_cast<QWidget*>(parent()));
        mb->show();
    }else{
        QMessageBox* l=new QMessageBox(QMessageBox::Critical,"Attenzione!",
                                       "L\'username inserito non esiste in questo database.");
        l->setGeometry(200,200,400,60);
        l->show();
    }
}



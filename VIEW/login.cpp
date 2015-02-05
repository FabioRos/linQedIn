#include "login.h"


login::login(users_repository*repo, QWidget *parent):
    ptr_repository(repo),QWidget(parent){
    //CAMPI PROPRI
    input_username = new QLineEdit(this);
    input_username->setStyleSheet("margin-top:100px;margin-left:250px;height:30px;width:300px;");
    input_username->setAlignment(Qt::AlignCenter);
    btn_login = new QPushButton("Login",this);
    btn_login->setStyleSheet("margin-left:250px;height:30px;width:300px");

//    layout_login->addWidget(input_username);
//    layout_login->addWidget(btn_login);

    layout_verticale= new QVBoxLayout(this);

    layout_verticale->addWidget(input_username);
    layout_verticale->addWidget(btn_login);


    connect(input_username,SIGNAL(returnPressed()),btn_login,SIGNAL(clicked()));
    connect(btn_login,SIGNAL(clicked()),this, SLOT(login_autorizzato()));


}

void login::login_autorizzato(){
    std::string user=input_username->text().toStdString();
    client_controller cc(ptr_repository);
    if(cc.login_autorizzato(user)){
        this->hide();
        client_environment* mb=new client_environment(ptr_repository,user, static_cast<QWidget*>(parent()));
        mb->show();
    }else{
        QMessageBox* l=new QMessageBox(QMessageBox::Critical,"Attenzione!",
                                       "L\'username inserito non esiste in questo database.");
        l->setGeometry(200,200,400,60);
        l->show();
    }
}



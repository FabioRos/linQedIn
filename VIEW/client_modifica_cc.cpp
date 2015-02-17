#include "client_modifica_cc.h"

client_modifica_cc::client_modifica_cc(users_repository* repo, const std::string& user, QWidget *parent) :
    QWidget(parent), ptr_repository(repo), username_(user){
    is_a_pagamento=false;
    btn_conferma= new QPushButton("conferma carta",this);
    controller=new client_controller(ptr_repository);
    input_cc= new QLineEdit();
    if(controller->isAPagamento(username_)!=0){
        is_a_pagamento=true;
    }
    layout= new QFormLayout(this);
    layout->setSpacing(20);
    layout->addRow(new QLabel("<center><b><h3>MODIFICA CARTA DI CREDITO</h3></b></center>"));
    layout->addRow("Nuova Carta: ",input_cc);
    layout->addRow(btn_conferma);

    connect(btn_conferma, SIGNAL(clicked()),this,SLOT(salva()));

}

void client_modifica_cc::salva(){
    if(is_a_pagamento){
        controller->isAPagamento(username_)->set_carta_di_credito(input_cc->text().toStdString());
    }
}

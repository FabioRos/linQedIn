#include "admin_gestisci_tariffe.h"

admin_gestisci_tariffe::admin_gestisci_tariffe(users_repository* ptr_repo,QWidget *parent) :
    ptr_repository(ptr_repo),QWidget(parent){
    lbl_titolo= new QLabel(QString("<b><center><h3>MODIFICA TARIFFAZIONI</h3></center></b>"),this);
    btn_salva_modifiche = new QPushButton("salva_modifiche",this);
    input_tariffa_business= new QDoubleSpinBox(this);
    input_tariffa_executive= new QDoubleSpinBox(this);

    //precisione
    input_tariffa_business->setSingleStep(0.01);
    input_tariffa_executive->setSingleStep(0.01);
    input_tariffa_business->setMaximum(999999999);
    input_tariffa_executive->setMaximum(999999999);

    //inizializzo
    input_tariffa_business->setValue(ptr_repository->get_tariffa_business());
    input_tariffa_executive->setValue(ptr_repository->get_tariffa_executive());


    layout=new QFormLayout(this);
    layout->setSpacing(20);
    layout->addRow(lbl_titolo);
    layout->addRow("Tariffazione business: ",input_tariffa_business);
    layout->addRow("Tariffazione executive: ",input_tariffa_executive);
    layout->addRow(btn_salva_modifiche);

    connect(btn_salva_modifiche,SIGNAL(clicked()),this,SLOT(salva()));
}

void admin_gestisci_tariffe::salva(){
    ptr_repository->set_tariffa_business(input_tariffa_business->value());
    ptr_repository->set_tariffa_executive(input_tariffa_executive->value());
}

#include "client_environment.h"

client_environment::client_environment(users_repository* repo, const std::string& uc, QWidget *parent):
    ptr_repository(repo),username_corrente(uc),QWidget(parent){

    //Inizializzazione campi dati
    QWidget* menu=new QWidget;
    btn_profilo=new QPushButton("Profilo",menu);
    btn_rete=new QPushButton("Rete",menu);
    btn_log_out=new QPushButton("Log-out",menu);
    btn_cerca=new QPushButton("Cerca",menu);
    btn_esperienze=new QPushButton("Esperienze",menu);
    this->setGeometry(0,0,750,500);
    scroll_area=new QScrollArea(this);
    controller= new client_controller(ptr_repository);
   // scroll_area->setGeometry(200,10,510,500);

    scroll_area->setHorizontalScrollBarPolicy( Qt::ScrollBarAsNeeded);
    scroll_area->setVerticalScrollBarPolicy( Qt::ScrollBarAsNeeded);
    scroll_area->setWidgetResizable(true);


    //creo il layout a due colonne, sx menu, dx area lavoro
    layout_due_colonne= new QHBoxLayout(this);
    layout_due_colonne->addWidget(menu);
    layout_due_colonne->addWidget(scroll_area);




    //istanzio il layout
    layout_menu=new QVBoxLayout(menu);

    //aggiungo i widgets al layout
    layout_menu->addWidget(btn_profilo);
    layout_menu->addWidget(btn_rete);
    layout_menu->addWidget(btn_log_out);
    layout_menu->addWidget(btn_cerca);
    if(controller->isAPagamento(username_corrente)){
        btn_modifica_cc =new QPushButton("carta di credito",menu);
        layout_menu->addWidget(btn_modifica_cc);
        connect(btn_modifica_cc,SIGNAL(clicked()),this,SLOT(mostra_pag_modifica_cc()));
    }
    layout_menu->addWidget(btn_esperienze);

//    QHBoxLayout layout_aux;
//    layout_aux.addWidget(scroll_area);
//    layout_menu->addLayout(&layout_aux);


    //faccio le connessioni
    connect(btn_profilo,SIGNAL(clicked()),this,SLOT(mostra_profilo()));
    connect(btn_cerca,SIGNAL(clicked()),this,SLOT(mostra_pag_ricerca()));
    connect(btn_log_out,SIGNAL(clicked()),this,SLOT(log_out()));
    connect(btn_rete,SIGNAL(clicked()),this,SLOT(mostra_pag_rete()));
    connect(btn_esperienze,SIGNAL(clicked()),this,SLOT(mostra_pag_esperienze()));

}

client_environment::~client_environment(){
    delete btn_profilo;
    delete btn_rete;
    delete btn_log_out;
    delete btn_cerca;
    delete layout_menu;
}

void client_environment::log_out(){
    this->hide();
    login* login_view=new login(ptr_repository,static_cast<QWidget*>(parent()));
    login_view->show();
}

void client_environment::mostra_profilo(){
    //pagina_profilo = new client_profilo(ptr_repository,username_corrente,this);
    scroll_area->setWidget(new client_profilo(ptr_repository,username_corrente,this));
}

void client_environment::mostra_pag_ricerca(){
    scroll_area->setWidget(new cerca(ptr_repository,username_corrente,this));
}

void client_environment::mostra_pag_rete(){
   //if(!dynamic_cast<client_rete*>(scroll_area->widget()))
        scroll_area->setWidget(new client_rete(username_corrente,ptr_repository,this));
    // /*new cerca(ptr_repository,username_corrente,this)*/);
}

void client_environment::mostra_pag_modifica_cc(){
    if(!dynamic_cast<client_modifica_cc*>(scroll_area->widget()))
        scroll_area->setWidget(new client_modifica_cc(ptr_repository,username_corrente,this));
}

void client_environment::mostra_pag_esperienze(){
      scroll_area->setWidget(new client_manage_esperienza(ptr_repository,username_corrente,this));

}



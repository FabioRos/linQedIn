#include "tab_wrapper.h"
#include "client_manager.h"

Tab_wrapper::Tab_wrapper(users_repository* repo, QWidget *parent)
    :ptr_repository(repo), QWidget(parent){
    emulatore_browser=new QTabWidget(this);
    //widgets
    view_amministrazione= new amministrazione(repo, emulatore_browser);
    view_client=new client_manager(ptr_repository, emulatore_browser);



    //dimensionamento
    this->setMinimumWidth(800);
    this->setMinimumHeight(600);

    //emulatore_browser->setGeometry(10,0,560,780);

    emulatore_browser->setMinimumWidth(780);
    emulatore_browser->setMinimumHeight(600);

    view_amministrazione->setMinimumHeight(600);

    layout_browser=new QHBoxLayout(emulatore_browser);
    //per mettere a sx il menu ed a dx i risultati dentro alle tab
    emulatore_browser->addTab(view_client,"Client");
    emulatore_browser->addTab(view_amministrazione, "Amministrazione");


}

Tab_wrapper::~Tab_wrapper(){
    delete emulatore_browser;
}

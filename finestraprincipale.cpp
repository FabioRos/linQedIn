#include "finestraprincipale.h"

FinestraPrincipale::FinestraPrincipale(QWidget *parent) : QMainWindow(parent){
    amministazione* view_amministrazione= new amministazione;
    view_amministrazione->show();
}

FinestraPrincipale::~FinestraPrincipale(){}

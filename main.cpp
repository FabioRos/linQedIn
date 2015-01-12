#include "finestraprincipale.h"
#include <QApplication>
//#include <string>
/*___temporaneo___*/
    #include <iostream>
/*________________*/

#include "./TEST/test_manager.h"
/*___temporaneo___*/
void popola(DB*);
/*------------------*/


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    bool opzione=false;
    if(argv[1]){
        std::string arg1_test=argv[1];
        if(arg1_test.compare(std::string("-test"))==0){
            opzione=true;
        }
    }

    FinestraPrincipale w(opzione);
    w.show();

    return a.exec();
}

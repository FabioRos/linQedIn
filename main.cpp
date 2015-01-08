#include "finestraprincipale.h"
#include <QApplication>
//#include <string>
/*___temporaneo___*/
    #include <iostream>
/*________________*/

#include "./TEST/test_manager.h"
//#include "./MODEL/db.h"

int main(int argc, char *argv[])
{
    //std::cout<< argc << " >>>>>>>>>>> "<< argv[0] <<" __ " << argv[1]<<std::endl;
    QApplication a(argc, argv);
    bool opzione=false;
    if(argv[1]){
        std::string arg1_test=argv[1];
        if(arg1_test.compare(std::string("-test"))==0){
            opzione=true;
            //test
            test_manager* tester=new test_manager;
            tester->run_tests();
        }
    }
    FinestraPrincipale w(opzione);
    w.show();




    return a.exec();
}

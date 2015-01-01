#include "finestraprincipale.h"
#include <QApplication>

/*___temporaneo___*/
    #include <iostream>
    #include "data.h"
/*________________*/

#include "test_manager.h"

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    //FinestraPrincipale w;
    //w.show();


    //test
    bool ok=true;
    test_manager* tester=new test_manager;
    ok=tester->run_tests();

    if(ok){

        std::cout<<" \n\n [V] Tutti i test passati. \n\n "<<std::endl;
    }else{
        std::cout<<" \n\n [X] Il programma non ha passato la fase di test. \n\n"<<std::endl;
    }
    //data d(1,1,2005);
    //std::cout<<"\n"<<d.get_giorno()<<'-'<<d.get_mese()<<'-'<<d.get_anno()<<std::endl;
    //std::cout<<"...\n"<<data::sanitize(d)<<"...\n";


    //return a.exec();
}

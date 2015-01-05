#include "finestraprincipale.h"
#include <QApplication>

/*___temporaneo___*/
    #include <iostream>
/*________________*/

#include "./TEST/test_manager.h"
#include "./MODEL/db.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FinestraPrincipale w;
    w.show();


    //test
    test_manager* tester=new test_manager;
    tester->run_tests();

    return a.exec();
}

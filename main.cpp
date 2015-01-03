#include "finestraprincipale.h"
#include <QApplication>

/*___temporaneo___*/
    #include <iostream>
/*________________*/

#include "test_manager.h"
#include "db.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FinestraPrincipale w;
    w.show();


    //test
    test_manager* tester=new test_manager;
    bool ok=tester->run_tests();


    return a.exec();
}

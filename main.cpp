#include "finestraprincipale.h"
#include "./MODEL/input_output.h"
#include <QApplication>

#include "./TEST/test_manager.h"
#include "./MODEL/users_repository.h"

int main(int argc, char *argv[])
{

    //Qui chiamo subito la classe repository così ho il DB pronto!


    QApplication a(argc, argv);
    bool opzione=false;
    if(argv[1]){
        std::string arg1_test=argv[1];
        if(arg1_test.compare(std::string("-test"))==0){
            opzione=true;
        }
    }

    users_repository* db=new users_repository(new DB);
   // DB* db=new DB(*(input_output::carica_da_file()));//carica_dati;
    FinestraPrincipale w(db,opzione);
    w.show();

    return a.exec();
}

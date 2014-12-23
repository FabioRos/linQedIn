#include "test_manager.h"
#include "test_data.h"
#include "test_lingua.h"
#include <iostream>

using std::cout;


test_manager::test_manager(){
    locale=new test;    //0,0,0
}


void test_manager::aggiorna_stato_test(const test* componente_testata){
    if(componente_testata->get_numero_test()==componente_testata->get_numero_test_superati()+
            componente_testata->get_numero_test_falliti()){
        locale->numero_test     += componente_testata->get_numero_test();
        locale->n_test_superati += componente_testata->get_numero_test_superati();
        locale->n_test_falliti  += componente_testata->get_numero_test_falliti();
    }


}

bool test_manager::run_tests(){
    return(this->data_tester() && this->lingua_tester());

}

bool test_manager::data_tester(){
    bool esito=true;
    //al primo fallimento --> esito==False

    //OGGETTO TESTER
    test_data* test_var=new test_data;


    //PRIMO INPUT
    data d();
    test_var->run_tests();
    int tot=test_var->get_numero_test();
    int s=test_var->get_numero_test_superati();
    int f=test_var->get_numero_test_falliti();

    cout<<"\n Tot Test: \t"<< tot <<
          "\n Superati: \t"<< s   <<
          "\n Falliti:  \t"<< f   <<"\n";

    if(f)
        esito=false;



    //--FINE PRIMO INPUT --//

    return esito;
}

bool test_manager::lingua_tester(){

    bool esito=true;
    //al primo fallimento --> esito==False

    //OGGETTO TESTER
    test_lingua* test_var=new test_lingua;


    //PRIMO INPUT
    lingua l();
    test_var->run_tests();
    int tot=test_var->get_numero_test();
    int s=test_var->get_numero_test_superati();
    int f=test_var->get_numero_test_falliti();

    cout<<"\n Tot Test: \t"<< tot <<
          "\n Superati: \t"<< s   <<
          "\n Falliti:  \t"<< f   <<"\n";

    if(f)
        esito=false;



    //--FINE PRIMO INPUT --//

    return esito;
}

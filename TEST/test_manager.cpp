#include <iostream>

#include "test_manager.h"
#include "test_data.h"
#include "test_lingua.h"
#include "test_esperienza.h"
#include "test_utente_basic.h"
#include "test_utente_business.h"
#include "test_rete.h"
#include "test_db.h"
#include "test_smart_utente.h"

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
    bool risultato=false;
    std::cout<<"\n _______________________ \033[1;34mTEST MODE\033[0m _____________________________\n\n";
    risultato=(this->data_tester() && this->lingua_tester() && this->esperienza_tester() &&
            this->rete_tester() && this->utente_basic_tester() && this->utente_business_tester()&&
            this->smart_utente_tester() && this->db_tester());

    if(risultato)
        std::cout<<" \n\n \033[1;32m [V] Tutti i test passati. \n\033[0m\n"<<std::endl;
    else
         std::cout<<" \n\n \033[1;31m [X] Il programma non ha passato la fase di test.\033[0m\n\n"<<std::endl;
    return risultato;
}

bool test_manager::data_tester(){
    bool esito=true;
    //al primo fallimento --> esito==False

    //OGGETTO TESTER
    test_data* test_var=new test_data;
    test_var->run_tests();
    int tot=test_var->get_numero_test();
    int s=test_var->get_numero_test_superati();
    int f=test_var->get_numero_test_falliti();

    cout<<" < #:"<< tot <<", Superati: "<< s <<", Falliti: "<< f  <<" >\n";
    cout<<"\n _______________________________________________________________\n";

    if(f)
        esito=false;

    return esito;
}

bool test_manager::lingua_tester(){

    bool esito=true;
    //al primo fallimento --> esito==False

    //OGGETTO TESTER
    test_lingua* test_var=new test_lingua;
    test_var->run_tests();
    int tot=test_var->get_numero_test();
    int s=test_var->get_numero_test_superati();
    int f=test_var->get_numero_test_falliti();

    cout<<" < #:"<< tot <<", Superati: "<< s <<", Falliti: "<< f  <<" >";
    cout<<"\n _______________________________________________________________\n";

    if(f)
        esito=false;

    return esito;
}

bool test_manager::esperienza_tester(){
    bool esito=true;
    //al primo fallimento --> esito==False

    //OGGETTO TESTER
    test_esperienza* test_var=new test_esperienza;
    test_var->run_tests();
    int tot=test_var->get_numero_test();
    int s=test_var->get_numero_test_superati();
    int f=test_var->get_numero_test_falliti();

    cout<<" < #:"<< tot <<", Superati: "<< s <<", Falliti: "<< f  <<" >";
    cout<<"\n _______________________________________________________________\n";
    if(f)
        esito=false;

    return esito;
}

bool test_manager::rete_tester(){
    bool esito=true;
    //al primo fallimento --> esito==False

    //OGGETTO TESTER
    test_rete* test_var=new test_rete;
    test_var->run_tests();
    int tot=test_var->get_numero_test();
    int s=test_var->get_numero_test_superati();
    int f=test_var->get_numero_test_falliti();

    cout<<" < #:"<< tot <<", Superati: "<< s <<", Falliti: "<< f  <<" >";
    cout<<"\n _______________________________________________________________\n";
    if(f)
        esito=false;

    return esito;

}


bool test_manager::utente_basic_tester(){
    bool esito=true;
    //al primo fallimento --> esito==False

    //OGGETTO TESTER
    test_utente_basic* test_var=new test_utente_basic;
    test_var->run_tests();
    int tot=test_var->get_numero_test();
    int s=test_var->get_numero_test_superati();
    int f=test_var->get_numero_test_falliti();

    cout<<" < #:"<< tot <<", Superati: "<< s <<", Falliti: "<< f  <<" >";
    cout<<"\n _______________________________________________________________\n";
    if(f)
        esito=false;

    return esito;

}

bool test_manager::utente_business_tester(){
bool esito=true;
//al primo fallimento --> esito==False

//OGGETTO TESTER
test_utente_business* test_var=new test_utente_business;
test_var->run_tests();
int tot=test_var->get_numero_test();
int s=test_var->get_numero_test_superati();
int f=test_var->get_numero_test_falliti();

cout<<" < #:"<< tot <<", Superati: "<< s <<", Falliti: "<< f  <<" >";
cout<<"\n _______________________________________________________________\n";
if(f)
    esito=false;

return esito;

}

bool test_manager::db_tester(){
    bool esito=true;
    //al primo fallimento --> esito==False

    //OGGETTO TESTER
    test_db* test_var=new test_db;
    test_var->run_tests();
    int tot=test_var->get_numero_test();
    int s=test_var->get_numero_test_superati();
    int f=test_var->get_numero_test_falliti();

    cout<<" < #:"<< tot <<", Superati: "<< s <<", Falliti: "<< f  <<" >";
    cout<<"\n _______________________________________________________________\n";
    if(f)
        esito=false;

    return esito;
}

bool test_manager::smart_utente_tester(){
    bool esito=true;
    //al primo fallimento --> esito==False

    //OGGETTO TESTER
    test_smart_utente* test_var=new test_smart_utente;
    test_var->run_tests();
    int tot=test_var->get_numero_test();
    int s=test_var->get_numero_test_superati();
    int f=test_var->get_numero_test_falliti();

    cout<<" < #:"<< tot <<", Superati: "<< s <<", Falliti: "<< f  <<" >";
    cout<<"\n _______________________________________________________________\n";
    if(f)
        esito=false;

    return esito;
}

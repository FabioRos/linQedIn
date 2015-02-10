#include "test_smart_utente.h"
#include "../MODEL/smart_utente.h"
#include "../MODEL/utente_basic.h"
#include "../MODEL/utente_business.h"
#include "../MODEL/utente_executive.h"

test_smart_utente::test_smart_utente(){
}


test* test_smart_utente::run_tests(){
    //gestiti cosi, ma sono test booleani cosi sono portabili ed utilizzabili come API
    array_=new bool[numero_test];

    this->test0();
    this->test1();
    this->test2();
    this->test3();
    this->test4();
//    this->test5();
//    this->test6();
//    this->test7();
//    this->test8();
//    this->test9();
//    this->test10();
//    this->test11();
//    this->test12();
//    this->test13();
    //OUTPUT
    if(!n_test_falliti){
        std::cout<<"++++++++  [V] Tutti i test passati per l'unità [SMART_UTENTE] +++++++";
    }else{
        std::cout<<"-  [X] Il programma non ha passato la fase di test per l'unità [SMART_UTENTE] -";
    }

    //DETTAGLIO
    stampa_array_errori();

    return static_cast<test*>(this);
}


bool test_smart_utente::test0(){    //business basic
    numero_test++;
    try{
        utente_business* ubs=new utente_business;
        smart_utente smu(ubs);
        smu.cambio_tipo_utente("basic");
        if(dynamic_cast<utente_basic*>(smu.get_ptr_utente())){
            array_[0]=false;
            n_test_superati+=1;
            return true;
        }else{
            throw 0;
        }
    }
    catch (int e)    {
        array_[e]=true;
        n_test_falliti+=1;
        return false;
    }
}


bool test_smart_utente::test1(){    //basic business w/o cc
    numero_test++;
    try{
        utente_basic* u= new utente_basic();
        smart_utente smu(u);
        smu.cambio_tipo_utente("business");
        if(dynamic_cast<utente_business*>(smu.get_ptr_utente())){
            array_[1]=false;
            n_test_superati+=1;
            return true;
        }else{
            throw 1;
        }
    }
    catch (int e)    {
        array_[e]=true;
        n_test_falliti+=1;
        return false;
    }
}



bool test_smart_utente::test2(){    //basic -> executive w/o cc
    numero_test++;
    try{
        utente_basic* u= new utente_basic();
        smart_utente smu(u);
        smu.cambio_tipo_utente("executive");
        if(dynamic_cast<utente_executive*>(smu.get_ptr_utente())){
            array_[2]=false;
            n_test_superati+=1;
            return true;
        }else{
            throw 2;
        }
    }
    catch (int e)    {
        array_[e]=true;
        n_test_falliti+=1;
        return false;
    }
}


bool test_smart_utente::test3(){    //basic -> business w/ cc
    numero_test++;
    try{
        utente_basic* u= new utente_basic();
        smart_utente smu(u);
        smu.cambio_tipo_utente("business","cc123456a7");
        if(dynamic_cast<utente_business*>(smu.get_ptr_utente())){
            array_[3]=false;
            n_test_superati+=1;
            return true;
        }else{
            throw 3;
        }
    }
    catch (int e)    {
        array_[e]=true;
        n_test_falliti+=1;
        return false;
    }
}

bool test_smart_utente::test4(){    // business -> executive w/o cc
    numero_test++;
    try{
        utente_business* ubs=new utente_business;
        smart_utente smu(ubs);
        smu.cambio_tipo_utente("executive");
        if(dynamic_cast<utente_executive*>(smu.get_ptr_utente())){
            array_[4]=false;
            n_test_superati+=1;
            return true;
        }else{
            throw 4;
        }
    }
    catch (int e)    {
        array_[e]=true;
        n_test_falliti+=1;
        return false;
    }
}

//bool test_smart_utente::test0(){    //test  >=
//    numero_test++;
//    try{
//        utente_business* ubs=new utente_business;
//        utente_basic* u= new utente_basic();
//        smart_utente smu(ubs);
//        smu.cambio_tipo_utente("basic");
//        if(dynamic_cast<utente_basic*>(smu.get_ptr_utente())){
//            array_[0]=false;
//            n_test_superati+=1;
//            return true;
//        }else{
//            throw 0;
//        }
//    }
//    catch (int e)    {
//        array_[e]=true;
//        n_test_falliti+=1;
//        return false;
//    }
//}

//bool test_smart_utente::test0(){    //test  >=
//    numero_test++;
//    try{
//        utente_business* ubs=new utente_business;
//        utente_basic* u= new utente_basic();
//        smart_utente smu(ubs);
//        smu.cambio_tipo_utente("basic");
//        if(dynamic_cast<utente_basic*>(smu.get_ptr_utente())){
//            array_[0]=false;
//            n_test_superati+=1;
//            return true;
//        }else{
//            throw 0;
//        }
//    }
//    catch (int e)    {
//        array_[e]=true;
//        n_test_falliti+=1;
//        return false;
//    }
//}

//bool test_smart_utente::test0(){    //test  >=
//    numero_test++;
//    try{
//        utente_business* ubs=new utente_business;
//        utente_basic* u= new utente_basic();
//        smart_utente smu(ubs);
//        smu.cambio_tipo_utente("basic");
//        if(dynamic_cast<utente_basic*>(smu.get_ptr_utente())){
//            array_[0]=false;
//            n_test_superati+=1;
//            return true;
//        }else{
//            throw 0;
//        }
//    }
//    catch (int e)    {
//        array_[e]=true;
//        n_test_falliti+=1;
//        return false;
//    }
//}

//bool test_smart_utente::test0(){    //test  >=
//    numero_test++;
//    try{
//        utente_business* ubs=new utente_business;
//        utente_basic* u= new utente_basic();
//        smart_utente smu(ubs);
//        smu.cambio_tipo_utente("basic");
//        if(dynamic_cast<utente_basic*>(smu.get_ptr_utente())){
//            array_[0]=false;
//            n_test_superati+=1;
//            return true;
//        }else{
//            throw 0;
//        }
//    }
//    catch (int e)    {
//        array_[e]=true;
//        n_test_falliti+=1;
//        return false;
//    }
//}


#include "test_utente_business.h"
#include "../MODEL/utente_business.h"

test_utente_business::test_utente_business():test(0,0,0){}


test* test_utente_business::run_tests(){
    //gestiti cosi, ma sono test booleani cosi sono portabili ed utilizzabili come API
    array_=new bool[numero_test];

    this->test0();
//    this->test1();
//    this->test2();
//    this->test3();
//    this->test4();
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
        std::cout<<"++++++++  [V] Tutti i test passati per l'unità [UTENTE BUSINESS] +++++++";
    }else{
        std::cout<<"-  [X] Il programma non ha passato la fase di test per l'unità [UTENTE BUSINESS] -";
    }

    //DETTAGLIO
    stampa_array_errori();

    return static_cast<test*>(this);
}

bool test_utente_business::test0(){    //test
    numero_test++;
    try{
        utente_business* u= new utente_business();
        if(u){
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


//bool test_utente_business::test0(){    //test
//    numero_test++;
//    try{
//        utente_basic* u= new utente_basic();
//        if(u){
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

//bool test_utente_business::test0(){    //test
//    numero_test++;
//    try{
//        utente_basic* u= new utente_basic();
//        if(u){
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

//bool test_utente_business::test0(){    //test
//    numero_test++;
//    try{
//        utente_basic* u= new utente_basic();
//        if(u){
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

//bool test_utente_business::test0(){    //test
//    numero_test++;
//    try{
//        utente_basic* u= new utente_basic();
//        if(u){
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

//bool test_utente_business::test0(){    //test
//    numero_test++;
//    try{
//        utente_basic* u= new utente_basic();
//        if(u){
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

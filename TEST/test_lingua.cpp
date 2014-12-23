#include "test_lingua.h"

test_lingua::test_lingua(): test(0,0,0){
}

test *test_lingua::run_tests(){
    //gestiti cosi, ma sono test booleani cosi sono portabili ed utilizzabili come API

    this->test1();
    this->test2();
    this->test3();
    this->test4();
    this->test5();
    this->test6();


    //OUTPUT
    if(!n_test_falliti){
        std::cout<<"\n \n [V] Tutti i test passati per l'unità [LINGUA] \n \n";
    }else{
        std::cout<<"\n \n [X] Il programma non ha passato la fase di test per l'unità [LINGUA] \n \n";
    }

    return static_cast<test*>(this);
}

bool test_lingua::test1(){
    numero_test++;
    try{
       lingua* l = new lingua("Inglese","B1","B1","C1");
        if(!l){
            throw 20;
        }else{
            n_test_superati+=1;
            return true;
        }
    }
    catch (...)    {
        n_test_falliti+=1;
        return false;
    }
    lingua("Inglese","B1","B1","C1");
    return true;
}
bool test_lingua::test2(){
    numero_test++;
    try{
       lingua* l = new lingua("Inglese","B1","B1","C1");
        if(lingua::sanitize(*l)==true){
            n_test_superati+=1;
            return true;
        }else{
            throw 20;
        }
    }
    catch (...)    {
        n_test_falliti+=1;
        return false;
    }
    lingua("Inglese","B1","B1","C1");
    return true;
}
bool test_lingua::test3(){
    numero_test++;
    try{
       lingua* l = new lingua("Inglese","B3","B1","C1");
        if(lingua::sanitize(*l)==false){
            n_test_superati+=1;
            return true;
        }else{
            throw 20;
        }
    }
    catch (...)    {
        n_test_falliti+=1;
        return false;
    }
    lingua("Inglese","B1","B1","C1");
    return true;
}
bool test_lingua::test4(){
    numero_test++;
    try{
       lingua* l = new lingua("Inglese","B1","D1","C1");
        if(lingua::sanitize(*l)==false){
            n_test_superati+=1;
            return true;
        }else{
            throw 20;
        }
    }
    catch (...)    {
        n_test_falliti+=1;
        return false;
    }
    lingua("Inglese","B1","B1","C1");
    return true;
}
bool test_lingua::test5(){
    numero_test++;
    try{
       lingua* l = new lingua("","B1","B1","C1");
        if(lingua::sanitize(*l)==false){
            n_test_superati+=1;
            return true;
        }else{
            throw 20;
        }
    }
    catch (...)    {
        n_test_falliti+=1;
        return false;
    }
    lingua("Inglese","B1","B1","C1");
    return true;
}
bool test_lingua::test6(){
    numero_test++;
    try{
       lingua* l = new lingua("Inglese","","","");
        if(lingua::sanitize(*l)==false){
            n_test_superati+=1;
            return true;
        }else{
            throw 20;
        }
    }
    catch (...)    {
        n_test_falliti+=1;
        return false;
    }
    lingua("Inglese","B1","B1","C1");
    return true;
}

#include "test_lingua.h"

test_lingua::test_lingua(): test(0,0,0){
}

test *test_lingua::run_tests(){
    //gestiti cosi, ma sono test booleani cosi sono portabili ed utilizzabili come API
    array_=new bool[numero_test];

    this->test0();
    this->test1();
    this->test2();
    this->test3();
    this->test4();
    this->test5();


    //OUTPUT
    if(!n_test_falliti){
        std::cout<<"\n ++++++++++++  [V] Tutti i test passati per l'unità [LINGUA] +++++++++++ \n";
    }else{
        std::cout<<"-  [X] Il programma non ha passato la fase di test per l'unità [LINGUA] -\n";
    }

    //DETTAGLIO
    stampa_array_errori();

    return static_cast<test*>(this);
}

bool test_lingua::test0(){
    numero_test++;
    try{
       lingua* l = new lingua("Inglese","","","");
        if(lingua::sanitize(*l)==false){
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
    lingua("Inglese","B1","B1","C1");
    return true;
}

bool test_lingua::test1(){
    numero_test++;
    try{
       lingua* l = new lingua("Inglese","B1","B1","C1");
        if(!l){
            throw 1;
        }else{
            array_[1]=false;
            n_test_superati+=1;
            return true;
        }
    }
    catch (int e)    {
        array_[e]=true;
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
    lingua("Inglese","B1","B1","C1");
    return true;
}
bool test_lingua::test3(){
    numero_test++;
    try{
       lingua* l = new lingua("Inglese","B3","B1","C1");
        if(lingua::sanitize(*l)==false){
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
    lingua("Inglese","B1","B1","C1");
    return true;
}
bool test_lingua::test4(){
    numero_test++;
    try{
       lingua* l = new lingua("Inglese","B1","D1","C1");
        if(lingua::sanitize(*l)==false){
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
    lingua("Inglese","B1","B1","C1");
    return true;
}
bool test_lingua::test5(){
    numero_test++;
    try{
       lingua* l = new lingua("","B1","B1","C1");
        if(lingua::sanitize(*l)==false){
            array_[5]=false;
            n_test_superati+=1;
            return true;
        }else{
            throw 5;
        }
    }
    catch (int e)    {
        array_[e]=true;
        n_test_falliti+=1;
        return false;
    }
    lingua("Inglese","B1","B1","C1");
    return true;
}

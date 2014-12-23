#include "test_data.h"
#include "data.h"

test_data::test_data() : test(0,0,0){}

test* test_data::run_tests(){
    //gestiti cosi, ma sono test booleani cosi sono portabili ed utilizzabili come API

    this->test1();
    this->test2();
    this->test3();
    this->test4();
    this->test5();
    this->test6();
    this->test7();
    this->test8();


    //OUTPUT
    if(!n_test_falliti){
        std::cout<<"\n \n [V] Tutti i test passati per l'unità [DATA] \n \n";
    }else{
        std::cout<<"\n \n [X] Il programma non ha passato la fase di test per l'unità [DATA] \n \n";
    }

    return static_cast<test*>(this);
}

//1/1/2000
bool test_data::test1(){
    numero_test++;
    try{
        data* d=new data(1,1,2000);
        if(data::sanitize(*d)==false){
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
}
//35/02/2000
bool test_data::test2(){
    numero_test++;
    try{
        data* d=new data(35,02,2000); //deve essere falso
        if(data::sanitize(*d)==true)
            throw 20;
        else{
            n_test_superati+=1;
            return true;
        }
    }
    catch (...)    {
        n_test_falliti+=1;
        return false;
    }
}
//29/02/2012
bool test_data::test3(){
    numero_test++;
    try{
        data* d=new data(29,02,2012); //deve essere vero
        if(data::sanitize(*d)==false)
            throw 20;
        else{
            n_test_superati+=1;
            return true;
        }
    }
    catch (...)    {
        n_test_falliti+=1;
        return false;
    }
}
//29/02/2013
bool test_data::test4(){
    numero_test++;
    try{
        data* d=new data(29,02,2013); //deve essere falso
        if(data::sanitize(*d)==true)
            throw 20;
        else{
            n_test_superati+=1;
            return true;
        }
    }
    catch (...)    {
        n_test_falliti+=1;
        return false;
    }
}
//-1/05/2013
bool test_data::test5(){
    numero_test++;
    try{
        data* d=new data(-1,05,2013); //deve essere falso
        if(data::sanitize(*d)==true)
            throw 20;
        else{
            n_test_superati+=1;
            return true;
        }
    }
    catch (...)    {
        n_test_falliti+=1;
        return false;
    }
}
//31/11/2013    //Novembre ha 30 giorni
bool test_data::test6(){
    numero_test++;
    try{
        data* d=new data(31,11,2013); //deve essere falso
        if(data::sanitize(*d)==true)
            throw 20;
        else{
            n_test_superati+=1;
            return true;
        }
    }
    catch (...)    {
        n_test_falliti+=1;
        return false;
    }
}
//30/11/2013    //Novembre ha 30 giorni
bool test_data::test7(){
    numero_test++;
    try{
        data* d=new data(30,11,2013); //deve essere vero
        if(data::sanitize(*d)==false)
            throw 20;
        else{
            n_test_superati+=1;
            return true;
        }
    }
    catch (...)    {
        n_test_falliti+=1;
        return false;
    }
}
//31/01/2013    //Gennaio ha 31 giorni
bool test_data::test8(){
    numero_test++;
    try{
        data* d=new data(31,01,2013); //deve essere vero
        if(data::sanitize(*d)==false)
            throw 20;
        else{
            n_test_superati+=1;
            return true;
        }
    }
    catch (...)    {
        n_test_falliti+=1;
        return false;
    }
}










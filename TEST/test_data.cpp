#include "test_data.h"
#include "../MODEL/data.h"


test_data::test_data() : test(0,0,0){}

test* test_data::run_tests(){
    //gestiti cosi, ma sono test booleani cosi sono portabili ed utilizzabili come API
    array_=new bool[numero_test];

    this->test0();
    this->test1();
    this->test2();
    this->test3();
    this->test4();
    this->test5();
    this->test6();
    this->test7();
    this->test8();
    this->test9();
    this->test10();
    this->test11();
    this->test12();
    this->test13();
    //OUTPUT
    if(!n_test_falliti){
        std::cout<<"++++++++++++  [V] Tutti i test passati per l'unità [DATA] +++++++++++\n";
    }else{
        std::cout<<"-  [X] Il programma non ha passato la fase di test per l'unità [DATA] -\n";
    }

    //DETTAGLIO
    stampa_array_errori();

    return static_cast<test*>(this);
}



bool test_data::test0(){    //test  >=
    numero_test++;
    try{
        data* d1=new data(31,01,2013);
        data* d2=new data(31,01,2013);
        if(*d1 >= *d2){
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


//1/1/2000
bool test_data::test1(){
    numero_test++;
    try{
        data* d=new data(1,1,2000);
        if(data::sanitize(*d)==false){
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
}
//35/02/2000
bool test_data::test2(){
    numero_test++;
    try{
        data* d=new data(35,02,2000); //deve essere vero-> la setta al 1-1-1970
                                      //nel costruttore -> *d ~~~ 1-1-1970
        if(data::sanitize(*d)==false){
            throw 2;
        }else{
            array_[2]=false;
            n_test_superati+=1;
            return true;
        }
    }
    catch (int e)    {
        array_[e]=true;
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
            throw 3;
        else{
            array_[3]=false;
            n_test_superati+=1;
            return true;
        }
    }
    catch (int e)    {
        array_[e]=true;
        n_test_falliti+=1;
        return false;
    }
}
//29/02/2013
bool test_data::test4(){
    numero_test++;
    try{
        data* d=new data(29,02,2013); //deve essere vero, come test2()
        if(data::sanitize(*d)==false)
            throw 4;
        else{
            array_[4]=false;
            n_test_superati+=1;
            return true;
        }
    }
    catch (int e)    {
        array_[e]=true;
        n_test_falliti+=1;
        return false;
    }
}
//-1/05/2013
bool test_data::test5(){
    numero_test++;
    try{
        data* d=new data(-1,05,2013); //deve essere vero, come test2()
        if(data::sanitize(*d)==false)
            throw 5;
        else{
            array_[5]=false;
            n_test_superati+=1;
            return true;
        }
    }
    catch (int e)    {
        array_[e]=true;
        n_test_falliti+=1;
        return false;
    }
}
//31/11/2013    //Novembre ha 30 giorni
bool test_data::test6(){
    numero_test++;
    try{
        data* d=new data(31,11,2013); //deve essere vero, come test2()
        if(data::sanitize(*d)==false)
            throw 6;
        else{
            n_test_superati+=1;
            array_[6]=false;
            return true;
        }
    }
    catch (int e)    {
        array_[e]=true;
        n_test_falliti+=1;
        return false;
    }
}
//30/11/2013    //Novembre ha 30 giorni
bool test_data::test7(){
    numero_test++;
    try{
        data* d=new data(30,11,2013); //deve essere vero
//        std::cout<< d->get_giorno() << '-' << d->get_mese()<<'-'<<d->get_anno()<<std::endl;
         if(data::sanitize(*d)==false)
            throw 7;
        else{
            n_test_superati+=1;
            array_[7]=false;
            return true;
        }
    }
    catch (int e)    {
        array_[e]=true;
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
            throw 8;
        else{
            array_[8]=false;
            n_test_superati+=1;
            return true;
        }
    }
    catch (int e)    {
        array_[e]=true;
        n_test_falliti+=1;
        return false;
    }
}

bool test_data::test9(){    //test !=
    numero_test++;
    try{
        data* d1=new data(31,01,2013);
        data* d2=new data(31,01,2013);
        if(*d1 != *d2)
            throw 9;
        else{
            array_[9]=false;
            n_test_superati+=1;
            return true;
        }
    }
    catch (int e)    {
        array_[e]=true;
        n_test_falliti+=1;
        return false;
    }
}

bool test_data::test10(){    //test  <
    numero_test++;
    try{
        data* d1=new data(31,01,2013);
        data* d2=new data(20,02,2013);
        if(*d2 < *d1)
            throw 10;
        else{
            array_[10]=false;
            n_test_superati+=1;
            return true;
        }
    }
    catch (int e)    {
        array_[e]=true;
        n_test_falliti+=1;
        return false;
    }
}

bool test_data::test11(){    //test  <
    numero_test++;
    try{
        data* d1=new data(40,02,2013);
        data* d2=new data(31,01,2013);
//        std::cout<< d1->get_giorno() << '-' << d1->get_mese()<<'-'<<d1->get_anno()<<std::endl;
//        std::cout<< d2->get_giorno() << '-' << d2->get_mese()<<'-'<<d2->get_anno()<<std::endl;
        if(*d1 < *d2){  //  := (1-1-1970 < 31-01-2013)?1:0;
            array_[11]=false;
            n_test_superati+=1;
            return true;
        }else{
          throw 11;
        }
    }
    catch (int e)    {
        array_[e]=true;
        n_test_falliti+=1;
        return false;
    }
}

bool test_data::test12(){    //test  <=
    numero_test++;
    try{
        data* d1=new data(31,01,2013);
        data* d2=new data(31,01,2013);
        if(*d1 <= *d2){
            array_[12]=false;
            n_test_superati+=1;
            return true;
        }else{
            throw 12;
        }
    }
    catch (int e)    {
        array_[e]=true;
        n_test_falliti+=1;
        return false;
    }
}


bool test_data::test13(){    //test  >
    numero_test++;
    try{
        data* d1=new data(31,01,2013);
        data* d2=new data(30,01,2013);
        if(*d1 > *d2){
            array_[13]=false;
            n_test_superati+=1;
            return true;
        }else{
            throw 13;
        }
    }
    catch (int e)    {
        array_[e]=true;
        n_test_falliti+=1;
        return false;
    }
}














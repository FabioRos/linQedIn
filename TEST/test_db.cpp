#include "test_db.h"

test_db::test_db(): test(0,0,0){}

test* test_db::run_tests(){
    //gestiti cosi, ma sono test booleani cosi sono portabili ed utilizzabili come API
    array_=new bool[numero_test];

    this->test0();
    this->test1();
    this->test2();
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
        std::cout<<"+++++++++++++  [V] Tutti i test passati per l'unità [DB] ++++++++++++\n";
    }else{
        std::cout<<"--  [X] Il programma non ha passato la fase di test per l'unità [DB] --\n";
    }

    //DETTAGLIO
    stampa_array_errori();

    return static_cast<test*>(this);
}

bool test_db::test0(){    //test  inserimento + empty
    numero_test++;
    try{
        DB db;
        smart_utente* su= new smart_utente(new utente_basic);
        db.aggiungi_utente(*su);
        if(db.empty()){
            throw 0;
        }else{
            array_[0]=false;
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

bool test_db::test1(){    //test  inserimento + empty
    numero_test++;
    try{
        DB db;
        smart_utente* su= new smart_utente;
        db.aggiungi_utente(*su);
        if(db.empty()){         //mi aspetto che il database sia vuoto
            array_[1]=false;    //perchè uno smart_utente vuoto ha
            n_test_superati+=1; //il campo dati ptr_utente ==0
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

bool test_db::test2(){    //test  inserimento + empty
    numero_test++;
    try{
        DB db;
        smart_utente* su= new smart_utente(new utente_basic());
        su->get_ptr_utente()->update_username("pippo");
        db.aggiungi_utente(*su);
        db.rimuovi_utente("pippo");
        if(db.empty()){
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

//bool test_db::test0(){    //test  >=
//    numero_test++;
//    try{

//        if(true){
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


//bool test_db::test0(){    //test  >=
//    numero_test++;
//    try{

//        if(true){
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


//bool test_db::test0(){    //test  >=
//    numero_test++;
//    try{

//        if(true){
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


//bool test_db::test0(){    //test  >=
//    numero_test++;
//    try{

//        if(true){
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


//bool test_db::test0(){    //test  >=
//    numero_test++;
//    try{

//        if(true){
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


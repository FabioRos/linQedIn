#include "test_utente_basic.h"
#include "../MODEL/smart_utente.h"
#include "../MODEL/utente_basic.h"
#include "../MODEL/utente_business.h"

test_utente_basic::test_utente_basic() : test(0,0,0){
}

test* test_utente_basic::run_tests(){
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
//    this->test9();
//    this->test10();
//    this->test11();
//    this->test12();
//    this->test13();
    //OUTPUT
    if(!n_test_falliti){
        std::cout<<"++++++++  [V] Tutti i test passati per l'unità [UTENTE BASIC] +++++++";
    }else{
        std::cout<<"-  [X] Il programma non ha passato la fase di test per l'unità [UTENTE BASIC] -";
    }

    //DETTAGLIO
    stampa_array_errori();

    return static_cast<test*>(this);
}


bool test_utente_basic::test0(){    //test  >=
    numero_test++;
    try{
        utente_basic* u= new utente_basic();
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

bool test_utente_basic::test1(){    //test  aggiungi esperienza
    numero_test++;
    try{
        utente_basic* u=new utente_basic;
        esperienza_professionale* ep = new esperienza_professionale("a","p","l","d",data(),data());
        u->aggiungi_esperienze_professionali(*ep);
        if(u->get_esperienze_professionali().empty()==false){
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


bool test_utente_basic::test2(){    //test  rimuovi esperienza
    numero_test++;
    try{
        utente_basic* u=new utente_basic;
        esperienza_professionale* ep = new esperienza_professionale("a","p","l","d",data(),data());
        u->aggiungi_esperienze_professionali(*ep);
        u->rimuovi_esperienze_professionali(*ep);
        if(u->get_esperienze_professionali().empty()==true){
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


bool test_utente_basic::test3(){    //aggiunta competenza
    numero_test++;
    try{
        utente_basic* u=new utente_basic;
        u->aggiungi_competenze("XML");
        if(u->get_competenze().empty()==false){
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


bool test_utente_basic::test4(){    //aggiunta competenza
    numero_test++;
    try{
        utente_basic* u=new utente_basic;
        u->aggiungi_competenze("XML");
        if(u->get_competenze().empty()==false){
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


bool test_utente_basic::test5(){    //ha competenza
    numero_test++;
    try{
        utente_basic* u=new utente_basic;
        u->aggiungi_competenze("XML");
        if(u->ha_la_competenza("XML")){
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
}


bool test_utente_basic::test6(){    //rimozione competenza
    numero_test++;
    try{
        utente_basic* u=new utente_basic;
        u->aggiungi_competenze("XML");
        u->rimuovi_competenze("XML");
        if(u->get_competenze().empty()==true){
            array_[6]=false;
            n_test_superati+=1;
            return true;
        }else{
            throw 6;
        }
    }
    catch (int e)    {
        array_[e]=true;
        n_test_falliti+=1;
        return false;
    }
}


bool test_utente_basic::test7(){    //rete
    numero_test++;
    try{
        utente_basic* u=new utente_basic;
        utente_basic* utente_due=new utente_basic();
        utente_due->update_username("username2");
        smart_utente* sm_u=new smart_utente(utente_due);
        u->aggiungi_utente_a_rete(sm_u);
        if(u->esiste_nella_rete("username2")){
            array_[7]=false;
            n_test_superati+=1;
            return true;
        }else{
            throw 7;
        }
    }
    catch (int e)    {
        array_[e]=true;
        n_test_falliti+=1;
        return false;
    }
}

bool test_utente_basic::test8(){    //test  >=
    numero_test++;
    try{

        if(true){
            array_[8]=false;
            n_test_superati+=1;
            return true;
        }else{
            throw 8;
        }
    }
    catch (int e)    {
        array_[e]=true;
        n_test_falliti+=1;
        return false;
    }
}


//bool test_utente_basic::test1(){    //test  >=
//    numero_test++;
//    try{
//        if(true){
//            array_[1]=false;
//            n_test_superati+=1;
//            return true;
//        }else{
//            throw 1;
//        }
//    }
//    catch (int e)    {
//        array_[e]=true;
//        n_test_falliti+=1;
//        return false;
//    }
//}


//bool test_utente_basic::test1(){    //test  >=
//    numero_test++;
//    try{
//        if(true){
//            array_[1]=false;
//            n_test_superati+=1;
//            return true;
//        }else{
//            throw 1;
//        }
//    }
//    catch (int e)    {
//        array_[e]=true;
//        n_test_falliti+=1;
//        return false;
//    }
//}


//bool test_utente_basic::test1(){    //test  >=
//    numero_test++;
//    try{
//        if(true){
//            array_[1]=false;
//            n_test_superati+=1;
//            return true;
//        }else{
//            throw 1;
//        }
//    }
//    catch (int e)    {
//        array_[e]=true;
//        n_test_falliti+=1;
//        return false;
//    }
//}


//bool test_utente_basic::test1(){    //test  >=
//    numero_test++;
//    try{
//        if(true){
//            array_[1]=false;
//            n_test_superati+=1;
//            return true;
//        }else{
//            throw 1;
//        }
//    }
//    catch (int e)    {
//        array_[e]=true;
//        n_test_falliti+=1;
//        return false;
//    }
//}

//bool test_utente_basic::test1(){    //test  >=
//    numero_test++;
//    try{
//        if(true){
//            array_[1]=false;
//            n_test_superati+=1;
//            return true;
//        }else{
//            throw 1;
//        }
//    }
//    catch (int e)    {
//        array_[e]=true;
//        n_test_falliti+=1;
//        return false;
//    }
//}


//bool test_utente_basic::test1(){    //test  >=
//    numero_test++;
//    try{
//        if(true){
//            array_[1]=false;
//            n_test_superati+=1;
//            return true;
//        }else{
//            throw 1;
//        }
//    }
//    catch (int e)    {
//        array_[e]=true;
//        n_test_falliti+=1;
//        return false;
//    }
//}


//bool test_utente_basic::test1(){    //test  >=
//    numero_test++;
//    try{
//        if(true){
//            array_[1]=false;
//            n_test_superati+=1;
//            return true;
//        }else{
//            throw 1;
//        }
//    }
//    catch (int e)    {
//        array_[e]=true;
//        n_test_falliti+=1;
//        return false;
//    }
//}

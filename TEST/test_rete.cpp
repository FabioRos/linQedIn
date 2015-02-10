#include "test_rete.h"
#include "../MODEL/smart_utente.h"
test_rete::test_rete() : test(0,0,0){

}

test* test_rete::run_tests(){
    //gestiti cosi, ma sono test booleani cosi sono portabili ed utilizzabili come API
    array_=new bool[numero_test];

    this->test0();
    this->test1();
    this->test2();
    this->test3();
    this->test4();
    this->test5();
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
        std::cout<<"++++++++++++  [V] Tutti i test passati per l'unità [ RETE ] +++++++++++\n";
    }else{
        std::cout<<"--- [X] Il programma non ha passato la fase di test per l'unità [RETE] ---\n";
    }

    //DETTAGLIO
    stampa_array_errori();

    return static_cast<test*>(this);
}

bool test_rete::test0(){    //test  costruzione rete
    numero_test++;
    try{
        rete* r=new rete;
        if(r){
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

bool test_rete::test1(){    //test aggiungi a rete
    numero_test++;
    try{
        rete* r=new rete;
        utente_basic* ptr_utente_basic=new utente_basic;
        ptr_utente_basic->update_username("TESTING_USERNAME");
        r->aggiungi_elemento(*(new smart_utente(ptr_utente_basic)));
        if(r->get_ptr_utente("TESTING_USERNAME")->get_username()=="TESTING_USERNAME"){
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


bool test_rete::test2(){    //test  get_all --> list<utente*>
    numero_test++;
    try{
        rete* r=new rete;
        utente_basic* ptr_utente_basic=new utente_basic;
        ptr_utente_basic->update_username("TESTING_USERNAME");
        r->aggiungi_elemento(*(new smart_utente(ptr_utente_basic)));
        std::list<utente*> risultato=r->get_all_ptr_utente();
        if(risultato.size()==1){
           risultato.pop_front();
            if(risultato.empty()){
                array_[2]=false;
                n_test_superati+=1;
                return true;
            }else
                throw 2;
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

bool test_rete::test3(){    //test  rete::empty()
    numero_test++;
    try{
        rete* r=new rete;
        if(r->empty()){
            utente_basic* ptr_utente_basic=new utente_basic;
            r->aggiungi_elemento(*(new smart_utente(ptr_utente_basic)));
            if(r->empty()){
                 throw 3;
            }else
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

bool test_rete::test4(){    //test  rete::esiste_elemento()
    numero_test++;
    try{
        rete* r=new rete;
        if(!(r->esiste_elemento("TESTING_USERNAME"))){
            utente_basic* ptr_utente_basic=new utente_basic;
            ptr_utente_basic->update_username("TESTING_USERNAME");
            r->aggiungi_elemento(*(new smart_utente(ptr_utente_basic)));

            if(r->esiste_elemento("TESTING_USERNAME")){
                array_[4]=false;
                n_test_superati+=1;
                return true;
            }else
               throw 4;
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

bool test_rete::test5(){    //test  rete::rimuovi_elemento()
    numero_test++;
    try{
        rete* r=new rete;
        if(!(r->esiste_elemento("TESTING_USERNAME"))){
            utente_basic* ptr_utente_basic=new utente_basic;
            ptr_utente_basic->update_username("TESTING_USERNAME");
            r->aggiungi_elemento(*(new smart_utente(ptr_utente_basic)));
            r->rimuovi_elemento("TESTING_USERNAME");
            if(r->empty()){
                array_[5]=false;
                n_test_superati+=1;
                return true;
            }else
               throw 5;
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

//bool test_rete::test0(){    //test  >=
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

//bool test_rete::test0(){    //test  >=
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

//bool test_rete::test0(){    //test  >=
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

//bool test_rete::test0(){    //test  >=
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


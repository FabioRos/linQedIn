#include "test_esperienza.h"
#include "esperienza_professionale.h"

test_esperienza::test_esperienza()
{
}


test* test_esperienza::run_tests(){
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


    //OUTPUT
    if(!n_test_falliti){
        std::cout<<"++ [V] Tutti i test passati per l'unità [ESPERIENZA PROFESSIONALE] ++\n";
    }else{
        std::cout<<"-  [X] Il programma non ha passato la fase di test per l'unità [ESPERIENZA PROFESSIONALE] -\n";
     }

    //DETTAGLIO
    stampa_array_errori();

    return static_cast<test*>(this);
}

bool test_esperienza::test0(){
    numero_test++;
    try{
        esperienza_professionale* p = new esperienza_professionale("a","a","a","a",data(),data());
        if(!p)
            throw 0;
        else{
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
bool test_esperienza::test1(){  //controllo getter
    numero_test++;
    esperienza_professionale* p = new esperienza_professionale("azienda","posizione","luogo","descrizione",
                                                               data(1,1,2014),data(2,1,2014));
    try{
        if(p->get_descrizione()!="descrizione" || p->get_posizione()!="posizione" ||
                p->get_luogo() !="luogo" || p->get_descrizione() !="descrizione" ||
                !(p->get_inizio() == data(1,1,2014)) || !(p->get_fine() == data(2,1,2014)))
            throw 1;
        else{
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


 bool test_esperienza::test2(){  //controllo setter
    numero_test++;
    esperienza_professionale* p = new esperienza_professionale("a","p","l","d",
                                                               data(),data());
    try{
        p->aggiorna_nome_azienda("azienda");
        p->aggiorna_posizione("posizione");
        p->update_luogo("luogo");
        p->update_descrizione("descrizione");
        p->update_inizio(data(1,1,2014));
        p->update_fine(data(2,1,2014));
        if(p->get_descrizione()!="descrizione" || p->get_posizione()!="posizione" ||
                p->get_luogo() !="luogo" || p->get_descrizione() !="descrizione" ||
                !(p->get_inizio() == data(1,1,2014)) || !(p->get_fine() == data(2,1,2014)))
            throw 2;
        else{
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
 bool test_esperienza::test3(){ //controllo ==
     numero_test++;
     try{
         esperienza_professionale* p1 = new esperienza_professionale("a","p","l","d",
                                                                    data(),data());
         esperienza_professionale* p2 = new esperienza_professionale("a","p","l","d",
                                                                    data(),data());
         if(*p1==*p2) {
             array_[3]=false;
             n_test_superati+=1;
             return true;
         }
         else{
             throw 3;

         }
     }
     catch (int e)    {
         array_[e]=true;
         n_test_falliti+=1;
         return false;
     }
 }

 bool test_esperienza::test4(){ //controllo !=
     numero_test++;
     try{
         esperienza_professionale* p1 = new esperienza_professionale("a","p","l","d",
                                                                    data(),data());
         esperienza_professionale* p2 = new esperienza_professionale("b","p","l","d",
                                                                    data(),data());
         if(*p1!=*p2) {
             array_[4]=false;
             n_test_superati+=1;
             return true;
         }
         else{
             throw 4;

         }
     }
     catch (int e)    {
         array_[e]=true;
         n_test_falliti+=1;
         return false;
     }
 }
bool test_esperienza::test5(){    //data inizio <= data fine!
    numero_test++;
    try{
        if(0)
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

/*
bool test_esperienza::test6(){      //remove esperienza
    numero_test++;
    try{
        if(0)
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
bool test_esperienza::test7(){
    numero_test++;
    try{
        if(0)
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
bool test_esperienza::test8(){
    numero_test++;
    try{
        if(0)
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
*/

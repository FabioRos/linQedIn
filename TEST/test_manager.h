#ifndef TEST_MANAGER_H
#define TEST_MANAGER_H
#include "test.h"

class test_manager
{
private:
    test* locale;

public:
    test_manager();

    //così chi fa i test di unita' puo aggiungere l suo punteggio a quello totale
    void aggiorna_stato_test(const test *);  //aggiorno con i risultati di un dato test

    bool run_tests();
    // DATA
    bool data_tester();
    // LINGUA
    bool lingua_tester();
    // ESPERIENZA PROFESSIONALE
    bool esperienza_tester();
    // UTENTE BASIC
    bool utente_basic_tester();



};

#endif // TEST_MANAGER_H

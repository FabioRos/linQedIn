#ifndef TEST_UTENTE_BASIC_H
#define TEST_UTENTE_BASIC_H

#include "test.h"

#include "../MODEL/smart_utente.h"

class test_utente_basic : public test{
public:
    test_utente_basic();
    test* run_tests();
    //tests
    bool test0();
    bool test1();
    bool test2();
    bool test3();
    bool test4();
    bool test5();
    bool test6();
    bool test7();
    bool test8();
};

#endif // TEST_UTENTE_BASIC_H

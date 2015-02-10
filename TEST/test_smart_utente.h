#ifndef TEST_SMART_UTENTE_H
#define TEST_SMART_UTENTE_H

#include "test.h"

#include "../MODEL/smart_utente.h"
#include "../MODEL/utente_basic.h"
#include "../MODEL/utente_business.h"
#include "../MODEL/utente_executive.h"

class test_smart_utente : public test
{
public:
    test_smart_utente();
    test* run_tests();
    //tests
    bool test0();
    bool test1();
    bool test2();
    bool test3();
    bool test4();
//    bool test5();
//    bool test6();
//    bool test7();
//    bool test8();
//    bool test9();
//    bool test10();
//    bool test11();
//    bool test12();
//    bool test13();
};

#endif // TEST_SMART_UTENTE_H

#ifndef TEST_COMPETENZE_H
#define TEST_COMPETENZE_H
#include "test.h"
#include <iostream>

class test_rete : public test{
public:
    test_rete();
    test* run_tests();
    //tests
    bool test0();
    bool test1();
    bool test2();
    bool test3();
    bool test4();
    bool test5();
//    bool test6();
//    bool test7();
//    bool test8();
//    bool test9();
//    bool test10();
//    bool test11();
//    bool test12();
//    bool test13();
};

#endif // TEST_COMPETENZE_H

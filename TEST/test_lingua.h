#ifndef TEST_LINGUA_H
#define TEST_LINGUA_H

#include "test.h"
#include "./MODEL/lingua.h"

class test_lingua: public test{
public:
    test_lingua();
    test* run_tests();
    //tests
    bool test0();
    bool test1();
    bool test2();
    bool test3();
    bool test4();
    bool test5();
};

#endif // TEST_LINGUA_H

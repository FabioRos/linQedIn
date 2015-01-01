#ifndef TEST_ESPERIENZA_H
#define TEST_ESPERIENZA_H

#include "test.h"
#include <iostream>
class test_esperienza : public test{
public:
    test_esperienza();
   test* run_tests();
    //tests
    bool test0();
    bool test1();
    bool test2();
    /* bool test3();
    bool test4();
    bool test5();
    bool test6();
    bool test7();
    bool test8();*/
};




#endif // TEST_ESPERIENZA_H

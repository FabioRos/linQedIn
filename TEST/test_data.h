#ifndef TEST_DATA_H
#define TEST_DATA_H

#include "test.h"
#include <iostream>
class test_data : public test{
public:
    test_data();
    test* run_tests();
    //tests
    bool test1();
    bool test2();
    bool test3();
    bool test4();
    bool test5();
    bool test6();
    bool test7();
    bool test8();

};

#endif // TEST_DATA_H

#ifndef TEST_H
#define TEST_H

#include <string>
#include "data.h"
#include "lingua.h"

class test{
public:
    int numero_test;
    int n_test_superati;
    int n_test_falliti;

    test();
    test( const int&, const int&, const int&);

    ~test();
    virtual test* run_tests();

    int get_numero_test() const;
    int get_numero_test_superati()const;
    int get_numero_test_falliti() const;

};



#endif // TEST_H

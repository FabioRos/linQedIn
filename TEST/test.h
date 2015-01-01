#ifndef TEST_H
#define TEST_H

#include <string>
#include <iostream>
#include "data.h"
#include "lingua.h"
#include "esperienza_professionale.h"

class test{
public:
    int numero_test;
    int n_test_superati;
    int n_test_falliti;
    bool* array_;   //array degli errori -> "array_[i]=true" => "c'è un errore all' i-esimo test."

    test();
    test( const int&, const int&, const int&);

    ~test();
    virtual test* run_tests();

    int get_numero_test() const;
    int get_numero_test_superati()const;
    int get_numero_test_falliti() const;

    void stampa_array_errori() const;
};



#endif // TEST_H

#include "test.h"

test::test():numero_test(0),n_test_superati(0),n_test_falliti(0){}

test::test(const int & tot, const int & s, const int & f):
    numero_test(tot),n_test_superati(s),n_test_falliti(f){}

test* test::run_tests(){
    return this;
} //concreta perchè mi serve istanziare test

int test::get_numero_test() const{
    return numero_test;
}

int test::get_numero_test_superati() const{
    return n_test_superati;
}

int test::get_numero_test_falliti() const {
    return n_test_falliti;
}






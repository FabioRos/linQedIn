#include "test.h"

test::test():numero_test(0),n_test_superati(0),n_test_falliti(0){}

test::~test(){}

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


void test::stampa_array_errori() const
{   std::cout<<std::endl;
    for (int i=0;i<numero_test;i++){
        std::cout<<"["<<i<<":";
        if(array_[i]==true)
            std::cout<<"\033[1;31mERR\033[0m] ";
        else
            std::cout<<"\033[1;32mOK\033[0m] ";
    }
    std::cout<<std::endl<<std::endl;
}



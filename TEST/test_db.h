#ifndef TEST_DB_H
#define TEST_DB_H

#include "test.h"
#include "../MODEL/db.h"
#include "../MODEL/utente_basic.h"

class test_db : public test{
private:
    DB database;
public:
    test_db();
    test* run_tests();
    //tests
    bool test0();   //aggiunta utente
    bool test1();   //aggiunta utente
    bool test2();   //rimozione utente
//    bool test3();
//    bool test4();
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

#endif // TEST_DB_H

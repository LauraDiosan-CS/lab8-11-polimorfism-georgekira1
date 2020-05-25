#ifndef LAB_8_11_BUN_TESTMOVIE_H
#define LAB_8_11_BUN_TESTMOVIE_H
#include "../Domain/Movie.h"

class TestMovie {
private:
    void testImplicitConstructor();
    void testConstructorWithParameters();
    void testClone();
    void testGetTitle();
    void testGetActors();
    void testAssignmentOperator();
    void testEqualityOperator();

public:
    void testAll();
};


#endif //LAB_8_11_BUN_TESTMOVIE_H

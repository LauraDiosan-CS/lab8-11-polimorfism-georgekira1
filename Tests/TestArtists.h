#ifndef LAB_8_11_BUN_TESTARTISTS_H
#define LAB_8_11_BUN_TESTARTISTS_H
#include "../Domain/Artists.h"

class TestArtists {
private:
    void testImplicitConstructor();
    void testConstructorWithParameters();
    void testClone();
    void testGetArtistName();
    void testSetArtistName();
    void testAssignmentOperator();


public:
    void testAll();
    TestArtists();
};


#endif //LAB_8_11_BUN_TESTARTISTS_H

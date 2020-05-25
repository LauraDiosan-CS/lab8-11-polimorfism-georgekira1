#ifndef LAB_8_11_BUN_TESTADMINISTRATOR_H
#define LAB_8_11_BUN_TESTADMINISTRATOR_H
#include "../Domain/Administrator.h"

class TestAdministrator {
private:
    void testImplicitConstructor();
    void testConstructorWithParameters();
    void testClone();
    void testGetAdminName();
    void testSetAdminName();
    void testGetPassword();
    void testSetPassword();
    void testAssignmentOperator();

public:
    void testAll();
    TestAdministrator();
};


#endif //LAB_8_11_BUN_TESTADMINISTRATOR_H

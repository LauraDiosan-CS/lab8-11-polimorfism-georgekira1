#include "TestAdministrator.h"
#include <cassert>

TestAdministrator::TestAdministrator() = default;

void TestAdministrator :: testAll(){
    this->testImplicitConstructor();
    this->testConstructorWithParameters();
    this->testClone();
    this->testGetAdminName();
    this->testSetAdminName();
    this->testGetPassword();
    this->testSetPassword();
    this->testAssignmentOperator();
}

void TestAdministrator::testImplicitConstructor() {
    Administrator a;
    assert (a.getPassword().empty());
    assert (a.getAdministratorName().empty());
}

void TestAdministrator::testConstructorWithParameters() {
    Administrator a ("alin", "111");
    assert (a.getPassword()== "111");
    assert (a.getAdministratorName()== "alin");
}

void TestAdministrator::testClone() {
    Administrator a ("alin", "111");
    Administrator* aClone = (Administrator*)a.clone();
    assert (a == *aClone);
    assert (&a != aClone);
}

void TestAdministrator::testGetAdminName() {
    Administrator a ("alin", "111");
    assert (a.getAdministratorName()== "alin");
}

void TestAdministrator::testSetAdminName() {
    Administrator a ("alin", "111");
    a.setAdministratorName("geo");
    assert (a.getAdministratorName()== "geo");
}

void TestAdministrator:: testGetPassword(){
    Administrator a ("alin", "111");
    assert (a.getPassword()== "111");
}
void TestAdministrator::testSetPassword() {
    Administrator a ("alin", "111");
    a.setPassword("geo");
    assert (a.getPassword()== "geo");
}

void TestAdministrator:: testAssignmentOperator() {
    Administrator a ("alin", "111");
    Administrator a2;
    a2 = a;
    assert(a2.getAdministratorName() == a.getAdministratorName());
}

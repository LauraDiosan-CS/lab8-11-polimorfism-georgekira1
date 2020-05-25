#include "TestArtists.h"
#include <cassert>

TestArtists::TestArtists() {

}

void TestArtists :: testAll(){
    this->testImplicitConstructor();
    this->testConstructorWithParameters();
    this->testClone();
    this->testGetArtistName();
    this->testSetArtistName();
    this->testAssignmentOperator();
}

void TestArtists::testImplicitConstructor() {
    Artists a;
    assert (a.getAvailableSeats() == 0);
    assert (a.getSoldSeats() == 0);
    assert (a.getDate().empty());
    assert (a.getVenue().empty());
    assert (a.getArtistName().empty());
}

void TestArtists::testConstructorWithParameters() {
    Artists a ("Logic", "13.11.2000", "Amsterdam Arena", 10, 1000);
    assert (a.getAvailableSeats() == 10);
    assert (a.getSoldSeats() == 1000);
    assert (a.getDate()== "13.11.2000");
    assert (a.getVenue()== "Amsterdam Arena");
    assert (a.getArtistName()== "Logic");
}

void TestArtists::testClone() {
    Artists a ("Logic", "13.11.2000", "Amsterdam Arena", 10, 1000);
    Artists* aClone = (Artists*)a.clone();
    assert (a == *aClone);
    assert (&a != aClone);
}

void TestArtists::testGetArtistName() {
    Artists a ("Logic", "13.11.2000", "Amsterdam Arena", 10, 1000);
    assert (a.getArtistName()== "Logic");
}

void TestArtists::testSetArtistName() {
    Artists a ("Logic", "13.11.2000", "Amsterdam Arena", 10, 1000);
    a.setArtistName("Madonna");
    assert (a.getArtistName()== "Madonna");
}

void TestArtists:: testAssignmentOperator() {
    Artists a ("Logic", "13.11.2000", "Amsterdam Arena", 10, 1000);
    Artists a2;
    a2 = a;
    assert(a2.getArtistName() == a.getArtistName());
}

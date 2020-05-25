#include "TestMovie.h"
#include <cassert>

void TestMovie :: testAll(){
    this->testImplicitConstructor();
    this->testConstructorWithParameters();
    this->testClone();
    this->testGetTitle();
    this->testGetActors();
    this->testAssignmentOperator();
    this->testEqualityOperator();
}

void TestMovie::testImplicitConstructor() {
    Movie m;
    assert (m.getTitle().empty());
    assert (m.getDate().empty());
    assert (m.getVenue().empty());
    assert (m.getActors().empty());
    assert (m.getAvailableSeats()==0);
    assert (m.getSoldSeats() == 0);
}

void TestMovie::testConstructorWithParameters() {
    Movie m ("Miracol in celula 7", "Keanu Reeves, Angelina Jolie, Brad Pitt", "13.11.2000", "Amsterdam Arena", 10, 1000);
    assert (m.getTitle() == "Miracol in celula 7");
    assert (m.getDate() == "13.11.2000");
    assert (m.getVenue() == "Amsterdam Arena");
    assert (m.getActors() == "Keanu Reeves, Angelina Jolie, Brad Pitt");
    assert (m.getAvailableSeats()==10);
    assert (m.getSoldSeats() == 1000);
}

void TestMovie:: testClone(){
    Movie m ("Miracol in celula 7", "Keanu Reeves, Angelina Jolie, Brad Pitt", "13.11.2000", "Amsterdam Arena", 10, 1000);
    Movie* mClone = (Movie*)m.clone();
    assert (m == *mClone);
    assert (&m != mClone);
}

void TestMovie::testGetTitle() {
    Movie m ("Miracol in celula 7", "Keanu Reeves, Angelina Jolie, Brad Pitt", "13.11.2000", "Amsterdam Arena", 10, 1000);
    assert (m.getTitle() == "Miracol in celula 7");
}

void TestMovie::testGetActors() {
    Movie m ("Miracol in celula 7", "Keanu Reeves, Angelina Jolie, Brad Pitt", "13.11.2000", "Amsterdam Arena", 10, 1000);
    assert(m.getActors() == "Keanu Reeves, Angelina Jolie, Brad Pitt");
}

void TestMovie:: testAssignmentOperator(){
    Movie m ("Miracol in celula 7", "Keanu Reeves, Angelina Jolie, Brad Pitt", "13.11.2000", "Amsterdam Arena", 10, 1000);
    Movie m2 ;
    m2 = m;
    assert(m2.getTitle() == m.getTitle());
}

void TestMovie::testEqualityOperator() {
    Movie m ("Miracol in celula 7", "Keanu Reeves, Angelina Jolie, Brad Pitt", "13.11.2000", "Amsterdam Arena", 10, 1000);
    Movie m2 ;
    m2 = m;
    assert (m2 == m);
}
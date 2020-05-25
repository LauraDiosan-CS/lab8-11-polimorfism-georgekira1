#include "TestService.h"
#include <cassert>

TestService::TestService() = default;

TestService::~TestService() = default;

void TestService::testAddArtist() {
    Service serv;
    RepoFile* repoFile = new RepoFileTXT();
    serv.setRepo(repoFile);

    Artists* a = new Artists("Alin", "03.05.2020", "Cluj", 10, 1000);
    serv.addArtist(a->getArtistName(), a->getDate(),a->getVenue(), a->getAvailableSeats(), a->getSoldSeats());

    assert(*serv.getArtistAtPosition(0) == *a);

}

void TestService::testAddAdmin() {
    Service serv;
    RepoFile* repoFile = new RepoFileTXT();
    serv.setRepo(repoFile);

    Administrator* a = new Administrator("Alin", "111");
    serv.addAdmin(a->getAdministratorName(), a->getPassword());

    assert(*serv.getAdministratorAtPosition(0) == *a);
}

void TestService::testAddMovie(){
    Service serv;
    RepoFile* repoFile = new RepoFileTXT();
    serv.setRepo(repoFile);

    Movie* m = new Movie("Better", "Alin,Brad,Chris", "03.05.2020", "Cluj", 10, 1000);
    serv.addMovie(m->getTitle(), m->getActors(), m->getDate(), m->getVenue(), m->getAvailableSeats(), m->getSoldSeats());

    assert(*serv.getMovieAtPosition(0) == *m);
}

void TestService::testLogIn() {
    Service serv;
    RepoFile* repoFile = new RepoFileTXT();
    serv.setRepo(repoFile);

    Administrator* admin = new Administrator("admin", "abcd");
    serv.addAdmin(admin->getAdministratorName(),admin->getPassword());

    assert(serv.logIn("admin", "abcd") == 0);
}

void TestService::testSignIn() {
    Service serv;
    RepoFile* repoFile = new RepoFileTXT();
    serv.setRepo(repoFile);

    Administrator* admin = new Administrator("admin", "abcd");

    assert(serv.signIn("admin", "abcd") == 0); // nu l-am adaugat inca deci da 0
}

void TestService::testAll(){
    this->testAddArtist();
    this->testAddMovie();
    this->testLogIn();
    this->testSignIn();
    this->testAddAdmin();
}
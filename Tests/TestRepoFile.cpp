#include "TestRepoFile.h"
#include <cassert>

TestRepoFile::TestRepoFile() {
    Artists* a = new Artists("Michael", "03.05.2010", "Cluj", 10, 10000);
    Movie* m = new Movie("Dreamer","Joe,Michael,Ron","03.05.2010","Cluj", 10, 10000);
    this->artists.push_back(a);
    this->movies.push_back(m);
}

TestRepoFile::~TestRepoFile() = default;

void TestRepoFile::testAll(){
    this->testAddMovie();
    this->testAddArtist();
    this->testLoadFromFileTXT();
    this->testSaveToFileTXT();
    this->testDeleteArtist();
    this->testDeleteMovie();
    this->testGetAllArtists();
    this->testGetAllMovies();
    this->testLoadFromFileCSV();
    this->testSaveToFileCSV();
}

void TestRepoFile::testAddArtist() {
    RepoFile* repoFile = new RepoFileTXT();
    Artists* a = new Artists("Alin", "03.05.2020", "Cluj", 10, 1000);
    repoFile->addArtist(a);
    assert(*repoFile->getArtist(0) == *a->clone());
}

void TestRepoFile::testAddMovie() {
    RepoFile* repoFile = new RepoFileTXT();
    Movie* m = new Movie("Better", "Alin,Brad,Chris", "03.05.2020", "Cluj", 10, 1000);
    repoFile->addMovie(m);
    assert(*repoFile->getMovie(0) == *m->clone());
}

void TestRepoFile::testGetAllMovies() {
    RepoFile* repoFile = new RepoFileTXT();
    Movie* m = new Movie("Better", "Alin,Brad,Chris", "03.05.2020", "Cluj", 10, 1000);
    repoFile->addMovie(m);
    vector<Movie*> some_movies = repoFile->getAllMovies();
    assert(*some_movies[0] == *m->clone());
}

void TestRepoFile::testGetAllArtists() {
    RepoFile* repoFile = new RepoFileTXT();
    Artists* a = new Artists("Alin", "03.05.2020", "Cluj", 10, 1000);
    repoFile->addArtist(a);
    vector<Artists*> some_artists = repoFile->getAllArtists();
    assert(*some_artists[0] == *a->clone());
}

void TestRepoFile::testDeleteMovie() {
    RepoFile* repoFile = new RepoFileTXT();
    Movie* m = new Movie("Better", "Alin,Brad,Chris", "03.05.2020", "Cluj", 10, 1000);
    repoFile->addMovie(m);
    Movie* m2 = new Movie("Better", "Alin,Brad,Chris", "03.05.2020", "Cluj", 10, 1000);
    repoFile->addMovie(m2);
    repoFile->deleteMovie(m2);
    assert(*repoFile->getMovie(0) == *m);
    repoFile->deleteMovie(m);
    assert(repoFile->getSizeMovies() == 0);
}


void TestRepoFile::testDeleteArtist() {
    RepoFile* repoFile = new RepoFileTXT();
    Artists* a = new Artists("Alin", "03.05.2020", "Cluj", 10, 1000);
    repoFile->addArtist(a);
    Artists* a2 = new Artists("Alin", "03.05.2020", "Cluj", 10, 1000);
    repoFile->addArtist(a2);
    repoFile->deleteArtist(a2);
    assert(*repoFile->getArtist(0) == *a);
    repoFile->deleteArtist(a);
    assert(repoFile->getSizeArtists() == 0);
}

void TestRepoFile::testLoadFromFileTXT() {
    RepoFile* repoFile = new RepoFileTXT(this->fileNameInTXT);
    repoFile->loadFromFile();
    assert(repoFile->getSizeArtists() == 0);

}


void TestRepoFile::testSaveToFileTXT() {
    RepoFile* repoFile = new RepoFileTXT(this->fileNameInTXT);
    repoFile->loadFromFile();
    repoFile->setFileName(this->fileNameOutTXT);

    Artists* newArtist = new Artists("Alin", "03.05.2020", "Cluj", 10, 1000);

    repoFile->addArtist(newArtist);
    repoFile->saveToFile();
    repoFile->loadFromFile();

    assert(repoFile->getSizeArtists() == 1);

}

void TestRepoFile::testLoadFromFileCSV() {
    RepoFile* repoFile = new RepoFileCSV(this->fileNameInCSV);
    repoFile->loadFromFile();
    assert(repoFile->getSizeArtists() == 0);
}

void TestRepoFile::testSaveToFileCSV() {
    RepoFile* repoFile = new RepoFileCSV(this->fileNameInCSV);
    repoFile->loadFromFile();
    repoFile->setFileName(this->fileNameOutCSV);

    Artists* newArtist = new Artists("Alin", "03.05.2020", "Cluj", 10, 1000);

    repoFile->addArtist(newArtist);
    repoFile->saveToFile();
    repoFile->loadFromFile();

    assert(repoFile->getSizeArtists() == 1);


}






















































#include "RepoFile.h"

RepoFile::RepoFile() = default;

RepoFile::RepoFile(string fileName) {
    this->fileName = fileName;
}

RepoFile::~RepoFile() = default;

void RepoFile::setFileName(string fileName) {
    this->fileName = fileName;
}


vector<Movie*> RepoFile:: getAllMovies(){
    return this->movies;
}

vector <Artists * > RepoFile :: getAllArtists(){
    return this->artists;
}

vector<Administrator*> RepoFile::getAllAdmins() {
    return this->admins;
}

int RepoFile:: getSizeMovies(){
    return this->movies.size();
}

int RepoFile:: getSizeArtists(){
    return this->artists.size();
}

int RepoFile::getSizeAdmins() {
    return this->admins.size();
}

Movie*  RepoFile:: getMovie(int pos){
    if (pos >= 0 && pos < this->getSizeMovies()) {
        return this->movies[pos]->clone();
    }
    return new Movie();
}

Artists* RepoFile:: getArtist(int pos) {
    if (pos >= 0 && pos < this->getSizeArtists()) {
        return this->artists[pos]->clone();
    }
    return new Artists();
}

Administrator* RepoFile:: getAdministrator(int pos) {
    if (pos >= 0 && pos < this->getSizeAdmins()) {
        return this->admins[pos]->clone();
    }
    return new Administrator();
}


void RepoFile::addMovie(Movie *m) {
    this->movies.push_back(m->clone());
    this->saveToFile();
}

void RepoFile::addArtist(Artists *artist) {
    this->artists.push_back(artist->clone());
    this->saveToFile();
}

void RepoFile::addAdmin(Administrator *admin) {
    this->admins.push_back(admin->clone());
    this->saveToFile();
}

void RepoFile:: deleteMovie(Movie* m){
    for (int i = 0; i < this->movies.size(); i++) {
        if (**(this->movies.begin() + i) == *m) {
            delete this->movies[i];
            this->movies.erase(this->movies.begin() + i);
            this->saveToFile();
            return;
        }
    }
}

void RepoFile::deleteArtist(Artists *artist) {
    for (int i = 0; i < this->artists.size(); i++) {
        if (**(this->artists.begin() + i) == *artist) {
            delete this->artists[i];
            this->artists.erase(this->artists.begin() + i);
            this->saveToFile();
            return;
        }
    }
}

void RepoFile::deleteAdmin(Administrator *admin) {
    for (int i = 0; i < this->admins.size(); i++) {
        if (**(this->admins.begin() + i) == *admin) {
            delete this->admins[i];
            this->admins.erase(this->admins.begin() + i);
            this->saveToFile();
            return;
        }
    }
}

void RepoFile::emptyRepo() {
    for (int i = 0; i < movies.size(); i++) {
        delete this->movies[i];
    }
    this->movies.clear();

    for (int i = 0; i < artists.size(); i++) {
        delete this->artists[i];
    }
    this->artists.clear();

    for (int i = 0; i < admins.size(); i++) {
        delete this->admins[i];
    }
    this->admins.clear();
}






























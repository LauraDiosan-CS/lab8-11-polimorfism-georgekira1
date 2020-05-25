#include "Service.h"


Service::Service() {
    R = NULL;
}

Service::Service(RepoFile*R) {
    this->R = R;
}

Service::~Service() {

}


int Service::signIn(string admin_name, string password) {
    vector<Administrator*> admins = R->getAllAdmins();
    Administrator* n = new Administrator(admin_name, password);
    for (Administrator* n : admins) {
        string name = n->getAdministratorName();
        if (name.compare(admin_name) == 0) {
            return -1;
        }
    }
    R->addAdmin(n);
    return 0;
}

int Service::logIn(string admin_name, string password) {
    vector<Administrator*> admins = R->getAllAdmins();
    Administrator* n = new Administrator(admin_name, password);
    for (Administrator* u : admins) {
        if (*u == *n) {
            return 0;
        }
    }
    return -1;
}

void Service::addArtist(string artist_name, string date, string venue, int available_seats, int sold_seats) {
    Artists*a = new Artists(artist_name, date, venue, available_seats, sold_seats);
    R->addArtist(a);
}

void Service::addMovie(string title, string actors, string date, string venue, int available_seats, int sold_seats){
    Movie* m = new Movie (title, actors, date, venue, available_seats, sold_seats);
    R->addMovie(m);
}

void Service::addAdmin(string admin, string password){
    Administrator* n_admin = new Administrator(admin, password);
    R->addAdmin(n_admin);
}

vector<Movie*> Service::getAllMovies() {
    return R->getAllMovies();
}

vector<Artists*> Service::getAllArtists() {
    return R->getAllArtists();
}

Artists* Service::getArtistAtPosition(int pos) {
    return this->R->getArtist(pos);
}

Movie* Service::getMovieAtPosition(int pod) {
    return this->R->getMovie(pod);
}

Administrator* Service::getAdministratorAtPosition(int pos) {
    return this->R->getAdministrator(pos);
}

void Service::setFileName(string fileName)
{
    this->R->setFileName(fileName);
}

void Service::setRepo(RepoFile* repo)
{
    this->R = repo;
}
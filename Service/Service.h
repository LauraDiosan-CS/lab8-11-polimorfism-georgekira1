#ifndef LAB_8_11_BUN_SERVICE_H
#define LAB_8_11_BUN_SERVICE_H
#pragma once
#include <vector>
#include "../Repository/RepoFile.h"
#include "../Domain/Administrator.h"
#include "../Domain/Artists.h"
#include "../Domain/Movie.h"

class Service {
private:
    RepoFile *R;
public:
    Service();

    Service(RepoFile *R);

    ~Service();

    int signIn(string user, string password);
    int logIn(string user, string password);

    void addArtist(string artist_name, string date, string venue, int available_seats, int sold_seats );
    void addMovie(string title, string actors, string date, string venue, int available_seats, int sold_seats);
    void addAdmin(string admin_name, string password);

    vector<Artists*> getAllArtists();
    vector<Movie*> getAllMovies();


    void setFileName(string fileName);
    void setRepo(RepoFile* repo);

    Artists* getArtistAtPosition(int pos);
    Movie* getMovieAtPosition(int pod);
    Administrator* getAdministratorAtPosition(int pos);


};




#endif //LAB_8_11_BUN_SERVICE_H

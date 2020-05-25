#include "../Domain/Administrator.h"
#include "../Domain/Artists.h"
#include "../Domain/Movie.h"
#include <vector>
#include <string>
#ifndef LAB_8_11_BUN_REPOFILE_H
#define LAB_8_11_BUN_REPOFILE_H


class RepoFile {
protected:
    vector<Movie*> movies;
    vector<Artists*> artists;
    vector<Administrator*> admins;
    string fileName;
public:
    RepoFile();
    RepoFile(string fileName);
    ~RepoFile();
    void setFileName(string fileName);

    vector<Movie*> getAllMovies();
    vector<Artists*> getAllArtists();
    vector<Administrator*> getAllAdmins();

    int getSizeMovies();
    int getSizeArtists();
    int getSizeAdmins();

    Movie* getMovie(int pos);
    Artists* getArtist(int pos);
    Administrator* getAdministrator(int pos);

    void addMovie(Movie* m);
    void addArtist(Artists* artist);
    void addAdmin(Administrator* admin);

    void deleteMovie(Movie* m);
    void deleteArtist(Artists* artist);
    void deleteAdmin(Administrator* admin);

    void emptyRepo();

    virtual void loadFromFile() = 0;
    virtual void saveToFile() = 0;
};



#endif //LAB_8_11_BUN_REPOFILE_H
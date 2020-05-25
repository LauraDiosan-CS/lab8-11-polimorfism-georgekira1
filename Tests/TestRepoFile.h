#ifndef LAB_8_11_BUN_TESTREPOFILE_H
#define LAB_8_11_BUN_TESTREPOFILE_H
#include "../Repository/RepoFileTXT.h"
#include "../Repository/RepoFileCSV.h"


class TestRepoFile {
private:
    const string fileNameInTXT = "TestFestivalsIn.txt";
    const string fileNameOutTXT = "TestFestivalsOut.txt";
    const string fileNameInCSV = "TestFestivalsIn.csv";
    const string fileNameOutCSV = "TestFestivalsOut.csv";

    vector<Movie*> movies;
    vector<Artists*> artists;

    void testGetAllMovies();
    void testGetAllArtists();
    void testAddMovie();
    void testAddArtist();
    void testDeleteMovie();
    void testDeleteArtist();

    void testLoadFromFileTXT();
    void testSaveToFileTXT();

    void testLoadFromFileCSV();
    void testSaveToFileCSV();

public:
    TestRepoFile();
    ~TestRepoFile();
    void testAll();
};


#endif //LAB_8_11_BUN_TESTREPOFILE_H


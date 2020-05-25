#ifndef LAB_8_11_BUN_REPOFILECSV_H
#define LAB_8_11_BUN_REPOFILECSV_H
#include "RepoFile.h"
#include "../Domain/Artists.h"
#include "../Domain/Movie.h"
#include <fstream>
#include <string>

using namespace std;

class RepoFileCSV : public RepoFile {

public:
    RepoFileCSV();
    RepoFileCSV(string fileName);
    ~RepoFileCSV();
    void loadFromFile() ;
    void saveToFile();

};


#endif //LAB_8_11_BUN_REPOFILECSV_H

#include "RepoFile.h"
#include <fstream>
#include <string>
#ifndef LAB_8_11_BUN_REPOFILETXT_H
#define LAB_8_11_BUN_REPOFILETXT_H

using namespace std;

class RepoFileTXT : public RepoFile {

public:
    RepoFileTXT();
    RepoFileTXT(string fileName);
    ~RepoFileTXT();
    void loadFromFile() ;
    void saveToFile();

};



#endif //LAB_8_11_BUN_REPOFILETXT_H



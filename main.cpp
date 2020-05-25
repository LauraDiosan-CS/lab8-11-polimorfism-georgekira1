#include <iostream>
#include "Tests/TestArtists.h"
#include "Tests/TestMovie.h"
#include "Tests/TestAdministrator.h"
#include "Tests/TestRepoFile.h"
#include "Tests/TestService.h"
#include "Repository/RepoFileTXT.h"
#include "Repository/RepoFileCSV.h"
#include "Service/Service.h"
#include "UI/UI.h"

using namespace std;

int main() {

    TestArtists testArtists;
    testArtists.testAll();

    TestMovie testMovie;
    testMovie.testAll();

    TestAdministrator testAdministrator;
    testAdministrator.testAll();

    TestRepoFile testRepoFile;
    testRepoFile.testAll();

    TestService testService;
    testService.testAll();

    RepoFile* R;
    cout << "Insert 1 for CSV files and 2 for TXT files : ";
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
        R = new RepoFileCSV("Obiecte.csv");
        Service S(R);
        UI UI(S);
        UI.runSignIn();
    }
    if (cmd == 2) {
        R = new RepoFileTXT("Obiecte.txt");
        Service S(R);
        UI UI(S);
        UI.runSignIn();
    }


}

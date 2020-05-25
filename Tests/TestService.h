#ifndef LAB_8_11_BUN_TESTSERVICE_H
#define LAB_8_11_BUN_TESTSERVICE_H
#pragma once
#include <vector>
#include "../Repository/RepoFileTXT.h"
#include "../Repository/RepoFile.h"
#include "../Service/Service.h"
#include "../Domain/Artists.h"
#include "../Domain/Movie.h"
#include "../Domain/Administrator.h"

class TestService {
private:

    void testAddArtist();
    void testAddAdmin();
    void testAddMovie();
    void testLogIn();
    void testSignIn();

public:
    TestService();
    ~TestService();
    void testAll();
};


#endif //LAB_8_11_BUN_TESTSERVICE_H

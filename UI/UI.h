#ifndef LAB_8_11_BUN_UI_H
#define LAB_8_11_BUN_UI_H
#pragma once
#include <vector>
#include <string>
#include "../Domain/Administrator.h"
#include "../Domain/Artists.h"
#include "../Domain/Movie.h"
#include "../Repository/RepoFileTXT.h"
#include "../Service/Service.h"

class UI {
private:
    Service serv;
    void showSignInMenu();
    void showAppMenu();

    void signIn();
    void logIn();

    void handleAddArtist();
    void handleAddMovie();

    void showArtists();
    void showMovies();

public:
    UI();
    UI(Service& S);
    ~UI();
    void runSignIn();
    void runMenu();

};


#endif //LAB_8_11_BUN_UI_H

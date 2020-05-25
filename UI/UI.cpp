#include "UI.h"
#include <iostream>
using namespace std;

UI::UI() = default;

UI::UI(Service& serv) {
    this->serv = serv;
}

UI::~UI() = default ;

void UI::showSignInMenu() {
    cout << "  1.  Sign In" << endl;
    cout << "  2.  Log In" << endl;
    cout << "  3.  Exit" << endl;
}

void UI::showAppMenu() {
    cout << "  1.  Add Artist" << endl;
    cout << "  2.  Add movie" << endl;
    cout << "  3.  Show movies" << endl;
    cout << "  4.  Show artists" << endl;
    cout << "  5.  Exit" <<endl;
}

void UI::handleAddArtist() {
        string name;
        cout << "Artist name: ";
        cin >> name;

        string date;
        cout << "Date: ";
        cin >> date;

        string place;
        cout << "Venue: ";
        cin >> place;

        int ticketsTotal;
        cout << "Tickets available: ";
        cin >> ticketsTotal;

        int sold_seats;
        cout << "Sold tickets: ";
        cin >> sold_seats;

    this->serv.addArtist(name, date, place, ticketsTotal, sold_seats);
}

void UI::handleAddMovie() {

    string title;
    cout << "Title: ";
    cin >> title;

    string actors;
    cout << "Actors : ";
    cin >> actors;

    string date;
    cout << "Date: ";
    cin >> date;

    string place;
    cout << "Venue: ";
    cin >>place;

    int ticketsTotal;
    cout << "Tickets available: ";
    cin >> ticketsTotal;

    int sold_seats;
    cout << "Sold tickets: ";
    cin >> sold_seats;

    this->serv.addMovie(title, actors, date, place, ticketsTotal, sold_seats);
}

void UI::showArtists() {
    vector <Artists*> artists = serv.getAllArtists();
    for (Artists *a : artists)
    {
        cout << a->toString(" ").erase(0,6) << endl;
    }
}

void UI::showMovies() {
    vector <Movie*> movies = serv.getAllMovies();
    for (Movie* m : movies)
        {
            cout << m->toString(" ").erase(0,5) << endl;
        }
}


void UI::signIn() {
    string admin_name;
    string password;
    cout << "Insert admin name: ";
    cin >> admin_name;
    cout << "Insert password: ";
    cin >> password;

    int r = serv.signIn(admin_name, password);
    if (r == -1) {
        cout << endl;
        cout << "User name is not available!" << endl;
    }
    if (r == 0) {
        cout << endl;
        cout << "You signed in!" << endl;
        }
    }

void UI::logIn() {
    string admin_name;
    string password;
    cout << endl;
    cout << "Insert admin name: ";
    cin >> admin_name;
    cout << "Insert password: ";
    cin >> password;
    int r = serv.logIn(admin_name, password);
    if (r == -1) {
        cout << endl;
        cout << "Admin name or password invalid!" << endl;
    }
    else {
        cout << endl;
        cout << "Login successful!" << endl;
        runMenu();
    }
}

void UI::runMenu() {
    bool ok = false;
    showArtists();
    showMovies();
    while (!ok) {
        showAppMenu();

        int op;
        cout << "  Insert your option: ";
        cin >> op;
        switch (op)
        {
            case(1): { this->handleAddArtist(); break; }
            case(2): { this->handleAddMovie(); break; }
            case(3): { this->showMovies(); break; }
            case(4): {this->showArtists(); break; }
            case(5): { ok = true; break; }
            default:
                cout << endl;
                cout << " Try another option" << endl;
        }
    }
}

void UI::runSignIn() {
    bool ok = false;
    while (!ok) {
        showSignInMenu();
        int cmd;
        cout << "  Insert your option: ";
        cin >> cmd;
        switch (cmd)
        {   case(1): { this->signIn(); break; }
            case(2): { this->logIn(); break; }
            case(3):{  ok = true; break; }
            default:
                cout << endl;
                cout << "Invalid option! " << endl;
        }
    }
}
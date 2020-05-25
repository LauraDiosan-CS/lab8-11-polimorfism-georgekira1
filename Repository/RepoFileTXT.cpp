#include "RepoFileTXT.h"

RepoFileTXT::RepoFileTXT() : RepoFile()
{
}

RepoFileTXT::RepoFileTXT(string fileName) : RepoFile(fileName)
{
    loadFromFile();
}

RepoFileTXT::~RepoFileTXT()
= default;

void RepoFileTXT::loadFromFile() {
    ifstream f(this->fileName);
    if (f.is_open()) {
        this->emptyRepo();
        string linie;
        string delim = " ";
        while (getline(f, linie)) {
            if (linie.substr(0, 6) == "Artist") {
                linie = linie.erase(0, 7);

                int pos = linie.find(delim);
                string artist_name = linie.substr(0, pos);
                linie = linie.erase(0, pos + 1);

                pos = linie.find(delim);
                string date = linie.substr(0, pos);
                linie = linie.erase(0, pos + 1);

                pos = linie.find(delim);
                string venue = linie.substr(0, pos);
                linie = linie.erase(0, pos + 1);

                pos = linie.find(delim);
                int available_seats = stoi(linie.substr(0, pos));
                linie = linie.erase(0, pos + 1);

                pos = linie.find(delim);
                int sold_seats = stoi(linie.substr(0, pos));

                Artists *a = new Artists(artist_name, date, venue, available_seats, sold_seats);
                this->artists.push_back(a);
            } else if (linie.substr(0, 5) == "Movie") {
                linie = linie.erase(0, 6);

                int pos = linie.find(delim);
                string title = linie.substr(0, pos);
                linie = linie.erase(0, pos + 1);

                pos = linie.find(delim);
                string actors = linie.substr(0, pos);
                linie = linie.erase(0, pos + 1);

                pos = linie.find(delim);
                string date = linie.substr(0, pos);
                linie = linie.erase(0, pos + 1);

                pos = linie.find(delim);
                string venue = linie.substr(0, pos);
                linie = linie.erase(0, pos + 1);

                pos = linie.find(delim);
                int available_seats = stoi(linie.substr(0, pos));
                linie = linie.erase(0, pos + 1);

                pos = linie.find(delim);
                int sold_seats = stoi(linie.substr(0, pos));

                Movie *m = new Movie(title, actors, date, venue, available_seats, sold_seats);
                this->movies.push_back(m);

            } else if (linie.substr(0, 13) == "Administrator") {
                linie = linie.erase(0, 14);

                int pos = linie.find(delim);
                string administrator_name = linie.substr(0, pos);
                linie = linie.erase(0, pos + 1);

                pos = linie.find(delim);
                string password = linie.substr(0, pos);

                Administrator *admin = new Administrator(administrator_name, password);
                this->admins.push_back(admin);

            }
        }
        f.close();
    }
}


void RepoFileTXT::saveToFile()
{
    ofstream f(this->fileName);
    if (f.is_open()) {
        for (Movie* m : this->movies) {
            f << m->toString(" ") << endl;
        }
        for (Artists* artist : this->artists) {
            f << artist->toString(" ") << endl;
        }
        for (Administrator* admin : this->admins) {
            f << admin->toString(" ") << endl;
        }
    }
}
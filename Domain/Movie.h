#ifndef LAB_8_11_BUN_MOVIE_H
#define LAB_8_11_BUN_MOVIE_H
#include <iostream>
#include "Festival.h"
#include <string>

class Movie : public Festival {
private:
    string title;
    string actors;

public:
    Movie();
    Movie(string title, string actors, string date, string venue, int available_seats, int sold_seats);
    Movie (const Movie& m);
    ~Movie();

    Movie * clone () override;

    string getTitle();
    string getActors();
    void setTitle(string title);
    void setActors(string actors);

    Movie& operator=(const Movie& m);
    bool operator==(const Movie& m);
    string toString(string delim) override;
};



#endif //LAB_8_11_BUN_MOVIE_H
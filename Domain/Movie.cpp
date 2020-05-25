#include "Movie.h"

Movie:: Movie() : Festival(){

}

Movie:: Movie(string title, string actors, string date, string venue,  int available_seats, int sold_seats) : Festival (date, venue,  available_seats, sold_seats){
    this->title = title;
    this->actors = actors;
}

Movie:: Movie(const Movie& m) : Festival (m){
    this->title = m.title;
    this->actors = m.actors;
}

Movie:: ~Movie(){

}
Movie* Movie:: clone (){
    return new Movie(this->title, this->actors, this->date, this->venue,  this->available_seats, this->sold_seats);
}

string Movie:: getTitle(){
    return this->title;
}

string Movie:: getActors() {
    return this->actors;
}

void Movie::setTitle(string title) {
    this->title = title;
}

void Movie:: setActors(string actors){
    this->actors = actors;
}

Movie& Movie:: operator=(const Movie& m){
    Festival:: operator=(m);
    this->title = m.title;
    this->actors = m.actors;
    return *this;
}

bool Movie:: operator==(const Movie& m){
    return Festival::operator==(m) && this->title == m.title  &&  this->actors == m.actors ;
}

string Movie:: toString(string delim){
    return "Movie" +  this->title + delim + this->actors + delim + Festival::toString(delim);
}

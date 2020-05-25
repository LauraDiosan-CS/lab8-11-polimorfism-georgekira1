#include "Artists.h"

Artists:: Artists() : Festival(){

}

Artists:: Artists(string artist_name, string date, string venue, int available_seats, int sold_seats) :  Festival( date, venue,  available_seats, sold_seats){
    this->artist_name = artist_name;
}

Artists::  Artists (const Artists& a) : Festival(a){
    this->artist_name = a.artist_name;
}

Artists:: ~Artists()= default;

Artists* Artists:: clone(){
    return new Artists(this->artist_name, this->date, this->venue, this->available_seats, this->sold_seats);
}

string Artists:: getArtistName(){
    return this->artist_name;
}

void Artists::setArtistName(string artist_name) {
    this->artist_name = artist_name;
}

Artists& Artists:: operator=(const Artists& a){
    Festival::operator=(a);
    this->artist_name = a.artist_name;
    return *this;
}

bool Artists:: operator==(const Artists& a){
    return Festival::operator==(a) && this->artist_name == a.artist_name;
}

string Artists:: toString(string delim){
    return "Artist" + delim + this->artist_name + delim + Festival::toString(delim) ;
}

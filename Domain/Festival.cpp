#include "Festival.h"
#include <iostream>

using namespace std;

Festival::Festival() {
    this-> available_seats = 0;
    this-> sold_seats = 0;
}

Festival:: Festival(string date, string venue, int available_seats, int sold_seats){
    this->date = date;
    this->venue = venue;
    this->available_seats = available_seats;
    this->sold_seats = sold_seats;
}

Festival::Festival(const Festival &f) {
    this->date = f.date;
    this->venue = f.venue;
    this->available_seats = f.available_seats;
    this->sold_seats = f.sold_seats;
}

Festival::~Festival()  = default;

Festival* Festival:: clone(){
    return new Festival(this->date, this->venue, this->available_seats, this->sold_seats);
}

string Festival:: getDate(){
    return this->date;
}

string Festival:: getVenue(){
    return this->venue;
}

int Festival::getAvailableSeats() {
    return this->available_seats;
}

int Festival::getSoldSeats() {
    return this->sold_seats;
}

void Festival:: setDate(string a_date) {
    this->date = a_date;
}

void Festival::setVenue(string a_venue) {
    this->venue = a_venue;
}

void Festival::setAvailableSeats(int available_seats) {
    this->available_seats = available_seats;
}

void Festival:: setSoldSeats(int sold_seats) {
    this->sold_seats = sold_seats;
}

Festival& Festival:: operator=(const Festival& f){
    this->date = f.date;
    this->venue = f.venue;
    this->available_seats = f.available_seats;
    this->sold_seats = f.sold_seats;

    return *this;
}

bool Festival::operator==(const Festival& f){
    return this->date == f.date && this->venue == f.venue && this->available_seats == f.available_seats &&  this->sold_seats == f.sold_seats;
}


string Festival::toString(string delim) {
    return this->date + delim + this->venue + delim + to_string(this->available_seats) + delim + to_string(this->sold_seats);
}
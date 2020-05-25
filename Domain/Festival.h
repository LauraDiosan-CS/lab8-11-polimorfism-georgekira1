#ifndef LAB_8_11_BUN_FESTIVAL_H
#define LAB_8_11_BUN_FESTIVAL_H
#include <iostream>
#include <string>

using namespace std;

class Festival {
protected:
    string date;
    string venue;
    int available_seats;
    int sold_seats;

public:
    Festival();
    Festival(string date, string venue, int available_seats, int sold_seats);
    Festival(const Festival& f);
    ~Festival();

    virtual Festival* clone();

    string getDate();
    string getVenue();
    int getAvailableSeats();
    int getSoldSeats();

    void setDate(string a_date);
    void setVenue(string a_venue);
    void setAvailableSeats(int available_seats);
    void setSoldSeats(int sold_seats);

    Festival& operator=(const Festival& f);
    bool operator==(const Festival& f);
    virtual string toString(string delim);
};



#endif //LAB_8_11_BUN_FESTIVAL_H

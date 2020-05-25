#ifndef LAB_8_11_BUN_ARTISTS_H
#define LAB_8_11_BUN_ARTISTS_H
#include <iostream>
#include <string>
#include "Festival.h"



class Artists : public Festival  {
private:
    string artist_name;

public:
    Artists();
    Artists(string artist_name, string date, string venue, int available_seats, int sold_seats);
    Artists (const Artists& a);
    ~Artists();

    Artists* clone() override;

    string getArtistName();
    void setArtistName(string artist_name);

    Artists& operator=(const Artists& a);
    bool operator==(const Artists& a);
    string toString(string delim) override;
};



#endif //LAB_8_11_BUN_ARTISTS_H

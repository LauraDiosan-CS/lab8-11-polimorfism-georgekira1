#ifndef LAB_8_11_BUN_ADMINISTRATOR_H
#define LAB_8_11_BUN_ADMINISTRATOR_H
#include <iostream>
#include <string>

using namespace std;

class Administrator {

private:
    string administrator_name;
    string password;

public:
    Administrator();
    Administrator(string administrator_name, string password);
    Administrator (const Administrator& admin);
    ~Administrator();

    string getAdministratorName();
    string getPassword();

    void setAdministratorName(string administrator_name);
    void setPassword(string password);

    Administrator* clone();

    Administrator& operator = (const Administrator& admin);
    bool operator == (const Administrator& admin);
    string toString(string delim);
};


#endif //LAB_8_11_BUN_ADMINISTRATOR_H

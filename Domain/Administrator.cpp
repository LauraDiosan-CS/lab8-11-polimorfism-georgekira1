#include "Administrator.h"

Administrator::Administrator(){
    this->administrator_name = "";
    this->password = "";
}

Administrator:: Administrator(string administrator_name, string password){
    this->administrator_name = administrator_name;
    this-> password = password ;
}

Administrator::Administrator(const Administrator &admin) {
    this->administrator_name = admin.administrator_name;
    this-> password = admin.password;
}

Administrator::~Administrator() = default;

string Administrator::getAdministratorName() {
    return this->administrator_name;
}

string Administrator:: getPassword() {
    return this->password;
}

void Administrator::setAdministratorName(string administrator_name) {
    this->administrator_name = administrator_name;
}

void Administrator::setPassword(string password) {
    this->password = password;
}

Administrator& Administrator:: operator=(const Administrator& admin){
    this->setAdministratorName(admin.administrator_name);
    this->setPassword(admin.password);
    return *this;
}

bool Administrator::operator==(const Administrator& admin){
    return (administrator_name == admin.administrator_name);
}

Administrator* Administrator::clone() {
    return new Administrator(this->administrator_name, this->password);
}

string Administrator::toString(string delim) {
    return "Administrator" + delim + this->administrator_name + delim + this->password;
}

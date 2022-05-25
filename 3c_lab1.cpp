#include <iostream>

using std::cout, std::endl, std::string;

const string MY_NAME = "Khoi Duong";

int main (void){
    string name, last_name, first_name;

    last_name = MY_NAME.substr(5,5);
    first_name = MY_NAME.substr(0,1);
    name = "Name: " + last_name + ", " + first_name;
    cout << name << endl;

    return 0;
}

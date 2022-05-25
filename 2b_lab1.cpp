#include <iostream>

using namespace std;

int main(){
    string first_name, last_name;
    int month, day, year;
    cout << "Input your name (first & last name): ";
    cin >> first_name >> last_name;
    cout << "Input date (month, day, and year): ";
    cin >> month >> day >> year;
    cout << "Name: " << last_name << ", " << first_name << endl;
    cout << endl;
    cout << endl;
    cout << "Today's date: " << month << "/" << day << "/" << year;

    return 0;
}

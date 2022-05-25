#include <iostream>
#include <iomanip>

using std::cout, std::setw, std::endl, std::right;

int main (void){
    cout << right << setw(16) << "Good Morning";
    cout << endl;
    cout << right << setw(12) << "Sarah";
    cout << endl;
    cout << right << setw(14) << "Sunshine!";

    return 0;
}

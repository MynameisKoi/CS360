#include <iostream>
#include <iomanip>

using std::cout, std::setw, std::endl, std::right;

int main (void){
    cout << right << setw(16) << "Good Morning";
    cout << right << setw(4) << " ";
    cout << right << setw(12) << "Sarah";
    cout << right << setw(8) << " ";
    cout << right << setw(14) << "Sunshine!";

    return 0;
}

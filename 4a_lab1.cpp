#include <iostream>
#include <iomanip>

using std::cout, std::showpoint, std::fixed, std::right, std::setw;

const int a = 1066;
const int b = 1492;
const int c = 512;
const int d = 1;
const int e = -23;

int main (void){

    cout.precision(5);
    cout << fixed  << showpoint;
    cout << right << setw(10) << a << '\n';
    cout << right << setw(10) << b << '\n';
    cout << right << setw(10) << c << '\n';
    cout << right << setw(10) << d << '\n';
    cout << right << setw(10) << e << '\n';

    return 0;
}

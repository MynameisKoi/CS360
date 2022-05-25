#include <iostream>
#include <iomanip>

using std::cout, std::setprecision, std::fixed, std::showpoint, std::setw, std::right;

const float a = 23.62;
const float b = 46.0;
const float c = 43.4443;
const float d = 100.1;
const float e = 98.98;

int main (void){
    cout.precision(2);
    cout << fixed  << showpoint;
    cout << right << setw(10) << a << '\n';
    cout << right << setw(10) << b << '\n';
    cout << right << setw(10) << c << '\n';
    cout << right << setw(10) << d << '\n';
    cout << right << setw(10) << e << '\n';

    return 0;
}

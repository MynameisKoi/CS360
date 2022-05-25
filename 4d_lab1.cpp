#include <iostream>
#include <iomanip>

using std::cout, std::setprecision, std::fixed;

const float a = 23.62;
const float b = 46.0;
const float c = 43.4443;
const float d = 100.1;
const float e = 98.98;

int main (void){
    float answer = a+b+c+d+e;
    cout << "The sum of the numbers is: " << "";
    cout << fixed << setprecision(4) << answer << '\n';

    return 0;
}

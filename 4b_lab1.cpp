#include <iostream>
#include <iomanip>

using std::cout, std::setprecision, std::fixed, std::endl;

const float a = 1066;
const float b = 1492;
const float c = 512;
const float d = 1;
const float e = -23;

int main (void){
    float answer = (a+b) / (c+d+e);
    cout << "The answer is " << "";
    cout << fixed  << setprecision(4) << answer << endl;

    return 0;
}


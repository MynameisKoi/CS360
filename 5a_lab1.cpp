#include <iostream>
#include <iomanip>

using std::cout;

void spacing (int n){
    for (int i = 0; i < n; i++) {
        cout << " ";
    }
}

int main (void){
    spacing(4);
    cout << "Good morning";
    spacing(11);
    cout << "Sarah";
    spacing(13);
    cout << "Sunshine!";

    return 0;
}

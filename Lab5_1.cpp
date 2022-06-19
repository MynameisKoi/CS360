#include <iostream>
#include <vector>
using namespace std;

// create a function that takes a vector of integers and reverses its elements
void rvrs(vector<int>& vct)
{
    int size = vct.size();
    for (int i = 0; i < size / 2; i++)
    {
        int temp = vct[i];
        vct[i] = vct[size - i - 1];
        vct[size - i - 1] = temp;
    }
}

int main(){
    vector<int> vct;
    int num;
    cout << "Enter numbers to be reversed!\n";
    cout << "Type 'end' to stop: ";
    while (cin >> num)
    {
        vct.push_back(num);
    }
    rvrs(vct);
    cout << "Reversed: ";
    for (int i = 0; i < vct.size(); i++)
    {
        cout << vct[i] << " ";
    }
    cout << endl;

    return 0;
}

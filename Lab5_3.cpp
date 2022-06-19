#include <iostream>
#include <vector>
using namespace std;

//create a class Tensor with a method sort to sort a vector input argument and print it out
class Tensor
{
public:
    void sort(vector<int>& vct)
    {
        int size = vct.size();
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - 1; j++)
            {
                if (vct[j] > vct[j + 1])
                {
                    int temp = vct[j];
                    vct[j] = vct[j + 1];
                    vct[j + 1] = temp;
                }
            }
        }
    }
};

int main(){
    vector<int> vct;
    int num;
    cout << "Enter numbers to be sorted!\n";
    cout << "Type 'end' to stop: ";
    while (cin >> num)
    {
        vct.push_back(num);
    }
    Tensor tensor;
    tensor.sort(vct);
    cout << "Sorted: ";
    for (int i = 0; i < vct.size(); i++)
    {
        cout << vct[i] << " ";
    }
    cout << endl;

    return 0;
}

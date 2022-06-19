#include <iostream>
#include <vector>
using namespace std;

void LowerLeft_to_UpperRight()
{
    int row, col;
    //create a vector of vectors named vals
    vector<vector<int>> vals;
    //input the values into vals
    cout << "Enter number of rows: ";
    cin >> row;
    cout << "Enter number of columns: ";
    cin >> col;
    cout << endl;
    for (int i = 0; i < row; i++)
    {
        vector<int> temp;
        for (int j = 0; j < col; j++)
        {
            int num;
            cout << "Enter value for row " << i + 1 << " column " << j + 1 << ": ";
            cin >> num;
            temp.push_back(num);
        }
        vals.push_back(temp);
    }
    cout << endl;

    //print out the matrix
    cout << "Matrix: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << vals[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    //print the values that lie on the lower-left to upper-right diagonal of vals
    cout << "Diagonal lower-left to upper-right: " << endl;
    col = 0;
    for (int row = vals.size() - 1 ; row > -1 ; row--)
    {
        cout << vals[row][col] << " ";
        col++;
    }
}

int main(){
    LowerLeft_to_UpperRight();
    return 0;
}

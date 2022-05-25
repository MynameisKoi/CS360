#include <iostream>
using namespace std;

int main()
{
    int i,j;
    cout << "\n\n Display the pattern like a diamond:\n";
    cout << "----------------------------------------\n";

//Draw the first line of the diamond
    for (i=0; i<6; i++)
    {
        cout << " ";
    }
    cout << "*";
    cout << endl;

//Use loop to draw the first half of the diamond
    for(i=0;i<6;i++)
    {
        for(j=1;j<=5-i;j++)
            cout <<" ";
        cout << "*";
        for(j=1;j<=2*i+1;j++)
            cout <<" ";
        cout << "*";
        for(j=1;j<=5-i;j++)
            cout << " ";
        cout<<endl;
   }

//Use loop to draw the other half of the diamond
   for(i=4;i>=0;i--)
    {
        for(j=1;j<=5-i;j++)
            cout <<" ";
        cout << "*";
        for(j=1;j<=2*i+1;j++)
            cout <<" ";
        cout << "*";
        for(j=1;j<=5-i;j++)
            cout << " ";
        cout<<endl;
   }

// Draw the last line of the diamond
    for (i=0; i<6; i++)
    {
        cout << " ";
    }
    cout << "*";
    cout << endl;
}

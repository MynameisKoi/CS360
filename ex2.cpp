#include <iostream> //include the input-output stream. This is required in almost every C++ program.

using namespace std;

int main (){
    int  inches; //Declare the type of variable "inches"

    cout  << "Enter the number of inches on a side " //Print out the instruction on the screen
             << endl; //Endline
    cout  << "Press the return key." //Print out the instruction on the screen
             << endl; //Endline
    cin    >> inches; //Read the input
    cout  << "The area is "  << inches * inches  <<"." //Print out the area of the square with the function inches * inches
         << endl; //Endline

    return 0; //Return 0 for finish the program
}

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

class Complex{
    private:
float real, imag;
float r_polar, theta;
string r, i;

    public:
//Default constructor
    Complex(){
        real = 0;
        imag = 0;
    }

//Constructor with 2 arguments
    Complex(float r, float i){
        real = r;
        imag = i;
    }

//Constructor that build complex number from string
    Complex(string str){
        vector <int> v;
        stringstream ss(str);
        for (int i; ss >> i;) {
            v.push_back(i);
            if (ss.peek() == ',')
                ss.ignore();
        }
        real = v[0];
        imag = v[1];
    }

//Length method
    void length(void){
        r = std::to_string(real);
        i = std::to_string(imag);
        cout << "The length of string is: " << r.length() << "(real), " << i.length() << "(imaginary).";
    }

//Empty method
    void empty(void){
        r = std::to_string(real);
        i = std::to_string(imag);
        if (r.empty()) {cout << "Real part is an empty string.";}
        if (i.empty()) {cout << "Imaginary part is an empty string.";}
    }

//Calculate the conjugate of the complex number
    Complex com_conjugate(void){
        Complex conjugate;
        conjugate.real = real;
        conjugate.imag = -1 * imag;
        return conjugate;
    }

//Add function
    Complex plus(Complex c1){
        Complex ans;
        ans.real = real + c1.real;
        ans.imag = imag + c1.imag;
        return ans;
    }

//Subtract function
    Complex minus(Complex c1){
        Complex ans;
        ans.real = real - c1.real;
        ans.imag = imag - c1.imag;
        return ans;
    }

//Multiply function
    Complex multiply(Complex c1){
        Complex ans;
        ans.real = (real * c1.real) + (-1 * (imag * c1.imag));
        ans.imag = (imag * c1.real) + (real * c1.imag);
        return ans;
    }

//Divide function
    Complex divide(Complex c1){
        Complex ans;
        //Call conjugate function to find conjugate of c1
        Complex temp = c1.com_conjugate();
        //Calculate numerator and denominator
        Complex num = (*this).multiply(temp);
        Complex den = c1.multiply(temp);
        //Divide the numerator by denominator
        ans.real = num.real / den.real;
        ans.imag = num.imag / den.real;
        return ans;
    }

//Change the complex number to polar form with magnitude and angle
    int angle(void){
        r_polar = sqrt(pow(real,2) + pow(imag,2));
        theta = atan2(imag,real);
        cout << "(" << std::setprecision(3) << r_polar << " > " << std::setprecision(3) << theta << ")" << endl;
        return 0;
    }

//Print method
    void print(void){
    // if imaginary part is positive then
    //  it display real + i img complex number
    if (imag >= 0) {
        cout << std::setprecision(3) << real << "+i" << std::setprecision(3) << imag << endl;
    }

    // if imaginary part is negative then
    //  it display real - i img complex number
    else {
        cout << std::setprecision(3) << real << "-i" << std::setprecision(3) << (-1) * imag << endl;
    }
    }
};

int main(){
    Complex c1(6, 3);
    Complex c2("7, -5");
    cout << "Complex c1 polar form: ";
    c1.angle();
    cout << "Complex c2 polar form: ";
    c2.angle();
    Complex c3 = c1.plus(c2);
    cout << "Addition: ";
    c3.print();
    cout << "Addition (in polar form): ";
    c3.angle();
    Complex c4 = c1.minus(c2);
    cout << "Minus: ";
    c4.print();
    cout << "Minus (in polar form): ";
    c4.angle();
    Complex c5 = c1.multiply(c2);
    cout << "Multiply: ";
    c5.print();
    cout << "Multiply (in polar form): ";
    c5.angle();
    Complex c6 = c1.divide(c2);
    cout << "Divide: ";
    c6.print();
    cout << "Divide (in polar form): ";
    c6.angle();

    return 0;
}

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class Poly{
    private:
        int coeff;
        int exp;
        int array[10];
    // constructor takes coefficient and exponent as arguments
    // use an object to store exponents and coefficients
    // Poly c = Poly(3,4) + Poly(2,2) + Poly(7,1) + Poly(-5,0)
    public:
    Poly(){
        for (int i = 0; i < 10; i++) {
            array[i] = 0;
        }
    }
    Poly(int c, int e){
        for (int i = 0; i < 10; i++){
            if (i == e) {
                array[i] = c;
            }
            else {
                array[i] = 0;
            }
        }
    }

    // overload += operator
    Poly operator+=(Poly rhs){
        for (int i = 0; i < 10; i++){
            array[i] += array[i] + rhs.array[i];
        }
        return *this;
    }

    // overload -= operator
    Poly operator-=(Poly &rhs){
        for (int i = 0; i < 10; i++){
            array[i] += array[i] - rhs.array[i];
        }
        return *this;
    }

    // add two polynomials
    Poly operator+(Poly p){
        Poly q;
        for (int i = 0; i < 10; i++){
            q.array[i] = array[i] + p.array[i];
        }
        return q;
    }

    // subtract two polynomials
    Poly operator-(Poly p){
        Poly q;
        for (int i = 0; i < 10; i++){
            q.array[i] = array[i] - p.array[i];
        }
        return q;
    }

    // multiply polynomials by a constant
    Poly operator*(int c){
        Poly q;
        for (int i = 0; i < 100; i++){
            q.array[i] = array[i] * c;
        }
        return q;
    }

    // evaluate polynomials at a specific value for x
    int eval(int x){
        int sum = 0;
        for (int i = 0; i < 10; i++){
            sum += array[i] * pow(x, i);
        }
        return sum;
    }

    // display the polynomial
    void display(){
        for (int i = 0; i < 10; i++){
            if (array[i] != 0){
                if (i == 0){
                    cout << array[i];
                }
                else if (i == 1){
                    cout << array[i] << "x";
                }
                else{
                    cout << array[i] << "x^" << i;
                }
                cout << " + ";
            }
        }
        cout << "0" << endl;
    }
};

int main(){
    Poly p0(3,2);
    cout << "p0 = "; p0.display();
    Poly p1, p2;
    p1 += Poly(3,4) + Poly(2,2) + Poly(7,1) + Poly(-5,0);
    cout << "p1 = "; p1.display();
    p2 += Poly(1,1) + Poly(2,0) + Poly(3,3) + Poly(4,4);
    cout << "p2 = "; p2.display();
    Poly p3 = p1 + p2;
    cout << "Addition: "; p3.display();
    Poly p4 = p1 - p2;
    cout << "Subtraction: "; p4.display();
    Poly p5 = p1 * 2;
    cout << "Multiplication: "; p5.display();
    int x = 4;
    cout << "The value of p1 at x = " << x << " is: " << p1.eval(x) << endl;
    cout << "The value of p2 at x = " << x << " is: " << p2.eval(x) << endl;
    x = 7;
    cout << "The value of p3 at x = " << x << " is: " << p3.eval(x) << endl;
    x = 5;
    cout << "The value of p4 at x = " << x << " is: " << p4.eval(x) << endl;

    return 0;
}

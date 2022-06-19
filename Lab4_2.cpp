#include <iostream>
#include <numeric>
using namespace std;

//create a class Rational to perform arithmetic with fractions
class Rational{
    private:
        int numerator;
        int denominator;

    public:
        // default constructor
        Rational(){
            numerator = 0;
            denominator = 1;
        }
        // constructor with 2 parameters
        Rational(int n, int d): numerator(n), denominator(d){
            if(d == 0){
                throw "Denominator cannot be zero";
            }
        }
        // constructor taking another Rational object as parameter
        Rational(const Rational& r): numerator(r.numerator), denominator(r.denominator){}

        // store the fraction in reduced form
        void reduce(){
            int div = gcd( numerator, denominator );
            numerator /= div;
            denominator /= div;
        }

        // add two fractions
        Rational operator+( const Rational& rhs ) const{
            int n = numerator * rhs.denominator + rhs.numerator * denominator;
            int d = denominator * rhs.denominator;
            // void reduce is called to store the fraction in reduced form
            Rational result( n, d );
            result.reduce();
            return result;
        }

        // subtract two fractions
        Rational operator-( const Rational& rhs ) const{
            int n = numerator * rhs.denominator - rhs.numerator * denominator;
            int d = denominator * rhs.denominator;
            // void reduce is called to store the fraction in reduced form
            Rational result( n, d );
            result.reduce();
            return result;
        }

        // multiply two fractions
        Rational operator*( const Rational& rhs ) const{
            int n = numerator * rhs.numerator;
            int d = denominator * rhs.denominator;
            // void reduce is called to store the fraction in reduced form
            Rational result( n, d );
            result.reduce();
            return result;
        }

        // divide two fractions
        Rational operator/( const Rational& rhs ) const{
            int n = numerator * rhs.denominator;
            int d = denominator * rhs.numerator;
            // void reduce is called to store the fraction in reduced form
            Rational result( n, d );
            result.reduce();
            return result;
        }

        // print Rational numbers in float format
        void floatPrint(){
            cout << (float)numerator / denominator << endl;
        }

        // print Rational numbers in fraction format
        void print() const{
            // reduce the fraction to its reduced form before printing
            Rational result( numerator, denominator );
            result.reduce();
            cout << result.numerator << "/" << result.denominator << endl;
        }
};

int main(){
    Rational r1( 15, 25 );
    cout << "r1 fraction format: "; r1.print();
    cout << "r1 float format: "; r1.floatPrint();
    Rational r2( 6, 18 );
    cout << "r2 fraction format: "; r2.print();
    cout << "r2 float format: "; r2.floatPrint();
    Rational r3 = r1 + r2;
    cout << "r1 + r2 fraction format: "; r3.print();
    cout << "r1 + r2 float format: "; r3.floatPrint();
    Rational r4 = r1 - r2;
    cout << "r1 - r2 fraction format: "; r4.print();
    cout << "r1 - r2 float format: "; r4.floatPrint();
    Rational r5 = r1 * r2;
    cout << "r1 * r2 fraction format: "; r5.print();
    cout << "r1 * r2 float format: "; r5.floatPrint();
    Rational r6 = r1 / r2;
    cout << "r1 / r2 fraction format: "; r6.print();
    cout << "r1 / r2 float format: "; r6.floatPrint();

    return 0;
}

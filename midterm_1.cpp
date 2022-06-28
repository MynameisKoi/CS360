#include <iostream>
#include <string>
using namespace std;

class Money{
  private:
    long double mny;
  public:
    Money();
        Money(char const s[]);
    void mstold(char const s[]);
    void ldtoms();
    void madd(Money m1, Money m2);
    void getmoney();
    void putmoney();
};

// Constructor
Money::Money(){
  mny = 0;
}

Money::Money(char const s[]){
    mstold(s);
}

// Use the function mstold() to convert a money string entered as input into a long double
void Money::mstold(char const s[]){
    mny = stold(s);
}

// Use the function ldtoms() to convert a long double into a money string for display
string ldtoms (long double x){
    string s = to_string(x);
    return s;
}

// Use the function getmoney() to get a money string from the user
void Money::getmoney(){
  char s[100];
  cout << "Enter a money string: ";
  cin >> s;
  mny = atof(s);
}

// Use the function putmoney() to display a money string to the user
void Money::putmoney(){
  cout << mny << endl;
}

// Use the function madd() to add two money strings
void Money::madd(Money m1, Money m2){
  mny = m1.mny + m2.mny;
}

int main(){
    Money m1, m2, m3;
    m1.getmoney();
    m2.getmoney();
    m3.madd(m1, m2);
    cout << "The sum of m1 and m2 is: "; m3.putmoney();

    Money m4("123.45");
    cout << "The money string m4 is: "; m4.putmoney();

    return 0;
}


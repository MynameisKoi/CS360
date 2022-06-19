#include <iostream>
#include <iomanip>
using namespace std;

//create a SavingsAccount class
class SavingsAccount{
    private:
        double savingsBalance;
        static double annual_InterestRate;

    public:
    //default constructor
    SavingsAccount(double a){
        savingsBalance = a;
    }

    // function calculateMonthlyInterest()
    float calculateMonthlyInterest(){
        double monthlyInterest = savingsBalance * (annual_InterestRate / 12);
        return savingsBalance += monthlyInterest;
    }

    // static function modifyInterestRate()
    static void modifyInterestRate(double new_interest_rate){
        annual_InterestRate = new_interest_rate;
    }

    // function print()
    void print(){
        cout << fixed << setprecision(3) << savingsBalance << endl;
    }
};

//Initialize static variable annual_InterestRate
double SavingsAccount::annual_InterestRate = 0.0;

int main(){
    //create a SavingsAccount object
    SavingsAccount saver1(2000);
    SavingsAccount saver2(3000);

    //set annual interest rate to 3%
    cout << "Annual interest rate is modified to 3%." << endl;
    saver1.modifyInterestRate(0.03);
    saver2.modifyInterestRate(0.03);

    //calculate the monthly interest and print the new balance
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();
    cout << "Saver 1 new balance: "; saver1.print();
    cout << "Saver 2 new balance: "; saver2.print();

    //set the annual interest rate to 4%
    cout << "Annual interest rate is modified to 4%." << endl;
    saver1.modifyInterestRate(0.04);
    saver2.modifyInterestRate(0.04);

    //calculate the monthly interest and print the new balance
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();
    cout << "Saver 1 new balance: "; saver1.print();
    cout << "Saver 2 new balance: "; saver2.print();

    return 0;
}

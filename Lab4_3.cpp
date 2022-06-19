  #include <iostream>
using namespace std;

// class HugeInteger that uses a 40-element array of digits to store integers as large as 40 digits each
class HugeInteger{
    private:
        int digits[40];

    public:
        // default constructor
        HugeInteger(){
            for(int i = 0; i < 40; i++){
                digits[i] = 0;
            }
        }
        // input function
        void input(){
            string n;
            cin >> n;
            for(int i = 0; i < n.length() ; i++){
                int a = stoi(n.substr((n.length()-1-i), 1));
                digits[i] = a;
            }
        }

        // output function
        void output(){
            for(int i = 39; i >= 0; i--){
                // pass zero located to the left of the first non-zero digit
                if(digits[i] != 0){
                    for(int j = i; j >= 0; j--){
                        cout << digits[j];
                    }
                    break;
                }
                if(digits[i] == 0 && i == 0){
                    cout << 0;
                }
            }
            cout << endl;
        }

        // add two HugeIntegers
        HugeInteger operator+( const HugeInteger& rhs ) const{
            HugeInteger result;
            int carry = 0;
            for(int i = 0; i < 40; i++){
                result.digits[i] = digits[i] + rhs.digits[i] + carry;
                if(result.digits[i] >= 10){
                    result.digits[i] -= 10;
                    carry = 1;
                }
                else{
                    carry = 0;
                }
            }
            return result;
        }

        // subtract two HugeIntegers
        HugeInteger operator-( const HugeInteger& rhs ) const{
            HugeInteger result;
            if ((*this).isLessThan(rhs)){
                cout << "Error: cannot subtract a larger number from a smaller number" << endl;
                cout << "The function will take the absolute value of the difference" << endl;
                result = rhs - *this;
                return result;
            }
            int carry = 0;
            for(int i = 0; i < 40; i++){
                result.digits[i] = digits[i] - rhs.digits[i] - carry;
                if(result.digits[i] < 0){
                    result.digits[i] += 10;
                    carry = 1;
                }
                else{
                    carry = 0;
                }
            }
            return result;
        }

        // multiply two HugeIntegers
        HugeInteger operator*( const HugeInteger& rhs ) const{
            HugeInteger result;
            for(int i = 0; i < 40; i++){
                for(int j = 0; j < 40; j++){
                    result.digits[i + j] += digits[i] * rhs.digits[j];
                    if(result.digits[i + j] >= 10){
                        int carry = result.digits[i + j] / 10;
                        result.digits[i + j] %= 10;
                        result.digits[i + j + 1] += carry;
                    }
                }
            }
            return result;
        }

        // divide two HugeIntegers
        HugeInteger operator/( const HugeInteger& rhs ) const{
            HugeInteger result;
            if((*this).isLessThan(rhs)){
                result.digits[0] = 0;
            }
            if((*this).isEqualTo(rhs)){
                result.digits[0] = 1;
            }
            HugeInteger temp = *this;
            HugeInteger temp2 = rhs;
            int i = 0;
            while(temp.isGreaterThanOrEqualTo(temp2)){
                temp = temp - temp2;
                i++;
            }
            result.digits[0] = i;
            for (int j = 0; j < 40; j++){
                if (result.digits[j] > 10) {
                    result.digits[j + 1] += result.digits[j] / 10;
                    result.digits[j] %= 10;
                }
            }
            return result;
        }

        // modulus function
        HugeInteger operator%( const HugeInteger& rhs) const{
            HugeInteger temp = *this;
            HugeInteger temp2 = rhs;
            if (temp.isLessThan(temp2)){
                return temp;
            }
            if (temp.isEqualTo(temp2)){
                HugeInteger result;
                result.digits[0] = 0;
                return result;
            }
            else {
                while(temp.isGreaterThanOrEqualTo(temp2)){
                    temp = temp - temp2;
                    }
                return temp;
                }
        }

        // isEqualTo function
        bool isEqualTo( const HugeInteger& rhs ) const{
            for(int i = 0; i < 40; i++){
                if(digits[i] != rhs.digits[i]){
                    return false;
                }
            }
            return true;
        }

        // isNotEqualTo function
        bool isNotEqualTo( const HugeInteger& rhs ) const{
            for(int i = 0; i < 40; i++){
                if(digits[i] != rhs.digits[i]){
                    return true;
                }
            }
            return false;
        }

        // isGreaterThan function
        bool isGreaterThan( const HugeInteger& rhs ) const{
            for(int i = 39; i >= 0; i--){
                if(digits[i] > rhs.digits[i]){
                    return true;
                }
                else if(digits[i] < rhs.digits[i]){
                    return false;
                }
            }
            return false;
        }

        // isLessThan function
        bool isLessThan( const HugeInteger& rhs ) const{
            for(int i = 39; i >= 0; i--){
                if(digits[i] < rhs.digits[i]){
                    return true;
                }
                else if(digits[i] > rhs.digits[i]){
                    return false;
                }
            }
            return false;
        }

        // isGreaterThanOrEqualTo function
        bool isGreaterThanOrEqualTo( const HugeInteger& rhs ) const{
            for(int i = 39; i >= 0; i--){
                if(digits[i] > rhs.digits[i]){
                    return true;
                }
                else if(digits[i] < rhs.digits[i]){
                    return false;
                }
            }
            return true;
        }

        // isLessThanOrEqualTo function
        bool isLessThanOrEqualTo( const HugeInteger& rhs ) const{
            for(int i = 39; i >= 0; i--){
                if(digits[i] < rhs.digits[i]){
                    return true;
                }
                else if(digits[i] > rhs.digits[i]){
                    return false;
                }
            }
            return true;
        }

        // isZero function
        bool isZero() const{
            for(int i = 0; i < 40; i++){
                if(digits[i] != 0){
                    return false;
                }
            }
            return true;
        }
};

int main(){
    HugeInteger a, b, c;
    cout << "Enter first number: "; a.input();
    cout << "Enter second number: "; b.input();
    cout << "Addition: "; c = a + b; c.output();
    cout << "Subtraction: "; c = a - b; c.output();
    cout << "Multiplication: "; c = a * b; c.output();
    cout << "Division: "; c = a / b; c.output();
    cout << "Modulus: "; c = a % b; c.output();
    cout << "isEqualTo: ";
    if(a.isEqualTo(b)){
        cout << "a is equal to b" << endl;
    }
    else{
        cout << "a is not equal to b" << endl;
    }

    cout << "isNotEqualTo: ";
    if(a.isNotEqualTo(b)){
        cout << "a is not equal to b" << endl;
    }
    else{
        cout << "a is equal to b" << endl;
    }

    cout << "isGreaterThan: ";
    if(a.isGreaterThan(b)){
        cout << "a is greater than b" << endl;
    }
    else{
        cout << "a is not greater than b" << endl;
    }

    cout << "isLessThan: ";
    if(a.isLessThan(b)){
        cout << "a is less than b" << endl;
    }
    else{
        cout << "a is not less than b" << endl;
    }

    cout << "isGreaterThanOrEqualTo: ";
    if(a.isGreaterThanOrEqualTo(b)){
        cout << "a is greater than or equal to b" << endl;
    }
    else{
        cout << "a is not greater than or equal to b" << endl;
    }

    cout << "isLessThanOrEqualTo: ";
    if(a.isLessThanOrEqualTo(b)){
        cout << "a is less than or equal to b" << endl;
    }
    else{
        cout << "a is not less than or equal to b" << endl;
    }

    cout << "isZero: ";
    if(a.isZero()){
        cout << "a is zero" << endl;
    }
    else{
        cout << "a is not zero" << endl;
    }

    return 0;
}

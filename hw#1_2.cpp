#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Matrix{
    private:
    int k = 0, row, column, count = 0;
    std::vector<int> digits;
    int s[20][20];
    char *input;

    public:
    Matrix(const string str){
        //Allocate string str to input
        input = new char[str.length()+1];
        assert(input != 0);
        const char* input = str.c_str();

        //Count row by counting the number of ")" in the string
        row = std::count(str.begin(), str.end(), ')');
        for (int i = 0; i < str.size(); i++) {
            //Check for digit numbers in the string
            if (isdigit(str[i])) {
                //Convert character type to int type
                int a = str[i] - '0';
                digits.push_back(a);
                count++;
                }
        }

        //Calculate the column to form a matrix
        column = count / row;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                s[i][j] = digits[k];
                k++;
            }
        }
    }

    //Destructor free the memory
    ~Matrix() {delete[] input;}

    int IsNaM(Matrix &mat2, int mat_case){
        if (mat_case == 1){
            if (((*this).column == mat2.column) && ((*this).row == mat2.row)){
                return true;
            }
            else {return false;}
        }

        if (mat_case == 2){
            if ((*this).column == mat2.row) {return true;}
            else {return false;}
        }
        return 0;
    }

    void add(Matrix &mat2){
        if ((*this).IsNaM(mat2,1) == true) {
            for (int i = 0; i < mat2.row; i++) {
                for (int j = 0; j < mat2.column; j++) {
                    cout << s[i][j] + mat2.s[i][j] << " ";
                }
                cout << endl;
            }
        }
        else {
            cout << "Invalid matrix size for operation 'add'! " << endl;
        }
    }

    void subtract(Matrix &mat2){
        if ((*this).IsNaM(mat2,1) == true) {
            for (int i = 0; i < mat2.row; i++) {
                for (int j = 0; j < mat2.column; j++) {
                    cout << s[i][j] - mat2.s[i][j] << " ";
                }
                cout << endl;
            }
        }
        else {
            cout << "Invalid matrix size for operation 'subtract'! " << endl;
        }
    }

    void multiply(Matrix &mat2){
        if ((*this).IsNaM(mat2,2) == true) {
            int i, j, k;
            int mult[20][20];

	        // Initializing elements of matrix mult to 0.
	        for(i = 0; i < (*this).row; ++i)
	        {
		        for(j = 0; j < mat2.column; ++j)
		        {
			        mult[i][j] = 0;
		        }
	        }

	        // Multiplying 2 matrices and storing in array mult.
	        for(i = 0; i < (*this).row; ++i)
	        {
		        for(j = 0; j < mat2.column; ++j)
		        {
			        for(k=0; k<(*this).column; ++k)
			        {
			    	    mult[i][j] += s[i][k] * mat2.s[k][j];
			        }
		        }
	        }

            //Print out the mult matrices
            for (int i = 0; i < (*this).row; i++) {
                for (int j = 0; j < mat2.column; j++) {
                    cout << mult[i][j] << " ";
                    }
                cout << endl;
            }
        }
        else {
            cout << "Invalid matrix size for operation 'subtract'! " << endl;
        }
    }

    // operator[] returns the element of the matrix
    int operator[](int i){
        int element[row*column];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                element[i*column+j] = s[i][j];
            }
        }
        return element[i];
    }

    void print(){
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cout << s[i][j] << " ";
                }
            cout << endl;
            }
    }
};


int main(){
    Matrix mat1("(1,2,3),(4,5,6),(7,8,9)");
    Matrix mat2("(9,8,7),(6,5,4),(3,2,1)");
    Matrix mat3("(4,9),(5,7),(6,3)");
    Matrix mat4("(2,5,8),(3,7,1)");
    // access the elements of the matrix
    cout << "mat1[2][3] = " << mat1[5] << endl;
    cout << "mat2[1][1] = " << mat2[0] << endl;
    cout << "mat3[3][2] = " << mat3[5] << endl;
    cout << "mat4[2][2] = " << mat4[4] << endl;
    cout << "Print matrix mat1: " << endl;
    mat1.print();
    cout << "Print matrix mat2: " << endl;
    mat2.print();
    cout << "Print matrix mat3: " << endl;
    mat3.print();
    cout << "Print matrix mat4: " << endl;
    mat4.print();
    cout << "mat1 + mat2: " << endl;
    mat1.add(mat2);
    cout << "mat3 + mat4: " << endl;
    mat3.add(mat4);
    cout << "mat1 - mat2: " << endl;
    mat1.subtract(mat2);
    cout << "mat1 * mat2: " << endl;
    mat1.multiply(mat2);
    cout << "mat3 * mat4: " << endl;
    mat3.multiply(mat4);

    return 0;
}

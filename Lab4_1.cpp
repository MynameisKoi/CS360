#include <iostream>
using namespace std;

class Example{
  public:
    Example( int y = 10 ): data( y ){
    // empty body
    } // end Example constructor
    int getIncrementedData(){
      return ++data;
    } // end function getIncrementedData
// Explanation: the function should not have 'const' because
// it has to modify the value of the variable 'data'

    int getCount(){
// Explanation: the function should be a non-static function instead of a static function
// Static functions can only access static variables, which cannot access the variable 'data'
// Non-static functions can access static variables and non-static variables
      cout << "Data is " << data << endl;
      return count;
    } // end function getCount
  private:
    int data;
    static int count;
}; // end class Example

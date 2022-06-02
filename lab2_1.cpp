#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
#define MAX 10
class Student {
  private:
    char name[30];
    int courseNum;
    int total;
    float perc;
  public:
    void getDetails(void); //member function to get student's details
    void putDetails(void); //member function to print student's details
};
void Student:: getDetails(void) //member function definition, outside of the class
{
  cout << "Enter name: " ;
  cin >> name;
  cout << "Enter course number: ";
  cin >> courseNum;
  cout << "Enter total grades out of 500: ";
  cin >> total;
  perc=(float)total/500*100;
}
void Student:: putDetails(void) //member function definition, outside of the class
{
  cout << "Student details:\n";
  cout << "Name: "<< name << ", course Number: " << courseNum <<
", Total: " << total << ", Percentage: " << std::setprecision(3) << perc;
}
 
int main(void){
  Student student[30];
  int n, i;
  cout << "Enter total number of students: ";
  cin >> n;
 
  for (i = 0; i < n; i++){
    cout << "Enter details of student " << i+1 << ":" << endl;
    student[i].getDetails();
    cout << endl;
  }
  cout << endl;
 
  for (i = 0; i < n; i++){
    cout << "Details of student " << i+1 << ":" << endl;
    student[i].putDetails();
    cout << endl;
  }
  return 0;
}

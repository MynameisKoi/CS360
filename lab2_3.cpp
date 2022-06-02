#include<iostream>
using std::cout;
using std::cin;
using std::endl;
class Rectangle{
  private:
float length, width, a, p;
 
  public:
void setlength(float){
cout << "Enter length: ";
cin >> length;
    }
void setwidth(float){
cout << "Enter width: ";
cin >> width;
    }
float perimeter(void){
p = (length + width) * 2;
return p;
    }
float area(void){
a = length * width;
return a;
    }
void show(void){
cout << "Length of the rectangle: " << length << endl;
cout << "Width of the rectangle: " << width << endl;
    }
int sameArea(Rectangle r1, Rectangle r2){
    if (r1.a = r2.a){
        return 1;
    }
    else {return 0;}
}
};
 
int main(void){
  Rectangle r1, r2;
  r1.setlength(5);
  r1.setwidth(2.5);
  cout << "Perimeter: " << r1.perimeter() << endl;
  cout << "Area: " << r1.area() << endl;
  r2.setlength(5);
  r2.setwidth(18.9);
  cout << "Perimeter: " << r2.perimeter() << endl;
  cout << "Area: " << r2.area() << endl;
 
  cout << "Output for 'sameArea' function: " << r1.sameArea(r1,r2) << endl;
  r1.setlength(15);
  r1.setwidth(6.3);
  cout << "Output for 'sameArea' function: " << r1.sameArea(r1,r2) << endl;
  return 0;
}

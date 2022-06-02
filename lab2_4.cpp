#include<iostream>
#include<list>
using std::cout;
using std::cin;
using std::endl;
using std::string;
 
class MusicIns {
  private:
string string_inst[5], wind_inst[5], perc_inst[5];
int n;
 
  public:
void string_ins(void){
string_inst[0] = "veena";
string_inst[1] = "guitar";
string_inst[2] = "sitar";
string_inst[3] = "sarod";
string_inst[4] = "mandolin";
    }
void wind_ins(void){
wind_inst[0] = "flute";
wind_inst[1] = "clarinet";
wind_inst[2] = "saxophone";
wind_inst[3] = "nadaswaram";
wind_inst[4] = "piccolo";
    }
void perc_ins(void){
perc_inst[0] = "table";
perc_inst[1] = "mridangam";
perc_inst[2] = "bongos";
perc_inst[3] = "drums";
perc_inst[4] = "tambour";
    }
void show(void)
{
    if (n == 1) {for (int i = 0; i < 5; i++) {cout << string_inst[i] << ", ";}}
    if (n == 2) {for (int i = 0; i < 5; i++) {cout << wind_inst[i] << ", ";}}
    if (n == 3) {for (int i = 0; i < 5; i++) {cout << perc_inst[i] << ", ";}}
    }
void get(void){
cout << "1) String instrument" << endl;
cout << "2) Wind instrument" << endl;
cout << "3) Perc instrument" << endl;
cout << "Choose a number: ";
cin >> n;
cout << "Instrument array: ";
return show();
}
};
 
int main(void){
    MusicIns ins;
    ins.string_ins();
    ins.wind_ins();
    ins.perc_ins();
    ins.get();
}
 

#include <iostream>
using namespace std;

class Smith{
    private:
    int m_wife;

    protected:
    int m_home;

    public:
    int name;

    // default constructor
    Smith(): m_wife(3), m_home(2), name(1){}

    friend class Friend_Smith;
    friend class Son_friend_Smith;
};

// class Son_Smith, inherited from Smith
class Son_Smith: public Smith{
    private:
    int flag;

    public:
    // default constructor
    Son_Smith(): Smith(){
        flag = 4;
    }
};

//friend class of Smith, named Friend_Smith
class Friend_Smith{
    public:
    void help(const Smith& sm){
        cout << "Name: " << sm.name << endl;
        cout << "Home: " << sm.m_home << endl;
        cout << "Wife: " << sm.m_wife << endl;
        cout << endl;
    }
};

//class Son_friend_Smith, inherited from Friend_Smith
class Son_friend_Smith: public Friend_Smith{
    public:
    void help(const Smith& uncle_smith){
        cout << "Name: " << uncle_smith.name << endl;
        cout << "Home: " << uncle_smith.m_home << endl;
        cout << "Wife: " << uncle_smith.m_wife << endl;
        cout << endl;
    }

    //call the help function of Friend_Smith passing uncle_smith as its argument
    void sfsm_help(const Smith& uncle_smith){
        Friend_Smith::help(uncle_smith);
    }
};

//Verify all help functions in the classes
int main(){
    Smith sm;
    Son_Smith son_sm;
    Friend_Smith f_sm;
    cout << "Help functions in Friend_Smith" << endl;
    f_sm.help(sm);
    Son_friend_Smith sf_sm;
    cout << "Help functions in Son_friend_Smith" << endl;
    sf_sm.help(sm);
    cout << "Call the help function of Friend_Smith in Son_friend_Smith" << endl;
    sf_sm.sfsm_help(sm);
    cout << "Help functions in Friend_Smith with Son_Smith object argument" << endl;
    f_sm.help(son_sm);

    return 0;
}

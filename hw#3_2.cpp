#include <iostream>
#include <iomanip>
#include "IntegerSet.h"

using namespace std;

IntegerSet::IntegerSet()
{
    for (int i = 0; i < max; i++)
    {
        arr[i] = false;
    }
}

IntegerSet::IntegerSet(int array[], int size)
{
    for (int i = 0; i < max; i++)
    {
        arr[i] = false;
    }
    for (int i = 0; i < size; i++)
    {
        arr[array[i]] = true;
    }
}

IntegerSet IntegerSet::unionOfSets(IntegerSet other)
{
    IntegerSet result;
    for (int i = 0; i < max; i++)
    {
        if (this->arr[i] || other.arr[i])
        {
            result.arr[i] = true;
        }
    }
    return result;
}

IntegerSet IntegerSet::intersectionOfSets(IntegerSet other)
{
    IntegerSet result;
    for (int i = 0; i < max; i++)
    {
        if (this->arr[i] && other.arr[i])
        {
            result.arr[i] = true;
        }
    }
    return result;
}

void IntegerSet::insertElement(int k)
{
    arr[k] = true;
}

void IntegerSet::deleteElement(int k)
{
    arr[k] = false;
}

void IntegerSet::printSet()
{
    int count = 0;
    for (int i = 0; i < max; i++)
    {
        if (arr[i] == true)
        {
            cout << i << " ";
        }
        else
        {
            count += 1;
        }
    }
    if (count == max)
    {
        cout << "None";
    }
    cout << endl;
}

bool IntegerSet::isEqualTo(IntegerSet other)
{
    for (int i = 0; i < max; i++)
    {
        if (this->arr[i] != other.arr[i])
        {
            return false;
        }
    }
    return true;
}

int main(){
    IntegerSet set1;
    IntegerSet set2;
    int array1[10] = {29, 14, 10, 8, 15, 20, 12, 18, 19, 21};
    IntegerSet set3(array1, 10);
    IntegerSet set4(array1, 10);
    int array3[5] = {3, 8, 7, 10, 12};
    IntegerSet set5(array3, 5);

    set1.insertElement(29);
    set1.insertElement(10);
    set1.insertElement(12);
    set1.insertElement(18);
    cout << "Set 1: ";
    set1.printSet();

    set2.insertElement(1);
    set2.insertElement(2);
    set2.insertElement(3);
    set2.insertElement(4);
    set2.insertElement(5);
    cout << "Set 2: ";
    set2.printSet();
    set2.deleteElement(3);
    set2.deleteElement(5);
    cout << "Set 2 after deletion: ";
    set2.printSet();

    cout << "Set 3: ";
    set3.printSet();
    cout << "Set 4: ";
    set4.printSet();
    cout << "Set 5: ";
    set5.printSet();

    cout << "Set 1 union Set 4: ";
    set1.unionOfSets(set4).printSet();
    cout << "Set 1 intersection Set 4: ";
    set1.intersectionOfSets(set4).printSet();

    cout << "Set 2 union Set 1: ";
    set2.unionOfSets(set1).printSet();
    cout << "Set 2 intersection Set 1: ";
    set2.intersectionOfSets(set1).printSet();

    cout << "Set 2 union Set 5: ";
    set2.unionOfSets(set5).printSet();
    cout << "Set 2 intersection Set 5: ";
    set2.intersectionOfSets(set5).printSet();

    cout << "Set 3 equal to Set 4: ";
    if (set3.isEqualTo(set4))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    cout << "Set 3 equal to Set 5: ";
    if (set3.isEqualTo(set5))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    cout << "Set 4 equal to Set 5: " ;
    if (set4.isEqualTo(set5))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}

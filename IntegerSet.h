// IntegerSet.h
// IntegerSet class definition.

#ifndef INTEGERSET_H
#define INTEGERSET_H

class IntegerSet{
    private:
        const int max = 100;
        bool arr[100];
    public:
        IntegerSet(); // default constructor
        IntegerSet(int array[], int size); // constructor with array of integers
        IntegerSet unionOfSets(IntegerSet other); // union of two sets
        IntegerSet intersectionOfSets(IntegerSet other); // intersection of two sets
        void insertElement(int k);
        void deleteElement(int k);
        void printSet();
        bool isEqualTo(IntegerSet other);
};

#endif // INTEGERSET_H

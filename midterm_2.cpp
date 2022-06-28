#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// define a function template interpolSearch() that looks up a given element in a sorted numeric array. This array elements are of the same type as the template parameter T
// the function template has three parameters - the value searched for of type T, a pointer to the first array element, and the number of array elements

template <typename T>
int interpolSearch(T arr[], int n, T key){
    // sort the array elements by number
    sort(arr, arr + n);
    cout << "Array after sorting: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    // find the index of the element we are looking for
    int low = 0;
    int high = n - 1;
    while (low <= high){
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main(){
    // create a random array of integers
    int size = 20;
    int arr[size];
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 10;
    // print the array of integers
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    // verify interpolSearch()
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    int index = interpolSearch(arr, n, key);
    if (index == -1)
        cout << "Element not found" << endl;
    else
        cout << "Element found at index " << index << endl;
    return 0;
}

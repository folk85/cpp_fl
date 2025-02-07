/*
3. Function Pointer for Custom Operations on Arrays

   Write a program that:
   - Defines three functions `add`, `multiply`, and `subtract` that operate on two integers.
   - Uses a function pointer to apply a selected operation (e.g., `addition`, 
   `multiplication`, `subtraction`) to every element of two arrays of integers.
   - Create a function `void applyOperation(int arr1[], int arr2[], int result[], int n, int (op)(int, int))` 
   that takes the two arrays, a result array, the number of elements, and a function pointer op to 
   apply the selected operation to corresponding elements in the arrays.
*/
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>
#include "doctest.h"
#include <algorithm>
#include <iterator>
#include <functional>
#include <iostream>
using namespace std;


void printVector(vector<int> &arr) {
    copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}
int add(const int a, const int b) {
    return (a + b);
}

int multiply(const int a, const int b) {
    return (a * b);
}

int subtract(const int a, const int b) {
    return (a - b);
}

void applyOperation(int arr1[], int arr2[], int result[], int n, int (*func)(int, int)) {
// void applyOperation(int arr1[], int arr2[], int result[], int n, function <int (int, int)> func) {
    for (auto i=0; i<n; i++) {
        result[i] = func(arr1[i], arr2[i]);
    }
}


TEST_CASE("mergeSort"){
    vector<int> arr1 {1, 2, 3, 4, 5};
    vector<int> arr2 {5, 4, 3, 2, 1};
    vector<int> res(arr1.size());
    for (auto &x: res) {
        x = 0;
    }

    // applyOperation( arr1.data(), arr2.data(), res.data(), arr1.size(), add);
    applyOperation( &arr1[0], &arr2[0], &res[0], arr1.size(), &add);
    printVector(res); 

    applyOperation( &arr1[0], &arr2[0], &res[0], arr1.size(), &multiply);
    printVector(res); 

    applyOperation( &arr1[0], &arr2[0], &res[0], arr1.size(), &subtract);
    printVector(res); 
}
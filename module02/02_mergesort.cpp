/*
2. Merge Sort with Recursion and Pass by Reference

   Write a recursive function `void mergeSort(vector<int> &arr, int left, int right)` that:
   - Takes a vector of integers by reference.
   - Sorts the array using the Merge Sort algorithm.
   - Write a helper function `void merge(vector<int> &arr, int left, int mid, int right)` to merge two halves of the array.
   - Ensure that the array is passed by reference to avoid copying data.
*/
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>
#include "doctest.h"
#include <algorithm>
#include <iterator>

#include <iostream>
using namespace std;


void printVector(vector<int> &arr) {
    copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void merge(vector<int> &arr, int left, int mid, int right) {
    // int lnel = mid - left + 1;
    // int lnel = mid ;
    // int rnel = right;

    int i = left; 
    int j = mid;
    int k = left;
    // cout << i << j<< k << " " << left << " " << mid << " " << right << " indices" << endl;
    while (i < mid && j < right) {
        // cout << i<<j<<k<<"   "<<arr[i]<<"   "<<arr[j]<<"   "<<arr[k] << " before" <<endl;
        if (arr[i] <= arr[j]) {
            swap( arr[k], arr[i]);
            i++;
        } else {
            j++;
            swap( arr[k], arr[j]);
        }
        k++;
        // cout << i<<j<<k<<"   "<<arr[i]<<"   "<<arr[j]<<"   "<<arr[k] << " after while " <<endl;
    }
    while (i < mid) {
        swap( arr[k], arr[i]);
        i++;
        k++;
    }
    while (j < right) {
        j++;
        swap( arr[k], arr[j]);
        k++;
    }
    // cout << i<<j<<k<<"   "<<arr[i]<<"   "<<arr[j]<<"   "<<arr[k] << " after all w " <<endl;
    printVector(arr);
}


void mergeSort(vector<int> &arr, int left, int right) {

    if (left < right) {
        int mid = left + (right - left) / 2; 
        mergeSort( arr, left, mid);
        mergeSort( arr, mid+1, right);
        merge(arr, left, mid, right);
    }

    // printVector(arr);
}


TEST_CASE("mergeSort"){
    vector<int> vector_uns {2, 1, 3 , 7, 4};
    auto vector_str = vector_uns; 
    sort(vector_str.begin(), vector_str.end());

    // printVector(vector_uns); 
    mergeSort(vector_uns, 0, vector_uns.size() - 1);
    // mergeSort(vector_uns, 0, 1);
    printVector(vector_uns); 
    printVector(vector_str); 



}
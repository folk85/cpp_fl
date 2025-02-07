/*
4. Generate All Subsets (Power Set) using Recursion and Lambda

   Write a recursive function `void generateSubsets(vector<int> &set, vector<int> &current, int index, const function<void(const vector<int>&)> &callback)` that:
   - Generates all possible subsets (power set) of a given set of integers.
   - Uses a lambda function as a callback to process each subset (e.g., print, store).
   - Demonstrates the use of the lambda to print each subset to the console as it's generated.
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

/// @brief accumulate power set
/// @param arr input array of digits, use values in range [0, 9]
/// @return number
int digit2num(vector<int> &arr) {
    int result = arr.back() % 10;
    for (int i=arr.size() - 2; i>=0; i--) {
        // cout << i << "   " << ( arr[i] % 10) << endl;
        result = 10 * result + ( arr[i] % 10);
    }
    return result;
}

void generateSubsets(vector<int> &set, vector<int> &current, int index, const function<void(const vector<int>&)> &callback) {
    if (index == current.size()) {
        auto cur_val = digit2num(current);
        if( find(set.begin(), set.end(), cur_val) == set.end() ) {
            set.push_back(cur_val);
            callback(current);
        }
        return;
    }

    for (size_t i=index; i < current.size(); i++) {

        swap(current[index], current[i]);
        // printf("tmp: %d %s \n",cnt,  arr.c_str());

        generateSubsets(set, current, index + 1, callback);

        swap(current[index], current[i]);
    }
}

TEST_CASE("set Subset"){
    vector<int> arrin {1, 2, 3};
    vector<int> arrset ;
    const function<void (vector<int>&)> fprint = printVector;
    generateSubsets(arrset, arrin, 0, fprint);

    // printVector(arrset);

    // applyOperation( arr1.data(), arr2.data(), res.data(), arr1.size(), add);
}
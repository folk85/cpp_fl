/*
6. Rotate Array
   Write a program that:
   - Takes an integer n and an array of n integers as input.
   - Asks the user for an integer k (number of positions to rotate).
   - Rotates the array to the right by k positions (without using an additional array).
   - Example: For array [1, 2, 3, 4, 5] and k = 2, the result should be [4, 5, 1, 2, 3].

*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


void rotate_arr(std::vector<int>& arr, int krot) {

    if (krot < 0) {
        std::rotate(arr.begin(), arr.begin() - krot, arr.end());
    }else if (krot > 0) {
        std::rotate(arr.rbegin(), arr.rbegin() + krot, arr.rend());
    }
}


int main() {
    std::vector<int> sval;
    int nel;
    int ival;

    std::cin >> nel;

    for (auto i=0; i< nel; i++) {
        std::cin >> ival;
        sval.push_back(ival);
    }
    int krot;
    std::cin >> krot;

    rotate_arr(sval, krot);
    for (auto s: sval) {
        printf("%d ", s);
    }

}
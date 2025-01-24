/*
4. Find Second Largest Element
   Write a program that:
   - Takes an integer n as input, followed by n integers to store in an array.
   - Finds the second largest element in the array without sorting it.
   - Handles cases where all elements are the same or there are fewer than two distinct elements.

*/

#include <climits>
#include <vector>
#include <iostream>

int second_largest(std::vector<int> arr) {

    int max1 = INT_MIN;
    int max2 = INT_MIN;
    if (arr.size() < 2) {
        max2 = arr[0];
    }
    for (auto i: arr) {
        if (i > max1) {
            max2 = max1;
            max1 = i;
        }
    }
    if (max2 == INT_MIN) {
        max2 = max1;
    }
    return max2;
}
int main() {
    std::vector<int> arr;

    int nel;
    int ival;

    std::cin >> nel;
    for (auto i=0; i< nel; i++) {
        std::cin >> ival;
        arr.push_back(ival);
    }

    auto res = second_largest(arr);
    printf("Second Largest number: %d\n", res);

}
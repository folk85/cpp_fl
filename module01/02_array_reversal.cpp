/*
2. Array Reversal
   Write a program that:
   - Takes an integer n as input, followed by n integers to store in an array.
   - Reverses the array in place (without using an additional array).
   - Prints the reversed array.

*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

void print_reversed(std::vector<int> arr) {
    int nel = arr.size();
    for (auto i=1; i <= nel; i++) {
        printf("%d ", arr[nel - i]);
    }
        printf("\n");
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

    print_reversed(arr);

}
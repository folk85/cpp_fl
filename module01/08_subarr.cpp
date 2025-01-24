/*
8. Subarray with Maximum Sum
   Write a program that:
   - Takes an integer n as input, followed by n integers to store in an array.
   - Implements an algorithm to find the subarray with the maximum sum.
   - For example, for the array [-2, 1, -3, 4, -1, 2, 1, -5, 4], the output should be 6 (subarray [4, -1, 2, 1]).

*/

#include <climits>
#include <vector>
#include <functional>
#include <iostream>
#include <numeric>

int max_subarr(std::vector<int> arr) {

    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int nel = arr.size();
    for (auto i=1; i < nel; i++) {
        auto sum_sub = std::accumulate(arr.begin(), arr.begin()+i, 0);
        int delta = 0;
        for (auto j=0;j<nel-i; j++) {
            if (j>0) {
                delta = arr[i + j] - arr[j];
            }
            sum_sub += delta;
            if (max1 < sum_sub) {
                max1 = sum_sub;
            }
        }
    }
    if (nel < 1) {
        max1 = 0;
        
    } else if (nel == 1) {
        max1 = arr[0];
    }
    return max1;
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

    auto res = max_subarr(arr);
    printf("Max number of subarray: %d\n", res);

}
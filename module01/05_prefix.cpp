/*
5. Longest Common Prefix
   Write a program that:
   - Takes n strings as input (stored in an array of strings).
   - Finds and prints the longest common prefix among all the strings.
   - For example, for {"flower", "flow", "flight"}, the output should be "fl".
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


std::string prefix(std::vector<std::string>& arr) {

    auto pref = arr[0];
    auto nel = pref.size();
    for (auto i=1; i < arr.size(); i++) {
        // printf("%s \n", s.c_str());
        for (auto j=0; j< nel; j++) {
            if (pref[j]!=arr[i][j]) {
                nel = j;
                break;
            }
        }
    }
    return pref.substr(0,nel);

}


int main() {
    std::vector<std::string> sval;
    int nel;
    std::string ival;

    std::cin >> nel;
    for (auto i=0; i< nel; i++) {
        std::cin >> ival;
        sval.push_back(ival);
    }

    auto res = prefix(sval);
    printf("%s ", res.c_str());

}
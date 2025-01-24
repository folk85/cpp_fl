/*
7. Anagram Checker
   Write a program that:
   - Takes two strings as input.
   - Checks whether the two strings are anagrams (contain the same characters in any order).
   - Ignores case and non-letter characters.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>

bool check_anagram(std::vector<std::string>& arr) {

    std::string chk_arr;
    bool res = true;
    for (auto i=0;i<arr.size(); i++) {
        std::string tmp;
        for (auto s: arr[i]) {
            if (std::isalpha(s)){
                tmp.push_back(std::tolower(s));
            }
        }
        std::sort(tmp.begin(), tmp.end());
        if (i == 0) {
            chk_arr = tmp;
        } else {
            if (chk_arr == tmp) {
                res &= true;
            } else {
                res &= false;
            }
        }
    }
    return res;
}

int main() {

    std::vector<std::string> arr;

    std::string line;

    std::getline(std::cin, line);
    std::istringstream stream(line);
    std::string ival;
    while (stream >> ival)
        arr.push_back(ival);

    auto res = check_anagram(arr); 

    if (res) {
        printf("The words are anagrams\n");
    }else{
        printf("The words are NOT anagrams\n");
    }
}
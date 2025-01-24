#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>

void get_unique(std::vector<int> arr) {

    int i = 1;
    while (i < arr.size()) {
        if (arr[i] == arr[i-1]) {
            arr.erase(arr.begin() + i - 1 );
        } else {
            i += 1;
        }
    }

    printf("Length of array with unique values is: %d \n", arr.size());
    for (auto ival : arr) {
        printf("%d ",ival);
    }
    printf("\n");


}

int main() {

    std::vector<int> arr;

    std::string line;

    std::getline(std::cin, line);
    std::istringstream stream(line);
    int ival;
    while (stream >> ival)
        arr.push_back(ival);

    get_unique(arr); 

}
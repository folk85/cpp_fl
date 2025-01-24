/*
3. String Compression
   Write a program that:
   - Takes a string as input.
   - Compresses the string by replacing consecutive occurrences of 
   the same character with the character followed by the number of 
   repetitions (e.g., "aaabbcc" becomes "a3b2c2").

*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

void print_compressed(std::string arr) {
    int nel = arr.size();
    int j = 1;
    auto sold = arr[0];

    for (auto i=0; i < nel; i++) {
            // printf("Test %s \n", arr[i]);
        if (i == 0) {
            // printf("%s", arr[i]);
            std::cout << arr[i];
        } else if (arr[i] == sold) {
            j += 1;
        } else {
            // printf("%d%s",j, arr[i]);
            if (j > 1) {
                std::cout << j;
            }
            std::cout << arr[i];
            j = 1;
            sold = arr[i];
        }

    }
    if (j> 1) {
        std::cout << j;
    }
        printf("\n");
}
int main() {
    std::string arr;

    std::getline(std::cin, arr);

    print_compressed(arr);

}
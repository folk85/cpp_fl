#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

void permute_str(std::vector<std::string>& res, std::string arr, int cnt);
void permutation(std::string sinput);

void permute_str(std::vector<std::string>& res, std::string arr, int cnt) {
    if (cnt == arr.size()) {
        if( std::find(res.begin(), res.end(), arr) == res.end() ) {
            res.push_back(arr);
        }
        return;
    }

    for (size_t i=cnt; i < arr.size(); i++) {

        std::swap(arr[cnt], arr[i]);
        // printf("tmp: %d %s \n",cnt,  arr.c_str());

        permute_str(res, arr, cnt + 1);

        std::swap(arr[cnt], arr[i]);
    }
}

void permutation(std::string sinput) {
    std::vector<char> carr;
    for (auto s: sinput) {
        carr.push_back(s);
    }
    printf("Input: %s \n", sinput.c_str());
    std::vector<std::string> res;
    permute_str(res, sinput, 0); 

    printf("Number of unique words: %d\n", res.size());
    for (auto ival : res) {
        printf("%s ",ival.c_str());
    }
    printf("\n");


}

int main() {
    std::string sval;

    std::getline(std::cin, sval);

    permutation(sval);

}
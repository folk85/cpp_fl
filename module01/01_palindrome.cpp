#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <string>

bool is_palindrome(std::string txt) {
    std::string txt1;
    // clean the input string, use only alphabetical or numerics.
    // and set to lower 
    for (auto s: txt) {
        if (std::isalpha(s) || std::isdigit(s)) {
            txt1 += std::tolower(s);
        }
    }
    // get reverse string
    std::string rev = txt1;
    std::reverse(rev.begin(), rev.end());
    //return the comparison
    return rev == txt1;
}


TEST_CASE("testing the palindrome function") {
    CHECK(is_palindrome("radar") == true);
    CHECK(is_palindrome("Radar") == true);
    CHECK(is_palindrome("") == true);
    CHECK(is_palindrome("a") == true);
    CHECK(is_palindrome("aBcsa") == false);
    CHECK(is_palindrome("race car") == true);
    CHECK(is_palindrome("A man, a plan, a canal: Panama!") == true);
    CHECK(is_palindrome("Was it a car or a cat I saw?") == true);
    CHECK(is_palindrome("hello world") == false);
    // CHECK(is_palindrome("a" * 100000 + "b" + "a" * 100000) == true);
    CHECK(is_palindrome("^&*( No lemon, no melon!!!@#$%)") == true);
}
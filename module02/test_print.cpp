#ifdef __has_include
   #if __has_include(<format>)
      #include <format>
   #else
      #warning "The <format> library is not available."
   #endif
   #if __has_include(<print>)
      #include <print>
   #else
      #warning "The <print> library is not available."
   #endif
#else
   #warning "The __has_include check is not available."
#endif

#include <iostream>

int main() {
#ifdef __cpp_lib_print
  std::print("{} {} {}", 'Hello', "World", '!');
#else 
  std::cout << "it's not implemented yet" << std::endl;
#endif
    return 0;
}
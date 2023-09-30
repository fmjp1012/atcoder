#include <iostream>

// This code can determine whether the compiler is based on GCC or Clang.
// Also, <command> --version can be used to determine the compiler.

int main() {
    #ifdef __clang__
        std::cout << "This is compiled with Clang" << std::endl;
    #elif defined(__GNUC__)
        std::cout << "This is compiled with GCC" << std::endl;
    #else
        std::cout << "This is compiled with an unknown compiler" << std::endl;
    #endif
    return 0;
}

#include "myvector.h"
#include <iostream>

int main() {
    myvector<int> test={1,2,3};

    std::cout << test.len();
    for (int i{0}; i<test.len(); i++)
        std::cout << test.at(i);
    
    return 0;
}
#include "string.hpp"
#include <iostream>

int main() {
    String obj;

    obj.push_back('a');
    obj.push_back('a');
    obj.push_back('a');
    obj.push_back('a');
    
    std::cout << obj;

    return 0;
}
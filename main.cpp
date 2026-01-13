#include <iostream>
#include "string.h"

int main() {
    String s1 = "Hello";
    std::cout << s1 << std::endl;
    std::cout << s1.get_size() << std::endl;
    String s2 = " World";
    std::cout << s2.get_size() << std::endl;
    s1 += s2;
    std::cout << s1 << std::endl;
    std::cout << s1.get_size() << std::endl;

    String s4 = "Te";
    String s5 = "st!";
    String s6 = s4 + s5;
    std::cout << s6 << std::endl;
    std::cout << s6.get_size() << std::endl;

    String s7 = "Hey";
    String s8 = "Hey";
    if (s7 == s8) {
        std::cout << "Equality between strings s7 & s8" << std::endl;
    }
    return 0;
}

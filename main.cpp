#include <iostream>
#include "MyString.h"

int main() {
    // Construction
    String a = "Hello";
    String b = "World";
    std::cout << "a: " << a << ", b: " << b << std::endl;

    // Copy constructor
    String c = a;
    std::cout << "c (copy of a): " << c << std::endl;

    // Move assignment
    String d = "Temp";
    d = std::move(b);
    std::cout << "d (moved from b): " << d << ", b: " << b << std::endl;

    // Operator +=
    a += d;
    std::cout << "a after a += d: " << a << std::endl;

    // Operator +
    String e = c + d;
    std::cout << "e (c + d): " << e << std::endl;

    // Operator[]
    std::cout << "a[0]: " << a[0] << ", last char: " << a[a.get_size()-2] << std::endl;

    // Equality
    String f = "HelloWorld";
    if (a == f) std::cout << "a equals f" << std::endl;

    // Size
    std::cout << "Size of e: " << e.get_size() << std::endl;

    return 0;
}

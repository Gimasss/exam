#include "bigint.hpp"
#include <iostream>

int main()
{
    const bigint a(42); //cannot be changed after constructin
    bigint b(21), c, d(1337), e(d);

    std::cout << bigint(42);

    std::ostream &x = std::cout << "x";
    x << "y";
    std::cout << std::endl;


    std::cout << "---standard big int---" << std::endl;
    std::cout << "a = " << a << std::endl;
    (std::cout << "b = ") << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;

    std::cout << "---addition---" << std::endl;
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "(c += a) = " << (c += a) << std::endl;

    //std::cout << "---increment---" << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "++b = " << ++b << std::endl;
    std::cout << "b++ = " << b++ << std::endl;

    std::cout << "---shift---" << std::endl;
    std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << std::endl;
    std::cout << "(d <<= 4) = " << (d <<= 4) << std::endl;
    std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << std::endl;

    std::cout << "---boh---" << std::endl;
    std::cout << "a =" << a << std::endl;
    std::cout << "d =" << d << std::endl;

    std::cout << "---comparison---" << std::endl;
    std::cout << "(d < a) = " << (d < a) << std::endl;
    std::cout << "(d <= a) = " << (d <= a) << std::endl;
    std::cout << "(d > a) = " << (d > a) << std::endl;
    std::cout << "(d >= a) = " << (d >= a) << std::endl;
    std::cout << "(d == a) = " << (d == a) << std::endl;
    std::cout << "(d != a) = " << (d != a) << std::endl;

}


//what is should d by looking at the main
//1. costruzione obj
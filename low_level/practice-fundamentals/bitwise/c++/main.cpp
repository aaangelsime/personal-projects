#include <iostream>
/*

g++ main.cpp -o main

./main

*/

int main (int argc, char* argv[])
{
    int x = 4; // 1 byte -> 0000 0100
    int y = 6; // 1 byte -> 0000 0110

    int a = x ^ y; // xor
    std::cout << "x xor y: " << a << std::endl;

    /*

    Truth Table

    x | y | a
    0 | 0 | 
    0 | 1 | 
    1 | 0 | 
    1 | 1 | 

    */

    int b = x & y; // and
    std:: cout << "x and y: " << b << std::endl;

    /*
    
    Truth Table

    x | y | a
    0 | 0 | 
    0 | 1 | 
    1 | 0 | 
    1 | 1 | 

    */

    int c = x | y; // or
    std:: cout << "x or y: " << c << std::endl;

    /*
    
    Truth Table

    x | y | a
    0 | 0 | 
    0 | 1 | 
    1 | 0 | 
    1 | 1 | 

    */

    return 0;
}
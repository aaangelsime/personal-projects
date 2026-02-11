#include <iostream>

void swap(int &x, int &y);

int main(int argc, char* argv[])
{
    int x = 10;
    int y = 5;

    swap(x, y);

    std::cout << "&x: " << &x << std::endl;
    std::cout << "&y; " << &y << std::endl;

    return 0;
}

void swap(int &x, int &y)
{
    std::cout << "&x: " << &x << std::endl;
    std::cout << "&y; " << &y << std::endl;
}
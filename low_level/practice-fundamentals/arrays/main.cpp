#include <iostream>
#include <array>

int main(int argc, char* argv[])
{
    std::array<int, 5> x{1, 2, 3, 4, 5};

    for (int i = 0; i < 5; ++i)
    {
        x[i] = i + 2;
        std::cout << x[i] << std::endl;
    }
    return 0;
}
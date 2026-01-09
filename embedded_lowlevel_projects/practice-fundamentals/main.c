#include <stdio.h>

int main()
{
    int x = 10;

    // \n = new line
    printf("Value of x: %d\n", x);
    printf("Memory Address of x: %p\n", (void *)&x);

    return 0;
}
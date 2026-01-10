#include <stdio.h>
/*
To run without makefile 
    gcc main.c -o myprogram
    ./myprogram
*/

int main(int argc, char **argv)
// argc = number of command line arguments
// argv = list of command-line arguments; more of an argument vecotr, or pointer to an array of char-string arguments
{
    int x = 10;
    int *p = &x; // p stores the address of x

    // format specifiers (%d, %s, %p, etc.)
    // \n = new line
    printf("Value of x: %d\n", x);
    printf("Address of x: %p\n", (void*)&x);
    printf("Value of *p: %d\n", *p);
    printf("Value of p: %p\n", (void*)p);


    
    return 0;
}
#include <stdio.h>
/*
To run without makefile 
    gcc main.c -o myprogram
    ./myprogram

To run with make file
make makerun
or 
make && make makerun
*/


int main(void)
// argc = number of command line arguments
// argv = list of command-line arguments; more of an argument vector, or pointer to an array of char-string arguments
{
    int x = 10;
    int *p = &x; // p stores the address of x

    // format specifier %vartype
    printf("x = %d\n", x); // value of x
    printf("x memory address = %p\n", (void*)&x); // address of x
    printf("*p = %d\n", *p); // value at address
    printf("p = %p\n", (void*)p); // address of x
    printf("&p = %p\n", (void*)&p); // address of pointer variable
    
    // Displays byte size of the three types of ints
    printf("size of a short is %d\n", sizeof(short));
    printf("size of a int is %d\n", sizeof(int));
    printf("size of a long is %d\n", sizeof(long));
    return 0;

}

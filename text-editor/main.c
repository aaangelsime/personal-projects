#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

//functions
void enable_raw_mode();
void disable_raw_mode();

//structs
struct termios orig_termios;

int main ()
{
    enable_raw_mode();
    char c;

    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q')
    {
        if(iscntrl(c))
        {
            printf("%d\n", c);
        }
        else 
        {
            printf("%d ('%c')\n", c, c);
        }
    }
    return 0;
}

//en fn
void enable_raw_mode()
{
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disable_raw_mode);

    struct termios raw = orig_termios;

    raw.c_lflag &= ~(ECHO | ICANON);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

//dis fn
void disable_raw_mode()
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}
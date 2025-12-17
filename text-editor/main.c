#include <unistd.h> // POSIX OS API (read, STDIN_FILENO)
#include <errno.h> // System error numbers
#include <termios.h> // Terminal I/O interface
#include <stdlib.h> // Standard lib (exit, atexit)
#include <ctype.h> // Character classification (iscntrl)
#include <stdio.h> // Standard I/O (printf, perror)

//functions
void enable_raw_mode();
void disable_raw_mode();
void die(const char *s);

//structs
struct termios orig_termios; // holds original terminal state to restore later

int main ()
{
    enable_raw_mode();

    while (1)
    {
        char c = '\0';
        // byte read from stdin; returns -1 on error
        // EAGAIN check is for non blocking timeouts
        if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN) die("read");

        // if char is control char (Ctrl, Esc, Backspace)
        if(iscntrl(c))
        {
            //printf ; can print mult. representations of a byte.
            //&d tells it to format the byte as decimal num
            printf("%d\r\n", c); 
        }
        else 
        {
            //%c tells it to write out the byte directly as a char 
            printf("%d ('%c')\r\n", c, c);
        }

        if (c== 'q') break;
    }
    return 0;
}

//en fn
void enable_raw_mode()
{
    // get current terminal attributes
    if (tcgetattr(STDIN_FILENO, &orig_termios) == -1) die("tcgetattr");

    //register cleanup handler to restore terminal on exit
    atexit(disable_raw_mode);

    struct termios raw = orig_termios;

    //bitwire not/and to disable specific terminal flags:
    // ICRNL: Fixes Ctrl-M; OPOST: turns off output processing
    raw.c_iflag &= ~(BRKINT | INPCK | ISTRIP | ICRNL);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag &= ~(CS8); // set char size to 8 bits

    // ECHO
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);

    raw.c_cc[VTIME] = 1;
    raw.c_cc[VMIN] = 0;


    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) die("tcsetattr");
}

//dis fn
void disable_raw_mode()
{
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1)
    {
        die("tcsetattr");
    }
}

//error handling fn
void die(const char *s)
{
    perror(s);
    exit(1);
}
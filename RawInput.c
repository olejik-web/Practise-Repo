#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <stdio.h>

struct termios orig_termios;

void disableRawModule() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);

}

void enableRawMode() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disableRawModule);

    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() {
    enableRawMode();
    char c;
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q') {
        printf("%c", c);
    }
    return 0;
}
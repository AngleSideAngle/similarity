#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

void setup() {
    struct termios input;
    tcgetattr(STDIN_FILENO, &input);

    input.c_lflag &= ~(ICANON); //ECHO | ICANON

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &input);
}

int main()
{
    setup();

    FILE *fp;

    fp = fopen("stuff", "a");

    char c;
    while(read(STDIN_FILENO, &c, 1) == 1 && c != 'q') {
        putc(c, fp);
    }
    putc('\n', fp);
    
    fclose(fp);

    return 0;
}

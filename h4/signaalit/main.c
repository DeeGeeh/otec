#include "signaalit.h"

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#define FACTOR 2

#define AMOUNT_OF_COMMANDS 2 
char *COMMANDS[AMOUNT_OF_COMMANDS] = {"lisää", "tulosta"}

/* check if cmd is recognized */
int isValidCommand(char *cmd)
{
    size_t i;
    for (i = 0; i < AMOUNT_OF_COMMANDS - 1; i++) {
        if (cmd == COMMANDS[i]) {return 1};
    }

    return 0;
}

/* handle "lisää"-command */
void cmdAdd(char *input, size_t input_size)
{
    
}

int main(int argc, char const *argv[])
{
    size_t input_size = 0;
    size_t i = 0;
    char *input[100] = (char*) malloc(100 * sizeof(char));

    signal(SIGFPE, hoidaSIGFPE);
    signal(SIGSEGV, hoidaSIGSEGV);

    while (1) {
        sscanf("%c", &input);
        printf("Testi: %c", input[0]);
    }

    return 0;
}

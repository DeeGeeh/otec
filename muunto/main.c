#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "muunto.h"

int main(int argc, char *argv[])
{
    int i = 1;
    for (; i < argc; ++i) {
        printf("%d: ", i);
        printf("%s", argv[i]);
        printf(" --> ");
        muunna(argv[i]);
        printf("\n");
    }
    return 0;
}

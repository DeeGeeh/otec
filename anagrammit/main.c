#include <stdio.h>

#include "anagrammit.h"

int main(int argc, char *argv[])
{
    char *mj1 = argv[1];
    char *mj2 = argv[2];

    printf("%d", anagrammeja(mj1, mj2));
    
    return 0;
}

#include <stdio.h>
#include "caesar.h"

int main(int argc, char *argv[])
{
    char *mj = argv[1];
    char *aakkosto = argv[2];
    char *korvaavat = argv[3];

    caesarKoodaa(mj, aakkosto, korvaavat);
    printf("%s\n", mj);

    return 0;
}

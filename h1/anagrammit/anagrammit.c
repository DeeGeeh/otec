#include "anagrammit.h"

int anagrammeja(char mj1[], char mj2[])
{
    int lkmt[UCHAR_MAX + 1] = {0};
    int i;
    for (i = 0; i < strlen(mj1); ++i) {
        unsigned char curr = mj1[i];
        lkmt[curr] += 1;
    }

    for (i = 0; i < strlen(mj2); ++i) {
        unsigned char curr = mj2[i];
        lkmt[curr] -= 1;
    }

    for (i = 0; i < UCHAR_MAX; ++i) {
        if (lkmt[i] != 0) {
            return 0;
        }
    }

    return 1;
}

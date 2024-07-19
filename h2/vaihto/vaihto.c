/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#include "vaihto.h"

void vaihda(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void jarjesta(int *a, int *b, int *c)
{
    if (*a > *b) {
        vaihda(a, b);
    }

    if (*b > *c) {
        vaihda(b, c);
    }

    if (*a > *b) {
        vaihda(a, b);
    }
}

int main(int argc, char const *argv[])
{
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    int z = atoi(argv[3]);

    printf("%d %d %d\n", x, y, z);
    vaihda(&x, &y);

    printf("%d %d %d\n", x, y, z);
    jarjesta(&x, &y, &z);

    printf("%d %d %d\n", x, y, z);

    return 0;
}
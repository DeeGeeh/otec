/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(int argc, char const *argv[])
{

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int amountOfDivisors = argc - 3;
    int divisors[100];
    size_t i, j;
    bool printed = false;
    bool isDivisable;

    if (argc < 3) {
        exit(EXIT_FAILURE);
    }

    /* Read divisors into array */
    for (i = 0; i < amountOfDivisors; i++) {
        divisors[i] = atoi(argv[i + 3]);
    }

    for (i = a; i <= b; i++) {
        isDivisable = false;
        for (j = 0; j < amountOfDivisors; j++) {
            if (i % divisors[j] == 0) {
                isDivisable = true;
                break;
            }
        }
        if (!isDivisable) {
            if (printed) {
                printf(" ");
            }
            printf("%d", i);
            printed = true;
        }
    }

    /* empty row when done */
    if (printed) {
        puts("");
    }

    return 0;
}

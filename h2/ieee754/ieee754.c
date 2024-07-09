/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Calculate and print mantissa */
void printMantissa(char *argv[]) {
    int i = 0;
    int j = 1;
    double sum = 0.0;
    int len = strlen(argv[1]);

    while (i < len) {
        if (argv[1][i] == '1') {
            sum += pow(0.5, j);
        }
        i++;
        j++;
    }
    sum += 1.0;
    printf("%0.15lf\n", sum);
}

void printSign(char signBit) {
    if (signBit == '1') {
        printf("-");
    } else {
        printf("+");
    }
}

void printExponent(char *argv[]) {
    int i = 1;
    int sum = 0;
    int len = (int) strlen(argv[1]);

    while (i < 8) {
        if (argv[1][i] == '1') {
            sum += pow(2, len - 1 - i);
        }
        ++i;
    }
    sum -= 127;
    printf("%d\n", sum);
}

int main(int argc, char *argv[])
{
    printMantissa(argv);
    printExponent(argv);
    printSign(argv[1][0]);
    printf("\n");

    return 0;
}

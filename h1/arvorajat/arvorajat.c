#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct limit
{
    char str[20];
    int min;
    int max;
};

const struct limit limits[5] = {
    {"signed char", SCHAR_MIN, SCHAR_MAX},
    {"unsigned char", 0, UCHAR_MAX},
    {"short int", SHRT_MIN, SHRT_MAX},
    {"unsigned short int", 0, USHRT_MAX},
    {"int", INT_MIN, INT_MAX}
};

const int LIMIT_TYPES = 5;

int main(int argc, char const *argv[]) {
    int val;
    bool first = true;
    int i = 1;
    int j = 0;

    for (i = 1; i < argc; ++i) {
        val = atoi(argv[i]);
        first = true;
        
        printf("%d:", val);

        for (j = 0; j < LIMIT_TYPES; ++j) {
            if (val >= limits[j].min && val <= limits[j].max) {
                if (!first) putchar(',');
                else first = false;
                printf(" %s", limits[j].str);
            }
        }
        putchar('\n');
    }

    return 0;
}

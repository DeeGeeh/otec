#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char sign = argv[1][0];
    int i = 0;
    int sum = 0;
    int len = strlen(argv[1]);

    while (i < len) {
        if (argv[1][i] == '1') {
            if (sign == '1' && i == 0) {
                sum -= pow(2, len - 1 - i);
            } else {
                sum += pow(2, len - 1 - i);
            }
        }
        ++i;
    }

    printf("%d\n", sum);


    return 0;
}

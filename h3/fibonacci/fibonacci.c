#include "fibonacci.h"


unsigned int *fib_jono(unsigned int n)
{
    unsigned int i;
    unsigned int *arr = malloc(n * sizeof(unsigned int));

    if (n == 0) {
        return NULL;
    }

    if (arr == NULL) {
        return NULL;
    }

    if (n > 0) arr[0] = 0;
    if (n > 1) arr[1] = 1;
    if (n > 2) arr[2] = 1;

    for (i = 3; i < n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    return arr;
}


int main(void)
{
    unsigned int *fibonacci = fib_jono(15); /* 15 ensimmäistä fibonaccin lukua. */
    int i = 0;
    for (i = 0; i < 15; ++i)
    {
        printf(" %u", fibonacci[i]);
    }
    printf("\n");
    free(fibonacci); /* Dynaamisesti varatun muistin vapautus. */
    return 0;
}

#include "bitit.h"

void scharBitit(signed char x)
{
    int i = CHAR_BIT - 1;
    int j = 0;
    int one_count = 0;
    char str[CHAR_BIT];

    printf("%d\n", x);

    /* convert int to binary string */
    for(; i >= 0; i--) {
        if ((x>>i) & 1) {
            str[j] = '1';
        }
        else {
            str[j] = '0';
        }
        j++;
    }

    /* print binary string */
    for (i = 0; i < CHAR_BIT; i++) {
        if (str[i] == '1') {
            one_count++;
        }
        printf("%c", str[i]);
    }
    putchar('\n');
    printf("%d\n", CHAR_BIT - one_count);
    printf("%d\n", one_count);
}

void shortBitit(short int x)
{
    int i = sizeof(short int) * CHAR_BIT - 1;
    int j = 0;
    int one_count = 0;
    char str[sizeof(short int) * CHAR_BIT];

    printf("%d\n", x);

    /* convert int to binary */
    for (; i >= 0; i--) {
        if ((x>>i) & 1) {
            str[j] = '1';
        }
        else {
            str[j] = '0';
        }
        j++;
    }

    /* print binary string */
    for (i = 0; i < (int) sizeof(short int) * CHAR_BIT; i++)
    {
        if (str[i] == '1')
        {
            one_count++;
        }
        printf("%c", str[i]);
    }
    putchar('\n');
    printf("%d\n", (int) sizeof(short int) * CHAR_BIT - one_count);
    printf("%d\n", one_count);
}

void intBitit(int x)
{
    int i = sizeof(int) * CHAR_BIT - 1;
    int j = 0;
    int one_count = 0;
    char str[sizeof(int) * CHAR_BIT];

    printf("%d\n", x);

    /* convert to binary */
    for(; i >= 0; i--) {
        if ((x>>i) & 1) {
            str[j] = '1';
        }
        else {
            str[j] = '0';
        }
        j++;
    }

    /* print binary */
    for (i = 0; i < sizeof(int)*CHAR_BIT; i++) {
        if (str[i] == '1')
        {
            one_count++;
        }
        printf("%c", str[i]);
    }
    putchar('\n');
    printf("%d\n", (int) sizeof(int) * CHAR_BIT - one_count);
    printf("%d\n", one_count);
}

void longBitit(long int x)
{
    int i = sizeof(long int) * CHAR_BIT - 1;
    int j = 0;
    int one_count = 0;
    char str[sizeof(long int) * CHAR_BIT];

    printf("%ld\n", x);

    /* convert to binary */
    for (; i >= 0; i--) {
        if ((x >> i) & 1) {
            str[j] = '1';
        }
        else {
            str[j] = '0';
        }
        j++;
    }

    /* print binary */
    for (i = 0; i < sizeof(long int) * CHAR_BIT; i++) {
        if (str[i] == '1') {
            one_count++;
        }
        printf("%c", str[i]);
    }
    putchar('\n');
    printf("%d\n", (int) sizeof(long int) * CHAR_BIT - one_count);
    printf("%d\n", one_count);
}


int main(int argc, char const *argv[])
{    
    long int x = 2015;

    scharBitit(x);
    putchar('\n');
    shortBitit(x);
    putchar('\n');
    intBitit(x);
    putchar('\n');
    longBitit(x);

    return 0;
}
#include "bitit.h"

void kaannaScharBitit(signed char *x) {
    signed char tmp = *x;
    signed char res = 0;
    int i = 0;

    for (; i < CHAR_BIT; i++) {
        /* jooh */
    }
}

void kaannaShortBitit(short *x) {

}

void kaannaIntBitit(int *x) {

}

void kaannaLongBitit(long *x) {

}

void tulosta_schar_bitit(signed char x)
{
    int i;
    int j = 0;
    char str[CHAR_BIT];
    printf("%d\n", x);

    /* convert int to binary string */
    for (i = CHAR_BIT - 1; i >= 0; i--)
    {
        if ((x >> i) & 1)
        {
            str[j] = '1';
        }
        else
        {
            str[j] = '0';
        }
        j++;
    }
    /* print the binary string */
    for (i = 0; i < CHAR_BIT; i++)
    {
        putchar(str[i]);
    }
    putchar('\n');
}

int main()
{
    long int lx = 2015;
    signed char cx = lx;
    short sx = lx;
    int ix = lx;

    tulosta_schar_bitit(cx);
    kaannaScharBitit(&cx);
    tulosta_schar_bitit(cx);
    printf("\n");
    
    /*
        tulosta_short_bitit(sx);
        kaannaShortBitit(&sx);
        tulosta_short_bitit(sx);
        printf("\n");

        tulosta_int_bitit(ix);
        kaannaIntBitit(&ix);
        tulosta_int_bitit(ix);
        printf("\n");

        tulosta_long_bitit(lx);
        kaannaLongBitit(&lx);
        tulosta_long_bitit(lx);
    */

    return 0;
}
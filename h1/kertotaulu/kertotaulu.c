#include <stdio.h>

int main(int argc, char const *argv[])
{
    int top = 15;
    int i, j;

    printf("   x");
    for (i = 1; i <= top; i++)
    {
        printf("%*d", 4, i);
    }
    printf("\n");

    for (i = 1; i <= top; i++)
    {
        printf("%*d", 4, i);
        for (j = 1; j <= top; j++)
        {
            printf("%*d", 4, i * j);
        }
        printf("\n");
    }

    return 0;
}

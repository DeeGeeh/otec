#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    for (a; a <= b; a++)
    {
        printf("%d: %c\n", a, a);
    }

    return 0;
}
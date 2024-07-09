#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int params = argc - 1;
    int a;
    for (a = 1; a <= params; a++)
    {
        unsigned int len = (unsigned int)strlen(argv[a]);
        printf("%d: %s (pituus: %u)\n", a, argv[a], len);
    }

    return 0;
}
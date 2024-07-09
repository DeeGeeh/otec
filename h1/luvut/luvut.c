#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    int target = 100;
    int start;
    bool first = true;

    for (start = 0; start < target; ++start)
    {
        if ((start % 2 != 0) && (start % 3 != 0) && (start % 5 != 0))
        {
            if (first)
            {
                printf("%d", start);
                first = false;
            }
            else
            {
                printf(" %d", start);
            }
        }
    }

    printf("\n");

    return 0;
}

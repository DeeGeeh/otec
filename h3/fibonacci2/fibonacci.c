#include "fibonacci.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *allocate_memory(size_t size)
{
    void *ptr = malloc(size);
    if (ptr == NULL)
    {
        printf("Memory alloc fail.");
        return NULL;
    }
    return ptr;
}

void *realloc_memory(void *ptr, size_t size)
{
    void *new_ptr = realloc(ptr, size);
    if (new_ptr == NULL)
    {
        printf("Memory realloc fail.");
        return NULL;
    }
    return new_ptr;
}

char *fib_jono_mj(unsigned int n)
{
    size_t size = 1;
    size_t len = 0;
    int i = 0;
    int num1 = 0;
    int num2 = 1;
    int fib = 1;
    int needed_buffer_size;
    char temp[20];
    char *str = (char *)allocate_memory(size * sizeof(char));

    if (n == 0)
    {
        str[0] = '\0';
        return str;
    }

    size *= 2;
    str = (char *)realloc_memory(str, size * sizeof(char));
    size = 8;
    str = (char *)realloc_memory(str, size * sizeof(char));
    len += sprintf(str + len, "0, 1");

    for (i = 2; i < n; i++)
    {
        fib = num1 + num2;
        num1 = num2;
        num2 = fib;

        sprintf(temp, " %d", fib);
        needed_buffer_size = strlen(temp) + 1;

        /* double the size of the string if needed */
        if (len + needed_buffer_size > size)
        {   
            size *= 2;
            str = (char *)realloc_memory(str, size * sizeof(char));
        }

        len += sprintf(str + len, ",%s", temp);
    }

    str = (char *)realloc_memory(str, len * sizeof(char) + 1);

    return str;
}

int main(int argc, char *argv[])
{
    char *fibonacci = fib_jono_mj(atoi(argv[1]));
    printf("%s\n", fibonacci);
    free(fibonacci);
    return 0;
}
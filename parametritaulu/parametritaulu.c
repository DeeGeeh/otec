#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int getTotalWidth(int leftWidth, int rightWidth) {
    return leftWidth + rightWidth + 8;
}

int getLeftWidth(int rows)  {
    int width = 0;
    while (rows > 0)
    {
        width++;
        rows /= 10;
    }
    return width;
}

int getRightWidth(unsigned int args, const char* argv[]) {
    int i = 1;
    size_t currWidest = 0;
    while (i < args) {
        size_t wordLength = strlen(argv[i]);
        if (wordLength > currWidest) {
            currWidest = wordLength;
        }
        ++i;
    }
    return currWidest;
}

void printHashtagRow(int width) {
    int i = 0;
    for (i = 0; i < width-1; ++i) {
        printf("#");
    }
    printf("\n");
}

void printSeparatorRow(int leftWidth, int rightWidth)
{
    int i;
    printf("#");
    for (i = 0; i <= leftWidth + 1; ++i) {
        printf("-");
    }
    printf("+");
    for (i = 0; i <= rightWidth + 1; ++i) {
        printf("-");
    }
    printf("#\n");
}

void printCountries(int argc, char const *argv[]) {
    unsigned int leftColWidth = getLeftWidth(argc - 1);
    unsigned int rightColWidth = getRightWidth(argc - 1, argv);
    int totalWidth = getTotalWidth(leftColWidth, rightColWidth);
    int i;

    printHashtagRow(totalWidth);
    for (i = 1; i < argc; ++i) {
        printf("# %*d ", leftColWidth, i);
        printf("| ");
        printf("%-*s", rightColWidth, argv[i]);
        printf(" #\n");
        if (i != argc - 1) {
            printSeparatorRow(leftColWidth, rightColWidth);
        }
    }
    printHashtagRow(totalWidth);
}

int main(int argc, char const *argv[])
{
    printCountries(argc, argv);
    return 0;
}

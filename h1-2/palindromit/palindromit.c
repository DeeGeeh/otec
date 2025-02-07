#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(const char* word, const unsigned int wordLength) 
{
    size_t i = 0;
    size_t front = 0;
    size_t back = (size_t) wordLength - 1;

    for (i = 0; i < wordLength / 2; i++) {
        if (tolower(word[front]) == tolower(word[back])) {
            front++;
            back--;
        }
        else {
            return false;
        }
    }

    return true;
}

int main(int argc, char const *argv[])
{
    size_t i = 0;

    for (i = 1; i < argc; i++) {
        if (isPalindrome(argv[i], strlen(argv[i]))) {
            printf("\"%s\": on palindromi\n", argv[i]);
        }
        else
        {
            printf("\"%s\": ei ole palindromi\n", argv[i]);
        }
    }
    return 0;
}

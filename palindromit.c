#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checkEvenLength(int length, const char *word) {
    int half = length / 2;
    int i;
    for (i = 0; i < half; ++i) {
        if (tolower(word[i]) != tolower(word[length - 1 - i])) {
            return false;
        }
    }
    return true;
}

bool checkOddLength(int length, const char *word) {
    int half = length / 2;
    int i;
    for (i = 0; i < half; ++i)
    {
        if (tolower(word[i]) != tolower(word[length - 1 - i])) {
            return false;
        }
    }
    return true;
}

bool isPalindrome(const char *word) {
    bool result = false;
    int wordLength = strlen(word);
    if (wordLength % 2 == 0) {
        return checkEvenLength(wordLength, word);
    }
    else {
        return checkOddLength(wordLength, word);
    }

    return result;
}

int main(int argc, const char *argv[])
{
    int count = 1;
    while (count != argc)  {
        if (isPalindrome(argv[1])) {
            printf("\"%s\": on palindromi\n", argv[count]);
        } 
        else {
            printf("\"%s\": ei ole palindromi\n", argv[count]);
        }
        ++count;
    }
    return 0;
}

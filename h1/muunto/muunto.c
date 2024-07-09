#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "muunto.h"

void muunna(char mj[]) {
    int len = strlen(mj);
    int i = 0;
    char tmp;

    for (i = 0; i < len; ++i) {
        if (isalpha(mj[i])) {
            if (islower(mj[i])) {
                mj[i] = toupper(mj[i]);
                continue;
            }
            mj[i] = tolower(mj[i]);
        }
    }

    for (i = 0; i < len / 2; ++i) {
        tmp = mj[len - i - 1];
        mj[len - i - 1] = mj[i];
        mj[i] = tmp;
    }
}

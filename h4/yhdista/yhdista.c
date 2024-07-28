/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#include "yhdista.h"

char *yhdista(const char *mj, ...)
{
    const char *tmp; 
    char* result;
    size_t len = 0;
    va_list pl;

    /* calc length of strings */
    va_start(pl, mj);
    tmp = mj;
    while (tmp != NULL) {
        len += strlen(tmp);
        tmp = va_arg(pl, const char*);
    }
    va_end(pl);

    /* alloc memory */
    result = (char*) malloc(len + 1);
    if (!result) {return NULL;}

    result[0] = '\0';
    va_start(pl, mj);
    tmp = mj;
    while (tmp != NULL) {
        strcat(result, tmp);
        tmp = va_arg(pl, const char *);
    }
    va_end(pl);

    return result;
}

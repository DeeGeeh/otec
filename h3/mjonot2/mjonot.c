/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#include "mjonot.h"

/* cheeky bubble sort has entered the chat */
void sort_arrays(char** kopio_mjt, size_t lkm, int (*vrt)(const char *, const char *)) {
    char *temp = NULL;
    size_t i, j;

    for (i = 0; i < lkm - 1; i++) {
        for (j = 0; j < lkm - 1 - i; j++) {
            if (!vrt(kopio_mjt[j], kopio_mjt[j + 1])) {
                temp = kopio_mjt[j];
                kopio_mjt[j] = kopio_mjt[j + 1];
                kopio_mjt[j + 1] = temp;
            }
        }
    }

}


char **jarjesta_mjt(char **mjt, size_t lkm, int (*vrt)(const char *, const char *))
{
    char **kopio = (char **)malloc(lkm * sizeof(char *));
    char *first = NULL;
    size_t i, j;

    /* kopioi mjt */
    for (i = 0; i < lkm; i++) {
        size_t len = strlen(mjt[i]);
        kopio[i] = (char *)malloc((len + 1) * sizeof(char));
        memcpy(kopio[i], mjt[i], len + 1);
    }
    
    sort_arrays(kopio, lkm, vrt);

    return kopio;
}
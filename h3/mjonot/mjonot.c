/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#include "mjonot.h"

char **kopioi_mjt(char **mjt, size_t lkm) {
    
    char **kopio = (char**) malloc(lkm * sizeof(char*));
    size_t i = 0;

    for (; i < lkm; i++) {
        size_t len = strlen(mjt[i]);
        kopio[i] = (char*) malloc((len + 1) * sizeof(char));
        memcpy(kopio[i], mjt[i], len+1);
    }

    return kopio;
}

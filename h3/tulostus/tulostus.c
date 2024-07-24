/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#include "tulostus.h"

void tulostaDblTaulu(double *taulu, size_t lkm, const char *taulNimi, int tarkkuus, const char *tiedNimi)
{
    int i;
    /* open file */
    FILE *f = fopen(tiedNimi, "w");
    if (f == NULL) {
        exit(1);
    }

    /* write into file */
    for (i = 0; i < lkm; i++) {
        fprintf(f, "%s[%i] = %.*f\n", taulNimi, i, tarkkuus, taulu[i]);
    }

    fclose(f);
}

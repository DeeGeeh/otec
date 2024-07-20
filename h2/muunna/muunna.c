/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#include "muunna.h"

void muunnaTaulu(unsigned int koko, double *taulu, double(*muunnos)(double x))
{
    int i = 0;

    for (; i < koko; i++) {
        taulu[i] = muunnos(taulu[i]);
    }
}
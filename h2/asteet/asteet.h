/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#ifndef asteet_h
#define asteet_h

#include <stdio.h>

typedef enum {
    Celsius,
    Fahrenheit,
    Kelvin
} Asteikko;

typedef struct {
    float lampotila;
    Asteikko asteikko;
} Lampotila;

float muunna(Lampotila a, Asteikko b);
float erotus(Lampotila a, Lampotila b, Asteikko c);

#endif
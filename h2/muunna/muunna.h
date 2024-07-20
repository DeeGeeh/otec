/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#ifndef muunna_h
#define muunna_h

#include <stdio.h>
#include <math.h>

double triplaa(double x);
void muunnaTaulu(unsigned int koko, double *taulu, double (*muunnos)(double x));

#endif
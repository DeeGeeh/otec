/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#if !defined(YKKOSVALIT_H)
#define YKKOSVALIT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    unsigned int x;
    unsigned int y;
} UintPari;

UintPari ykkosValit(const char *syoteNimi, const char *tulosNimi);

#endif // YKKOSVALIT_H

/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#ifndef mjonot_h
#define mjonot_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **jarjesta_mjt(char **mjt, size_t lkm, int (*vrt)(const char *, const char *));

#endif
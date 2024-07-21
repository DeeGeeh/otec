/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#ifndef kertotaulu_h
#define kertotaulu_h

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

typedef struct
{
    uint a;
    uint b;
    uint c;
    uint d;
    uint **kertotaulu;
} Kertotaulu;

Kertotaulu *luoKertotaulu(uint a, uint b, uint c, uint d);
void tuhoaKertotaulu(Kertotaulu *kt);

#endif
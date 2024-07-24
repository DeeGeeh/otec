/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#include "gotokoe.h"

int max2D(int **t2d, int kork, int lev)
{
    int x = 0;
    int y = 0;
    int max = t2d[0][0];

    start:
    if (t2d[y][x] > max) max = t2d[y][x];
    x++;
    if (x < lev) goto start;

    x = 0;
    y++;
    if (y < kork) goto start;

    return max;
}
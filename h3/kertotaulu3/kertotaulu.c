/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#include <stdlib.h>
#include "kertotaulu.h"

#define EMPTY 0

Kertotaulu *luoKertotaulu(uint a, uint b, uint c, uint d)
{
    int i, row, col;
    int x = b - a + 1;
    int y = d - c + 1;
    Kertotaulu* kt;
    uint** list = (uint**) malloc((y+1) * sizeof(uint*));

    /* handle malloc fail */
    if (!list) {return NULL;}

    /* check for bad params */
    if ((a > b) || (c > d)) { 
        free(list);
        return NULL;
    }

    for(row = 0; row <= y; row++) {
        list[row] = (uint*) malloc((x+1) * sizeof(uint));
        /* handle malloc fail */
        if (!list[row]) {
            for (i = 0; i < row; i++) {
                free(list[i]);
            }
            free(list);
            return NULL;
        }
        for (col = 0; col <= x; col++) {
            if (row == 0 && col == 0) {
                list[row][col] = EMPTY;
            }
            else if (row == 0) {
                list[row][col] = a + col - 1;
            }
            else if (col == 0) {
                list[row][col] = c + row - 1;
            }
            else {
                list[row][col] = (a + col - 1) * (c + row - 1);
            }
        }
    }
    kt = (Kertotaulu *)malloc(sizeof(Kertotaulu));
    if (!kt) {
        for (i = 0; i <= y; i++)
        {
            free(list[i]);
        }
        free(list);
        return NULL;
    }
    
    kt->a = a;
    kt->b = b;
    kt->c = c;
    kt->d = d;
    kt->kertotaulu = list;

    return kt;
}

void tuhoaKertotaulu(Kertotaulu *kt)
{
    int i = 0;
    int y = kt->d - kt->c + 2;

    if (!kt) {return;}

    if (kt->kertotaulu) {
        for (i = 0; i <= y; i++) {
            if (kt->kertotaulu[i]) {
                free(kt->kertotaulu[i]);
            }
        }
        free(kt->kertotaulu);
    }
    free(kt);
}
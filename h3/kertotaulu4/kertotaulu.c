/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#include "kertotaulu.h"

#define EMPTY 0

void *safe_malloc(size_t n) {
    void *p = malloc(n);
    if (p == NULL) {
        fprintf(stderr, "Fatal: failed to allocate %zu bytes.\n", n);
        abort();
    }
    return p;
}

char **luo_kertotaulu_mjt(uint a, uint b, uint c, uint d) {
    uint *widths;
    char **rows; 
    char *temp_row;
    int *result_val;
    int i, j, row, col;
    int size_x = b - a + 1;
    int size_y = d - c + 1; 

    /* calc and fill widths */
    for (col = 0; col < size_x; col++) {
        if (col == 0) {
            widths[col] = d;
        }
        else {
            widths[col] = d * (a + col - 1);
        }
    }

    /* calc and fill rows */
    for (row = 0; row <= size_y; row++) {
        for (col = 0; col <= size_x; col++) {
            if ((row == 0) && (col == 0)) {
                sprintf(temp_row, "%.*d", widths[col], EMPTY);
            }
            else if (row == 0) {
                *result_val = a + col - 1;
                sprintf(temp_row, "%.*d", widths[col], *result_val);
            }
            else if (col == 0) {
                *result_val = c + row - 1;
                sprintf(temp_row, "%.*d", widths[col], *result_val);
            }
            else {
                *result_val = (a + col - 1) * (c + row - 1);
                sprintf(temp_row, "%.*d", widths[col], *result_val);
            }
        }
        sprintf(*rows, "%s", temp_row);
    }

    free(widths);
    widths = NULL;

    return NULL;
}
/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#include "luku.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 1
#define GROWTH_FACTOR 2


char *lueKunnes(FILE *virta, char erotin, size_t *pituus)
{
    size_t length = 0;
    size_t cap = INITIAL_CAPACITY;
    int currChar;
    char *buffer = (char *) malloc(cap * sizeof(char));

    while ((currChar = fgetc(virta)) != EOF && (currChar != erotin)) {
        /* if more memory is needed */
        if (length >= cap) {
            cap *= GROWTH_FACTOR;
            buffer = (char *) realloc(buffer, cap * sizeof(char));
        }

        buffer[length] = (char) currChar;
        length++;
    }

    if (length > 0 || currChar == erotin ) {        
        /* null terminate */
        buffer = (char*) realloc(buffer, (length + 1) * sizeof(char));
        buffer[length] = '\0';
    }
    else {
        buffer = (char*) realloc(buffer, 0);
    }
    
    *pituus = length;
    return buffer;

}
#if !defined(KOLMIJAKO_H)
#define KOLMIJAKO_H

#include <stdio.h>
#include <stdlib.h>


struct IntPari {
    int x;
    int y;
};
typedef struct IntPari IntPari;

IntPari kolmijako(unsigned int n, int t[], int vipu1, int vipu2, int *p1, int *p2);


#endif

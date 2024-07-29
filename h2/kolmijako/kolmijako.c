#include "kolmijako.h"

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void testPrintArr(const unsigned int n, const int t[])
{
    size_t i = 0;
    for (; i < n; i++) {
        printf("%d ", t[i]);
    }
    puts("");
}

IntPari kolmijako(unsigned int n, int t[], int vipu1, int vipu2, int *p1, int *p2)
{
    IntPari result;
    size_t i;
    int pienet1 = 0;
    int pienet2;

    /* make sure vipu1 is smaller than vipu2 */
    if (t[vipu1] > t[vipu2]) {
        swap(&t[vipu1], &t[vipu2]);
    }

    /* sort first segment */
    for(i = 0; i < n; i++) {
        if (t[i] < t[vipu1]) {
            swap(&t[i], &t[pienet1]);
            if (vipu1 == pienet1) {
                vipu1 = i;
            }
            else if (vipu2 == pienet1) {
                vipu2 = i;
            }
            pienet1++;
        }
    }

    
    if (vipu2 == pienet1) {
        swap(&t[pienet1], &t[vipu1]);
        /*vipu1 = t[pienet1]; */
        printf("%d\n", t[pienet1]);
    } else {
        swap(&t[pienet1], &t[vipu1]);
    }

    testPrintArr(n, t);

    pienet2 = pienet1 + 1;


    /* sort third segment */
    for (i = pienet2; i < n; i++) {
        if (t[i] < t[vipu2]) {
            swap(&t[i], &t[pienet2]);
            if (vipu2 == pienet2) {
                vipu2 = i;
            }
            pienet2++;
        }
    }
    swap(&t[pienet2], &t[vipu2]);

    *p1 = pienet1;
    *p2 = pienet2;
    result.x = pienet1;
    result.y = pienet2;
    return result;
}

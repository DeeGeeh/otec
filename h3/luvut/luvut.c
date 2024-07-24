/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#include <stdio.h>
#include <stdlib.h>

#define FACTOR 2

int compare(const void *a, const void *b)
{
    double da = *(const double*) a;
    double db = *(const double*) b;

    return (da > db) - (da < db);
}

void print_values(double* arr, size_t arr_size)
{
    size_t i;
    double sum = 0;
    double avg = 0.0;

    qsort(arr, arr_size, sizeof(double), compare);

    printf("Luettiin %i lukua:", (int)arr_size);
    for (i = 0; i < arr_size; i++) {
        printf(" %.3f", arr[i]);
        sum += arr[i];
    }
    putchar('\n');

    avg = sum / arr_size;
    printf("Summa: %.3f\n", sum);
    printf("Keskiarvo: %.3f\n", avg);
}

int main(int argc, char const *argv[])
{
    size_t koko = 2;
    size_t count = 0;
    double* arr = (double*) malloc(koko * sizeof(double)); 
    double x = 0;

    /* read input and store it */
    while (scanf("%lf", &x) == 1) {
        if (count >= koko) {
            koko = koko * FACTOR;
            arr = (double*) realloc(arr, koko * sizeof(double));
        }
        arr[count] = x;
        count++;
    }

    /* trim array to correct size */
    arr = (double *) realloc(arr, count * sizeof(double));

    /* take a wild quess on what this does */
    print_values(arr, count);

    free(arr);
    return 0;
}

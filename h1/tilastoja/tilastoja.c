/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


double getSmallest(double *values, int amountOfVals) 
{
    size_t i;
    double smallest = values[0];
    for (i = 0; i <= amountOfVals; i++) {
        if (smallest > i) {
            smallest = i;
        }
    }

    return smallest;
}

double getGreatest(double *values, int amountOfVals) {
    size_t i;
    double greatest = values[0];
    for (i = 0; i <= amountOfVals; i++) {
        if (greatest > i) {
            greatest = i;
        }
    }

    return greatest;
}

void printUniques(double *values, int amountOfVals) 
{
    size_t i, j;
    double uniques[128];
    size_t sizeOfUniques = 0;
    bool isUnique;

    for (i = 0; i < amountOfVals; i++) {
        isUnique = true;
        for (j = i + 1; j < amountOfVals; j++) {
            if (values[i] == values[j]) {
                isUnique = false;
            }
        }
        if (isUnique) {
            uniques[sizeOfUniques] = values[i];
            sizeOfUniques++;
        }
    }

    if (sizeOfUniques > 0) {
        printf("Ainutlaatuiset:");
        for (i = 0; i < sizeOfUniques; i++) {
            printf(" %.6f", uniques[i]);
        }
        printf("\n");
    }
}

void printMostCommon(double *values, int amountOfVals) 
{
    double mostCommon[128];
    double currentVal = values[0];
    size_t timesFound = 0;
    size_t i;

    for (i = 0; i < amountOfVals; i++) {
        if (values[i] == currentVal) {
            timesFound++;
        }
    }   
}


int main(int argc, char const *argv[]) 
{
    const int amountOfVals = argc - 1;
    double values[amountOfVals];
    double smallest = getSmallest(values, amountOfVals);
    double greatest = getGreatest(values, amountOfVals);

    printf("Pienin: %.6f\n", smallest);
    printf("Suurin: %.6f\n", greatest);
    printUniques(values, amountOfVals);
    

    return 0;
}

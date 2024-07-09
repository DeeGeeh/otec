#include <stdio.h>
#include <stdlib.h>

#include "geometria.h"

int main(int argc, char const *argv[])
{
    int i;
    printf("Piin arvo: %0.19Lf\n", PII);
    for (i = 1; i < argc; ++i) {
        printf("Säteen %f omaavan ympyrän ala ja pallon tilavuus: %0.10f ja %0.10f\n", 
            atof(argv[i]),
            ympyranAla(atof(argv[i])),
            pallonTilavuus(atof(argv[i]))
            );
        printf("Säteen %f omaavan ympyrän piiri on %0.10Lf\n",
            atof(argv[i]),
            2 * PII * atof(argv[i]));
    }

    return 0;
}

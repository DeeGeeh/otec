#include <math.h>

#include "geometria.h"

const long double PII = 3.1415926535897932385L;

double ympyranAla(double sade) {
    return PII * pow(sade, 2);
}

double pallonTilavuus(double sade) {
    return (4 * PII * pow(sade, 3)) / 3;
}
#include <math.h>
#include "likimvrt.h"

double toleranssi = 0.000001;

double lueToleranssi() {
    return toleranssi;
}

void asetaToleranssi(double uusiToleranssi) {
    toleranssi = uusiToleranssi;
}

int doubleVrt(double a, double b) {
    if ((fabs(a-b) <= toleranssi)) {
      return 1;
    }
    
    return 0;
}

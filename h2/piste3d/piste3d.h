#ifndef piste3d_h
#define piste3d_h

#include <stdio.h>
#include <math.h>

typedef struct
{
    double x;
    double y;
    double z;
} Piste3D;


double etaisyys(Piste3D a, Piste3D b);
void tulosta(Piste3D p, int tarkkuus);


#endif
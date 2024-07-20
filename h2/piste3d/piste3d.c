#include "piste3d.h"

double etaisyys(Piste3D a, Piste3D b)
{
    double res;
    double x = pow((a.x - b.x), 2);
    double y = pow((a.y - b.y), 2);
    double z = pow((a.z - b.z), 2);
    res = sqrt(x+y+z);
    return res;
}

void tulosta(Piste3D p, int tarkkuus) 
{
    printf("(%.*f, %.*f, %.*f)", tarkkuus, p.x,
                                 tarkkuus, p.y,
                                 tarkkuus, p.z);
}
#include "murtoluku.h"
/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

/* get greatest common divisor / suurin yhteinen tekijä */
int gcd(int a, int b)
{
    int temp;
    a = abs(a);
    b = abs(b);

    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

Murtoluku tee_murtoluku(int os, int nim)
{
    Murtoluku ml;
    ml.os = os;
    ml.nim = nim;
    return ml;
}

Murtoluku supistettuML(int os, int nim)
{
    int gcdValue;

    if ((os == 0 || nim == 0)) {
        return tee_murtoluku(os, nim);
    }

    if (nim < 0) {
        os = -os;
        nim = -nim;
    }

    gcdValue = gcd(os, nim);
    os /= gcdValue;
    nim /= gcdValue;

    return tee_murtoluku(os, nim);
}

Murtoluku lisaaML(Murtoluku a, Murtoluku b)
{
    int uusiOs = a.os * b.nim + b.os * a.nim;
    int uusiNim = a.nim * b.nim;

    return supistettuML(uusiOs, uusiNim);
}

Murtoluku vahennaML(Murtoluku a, Murtoluku b)
{
    int uusiOs = a.os * b.nim - b.os * a.nim;
    int uusiNim = a.nim * b.nim;

    return supistettuML(uusiOs, uusiNim);
}

Murtoluku kerroML(Murtoluku a, Murtoluku b)
{
    int uusiOs = a.os * b.os;
    int uusiNim = a.nim * b.nim;

    return supistettuML(uusiOs, uusiNim);
}

Murtoluku jaaML(Murtoluku a, Murtoluku b)
{
    int uusiOs = a.os * b.nim;
    int uusiNim = a.nim * b.os;

    return supistettuML(uusiOs, uusiNim);
}

void tulostaML(Murtoluku ml)
{    
    if (ml.os == 0) {
        printf("%d", ml.os);
        return;
    }

    if (ml.nim == 1) {
        printf("%d", ml.os);
        return;
    }

    printf("%d/%d", ml.os, ml.nim);
}

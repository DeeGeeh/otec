/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#include "vertailu.h"
#include "rectangle.h"


int rectAlaVrt(const void *a, const void *b)
{
    const Rectangle* rectA = *(const Rectangle**) a;
    const Rectangle* rectB = *(const Rectangle**) b;
    const int areaA = getArea(rectA);
    const int areaB = getArea(rectB);

    return (areaA > areaB) - (areaA < areaB);
}

int rectXyVrt(const void *a, const void *b)
{
    const Rectangle *rectA = *(const Rectangle **)a;
    const Rectangle *rectB = *(const Rectangle **)b;
    if (rectA->origin.x == rectB->origin.x) {
        return rectA->origin.y - rectB->origin.y;
    }
    else {
        return rectA->origin.x - rectB->origin.x;
    }
}

int rectLeveysVrt(const void *a, const void *b)
{
    const Rectangle *rectA = *(const Rectangle **)a;
    const Rectangle *rectB = *(const Rectangle **)b;
    return rectB->width - rectA->width;
}

int mjPitAakkosVrt(const void *a, const void *b)
{
    const char *strA = *(const char **) a;
    const char *strB = *(const char **) b;
    unsigned int aLength = strlen(strA);
    unsigned int bLength = strlen(strB);

    /* Length based */
    if (aLength != bLength) {
        return (aLength < bLength) - (aLength > bLength);
    }
    /* alphabetically */
    else {
        return strcmp(strA, strB) ;
    }
}

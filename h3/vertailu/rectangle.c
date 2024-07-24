/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#include <stdlib.h>
#include "rectangle.h"

#define DEFAULT 0

Rectangle *createRectangle(void)
{
    Rectangle *r = malloc(sizeof(Rectangle *));
    Point *p = malloc(sizeof(Point *));
    p->x = DEFAULT;
    p->y = DEFAULT;
    r->origin = *p;
    r->height = DEFAULT;
    r->width = DEFAULT;

    return r;
}

Rectangle *createRectangle2(Point p)
{
    Rectangle *r = malloc(sizeof(Rectangle *));
    r->height = DEFAULT;
    r->width = DEFAULT;
    r->origin = p;

    return r;
}

Rectangle *createRectangle3(int w, int h)
{
    Rectangle *r = malloc(sizeof(Rectangle *));
    Point *p = malloc(sizeof(Point *));
    p->x = DEFAULT;
    p->y = DEFAULT;
    r->origin = *p;
    r->height = h;
    r->width = w;

    return r;
}

Rectangle *createRectangle4(Point p, int w, int h)
{
    Rectangle *r = malloc(sizeof(Rectangle *));
    Point *pp = malloc(sizeof(Point *));
    pp->x = p.x;
    pp->y = p.y;
    r->origin = *pp;
    r->height = h;
    r->width = w;

    return r;
}

void move(Rectangle *r, int x, int y)
{
    r->origin.x = x;
    r->origin.y = y;    
}

int getArea(const Rectangle *r)
{
    return r->height * r->width;
}

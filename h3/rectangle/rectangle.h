/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#ifndef rectangle_h
#define rectangle_h

#define DEFAULT 0

#include <stdio.h>
#include <stdlib.h>


typedef struct 
{
    int x;
    int y;
} Point;

typedef struct
{
    int width;
    int height;
    Point origin;
} Rectangle;

Rectangle *createRectangle(void);

Rectangle *createRectangle2(Point p);

Rectangle *createRectangle3(int w, int h);

Rectangle *createRectangle4(Point p, int w, int h);

void move(Rectangle *r, int x, int y);

int getArea(const Rectangle *r);

#endif

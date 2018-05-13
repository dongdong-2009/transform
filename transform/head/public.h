#ifndef __PUBLIC_H__
#define __PUBLIC_H__

#include "include.h"


typedef struct Point
{
    char x;
    char y;
}Point;


extern void copy_Point(Point *a,Point *b);

#endif

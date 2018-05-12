#ifndef __O_B_H__
#define __O_B_H__


#include "include.h"

#define ROW 73
#define COL 98

extern double k1;
extern double k2;
extern char img_origin[][80];
extern char img_bucket[ROW][COL];
extern Point point[60][80];
extern int max[2];
extern int min[2];

extern Point OB_rivise[ROW][COL];   //桶形校正表
extern Point BO_rivise[60][80];     //桶形反校正表
extern Point add_rivise[2357];


extern void init_B(char img_bucket[][COL]);
extern void show_B();
extern void get_B_Tran(char img_origin[][80],Point point[][80]);
extern void add_Max();
extern int tran_O_B(char img_origin[][80],char img_bucket[][COL]);


#endif

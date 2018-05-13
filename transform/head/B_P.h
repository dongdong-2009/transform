#ifndef __B_P_H__
#define __B_P_H__


#include "include.h"

extern Point_4 BP_rivise[175][205];
extern char img_P[175][205];
extern int P_T[175][2];    //记录P图中梯形的位置，校正和分析时只对梯形区域进行校正

extern void tran_B_P();
extern void show_P();


#endif

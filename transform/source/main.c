#include "include.h"


void copy_Point(Point *a,Point *b);

int main()
{
    int i=0;
    int j=0;

    read_flie("./data/511.txt",img_origin);    //读取图片
    show_Img(img_origin);               //显示原图
    get_B_Tran(img_origin,point);       //求转换关系
    add_Max();
    init_B(img_bucket);                 //初始化接受矩阵
    tran_O_B(img_origin,img_bucket);    //完成矩阵的转化
    //show_B();


    printf("\n%d %d %d %d",min[0],max[0],min[1],max[1]);
    getchar();

    return 1;
}


void copy_Point(Point *a,Point *b)
{
    (*a).x=(*b).x;
    (*a).y=(*b).y;
}

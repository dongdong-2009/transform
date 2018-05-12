#include "include.h"


int main()
{
    read_flie("./data/511.txt",img_origin);    //读取图片
    show_Img(img_origin);               //显示原图
    get_B_Tran(img_origin,point);       //求转换关系,将结果存于坐标点中
    add_Max();                          //将坐标点加上相应的位移量

    init_B(img_bucket);                 //初始化接受矩阵
    if(img_origin[1][4]==49)
    {
        1+2;
    }
    tran_O_B(img_origin,img_bucket);    //完成矩阵的转化
    show_B();

    printf("\n%d %d %d %d",min[0],max[0],min[1],max[1]);
    getchar();

    return 1;
}




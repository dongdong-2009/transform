#include "include.h"



int main()
{
    int i=0;
    int j=0;
    int flag=0;

    read_flie("./data/511.txt",img_origin);    //读取图片
    show_Img(img_origin);               //显示原图
    //get_B_Tran(img_origin,point);       //求转换关系,将结果存于坐标点中
    //add_Max();                          //将坐标点加上相应的位移量
    init_B(img_bucket);                 //初始化接受矩阵
    tran_O_B(img_origin,img_bucket);    //完成矩阵的转化
    //show_B();
    //tran_B_P();
    //show_P();
    init_P();
    tran_B_P();
    show_P();

    printf("\n%d %d %d %d %d",min[0],max[0],min[1],max[1],sss);
    getchar();

    return 1;
}




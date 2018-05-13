#include "include.h"


int main()
{
    int i=0;
    int j=0;
    int count=0;

    FILE *fp=fopen("E:\\github\\transform\\transform\\data\\OB_rivise.txt","w");
    if(!fp)
    {
        printf("Can't open file\n");
        return 0;
    }

    read_flie("./data/511.txt",img_origin);    //读取图片
    show_Img(img_origin);               //显示原图
    get_B_Tran(img_origin,point);       //求转换关系,将结果存于坐标点中
    add_Max();                          //将坐标点加上相应的位移量

    init_B(img_bucket);                 //初始化接受矩阵

    tran_O_B(img_origin,img_bucket);    //完成矩阵的转化

    show_B();

    printf("\n%d %d %d %d",min[0],max[0],min[1],max[1]);

    count=0;
    for(i=0;i<ROW;i++)
        {
            for(j=0;j<COL;j++)
            {
                fprintf(fp,"{%3d,%3d} ",OB_rivise[i][j].x,OB_rivise[i][j].y);
                count++;
                if(0==count%10) fprintf(fp,"\n");
            }
        }
    fclose(fp);

    getchar();

    return 1;
}




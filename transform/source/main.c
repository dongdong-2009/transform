// #include "include.h"


// int main()
// {
//     int i=0;
//     int j=0;
//     int count=0;

//     FILE *fs=fopen("E:\\github\\transform\\transform\\data\\OB_rivise.txt","w");
//     if(!fs)
//     {
//         printf("Can't open file\n");
//         return 0;
//     }

//     read_flie("./data/511.txt",img_origin);    //读取图片
//     show_Img(img_origin);               //显示原图
//     get_B_Tran(img_origin,point);       //求转换关系,将结果存于坐标点中
//     add_Max();                          //将坐标点加上相应的位移量

//     init_B(img_bucket);                 //初始化接受矩阵

//     tran_O_B(img_origin,img_bucket);    //完成矩阵的转化

//     show_B();

//     printf("\n%d %d %d %d",min[0],max[0],min[1],max[1]);

//     count=0;
//     for(i=0;i<ROW;i++)
//         {
//             fprintf(fs,"{");
//             for(j=0;j<COL;j++)
//             {
//                 fprintf(fs,"{%3d,%3d} ",OB_rivise[i][j].x,OB_rivise[i][j].y);
//                 if(j<COL-1) fprintf(fs,",");
//                 count++;
//                 if(0==count%10) fprintf(fs,"\n");
//             }
//             fprintf(fs,"}");
//             if(i<ROW-1) fprintf(fs,",");
//         }
//     fclose(fs);

//     getchar();

//     return 1;
// }



#include "include.h"


int main()
{
    int i=0;
    int j=0;

    read_flie("./data/511.txt",img_origin);    //读取图片
    show_Img(img_origin);               //显示原图
    //get_B_Tran(img_origin,point);       //求转换关系,将结果存于坐标点中
    //add_Max();                          //将坐标点加上相应的位移量
    init_B(img_bucket);                 //初始化接受矩阵
    tran_O_B(img_origin,img_bucket);    //完成矩阵的转化
    show_B();

    printf("\n%d %d %d %d",min[0],max[0],min[1],max[1]);
    getchar();

    return 1;
}




#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

#define ROW 73
#define COL 98
//#define m^n pow(m,n)

typedef struct Point
{
    int x;
    int y;
}Point;

//double k1=-0.000056;
//double k2=-0.000056;
double k1=0.000096;
double k2=0.000096;
char img_origin[60][80];
char img_bucket[ROW][COL];
Point point[60][80];
int max[2]={0,0};
int min[2]={110,110};
int count1=0;

Point OB_rivise[ROW][COL];   //桶形校正表
Point BO_rivise[60][80];     //桶形反校正表
Point add_rivise[]=
{

}

int read_flie(char* filePath,char img_origin[][80]);
void show_Img(char img_origin[][80]);
void get_B_Tran(char img_origin[][80],Point point[][80]);
void init_B(char img_bucket[][COL]);
void tran_O_B(char img_origin[][80],char img_bucket[][COL]);
void add_Max();
void show_B();
void copy_Point(Point *a,Point *b);

int main()
{
    int i=0;
    int j=0;

    read_flie("511.txt",img_origin);    //读取图片
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


int read_flie(char* filePath,char img_origin[][80])
{
    int i=0;
    int j=0;
    char c='\0';

    FILE *fp=fopen(filePath,"r");
    if(!fp)
    {
        printf("can't open file\n");
        return 0;
    }
    for(i=0;i<60;i++)
    {
        for(j=0;j<80;j++)
        {
            fscanf(fp,"%c",&c);
            if(c=='\n') fscanf(fp,"%c",&c);
            img_origin[i][j]=c;
        }

    }
    printf("图片信息读取成功！\n");
    fclose(fp);
    return 1;
}

void show_Img(char img_origin[][80])
{
    int i=0;
    int j=0;

    for(i=0;i<60;i++)
    {
        for(j=0;j<80;j++)
        {
            if('0'==img_origin[i][j])
            {
                printf(" ");
            }
            else
                printf("%c",img_origin[i][j]);
        }
        printf("\n");
    }
}


void get_B_Tran(char img_origin[][80],Point point[][80])
{
    int i=0;
    int j=0;
    double n=0;
    double m=0;
    double n1=0;
    double m1=0;

    for(i=0;i<60;i++)
    {
        for(j=0;j<80;j++)
        {
           n=i-30;
           m=j-40;
//           n1=n*(1+k1*n*n+k2*m*m);
//           m1=m*(1+k1*n*n+k2*m*m);
           n1=round(n*(1+k1*n*n+k2*m*m));
           m1=round(m*(1+k1*n*n+k2*m*m));

           n1+=30;
           m1+=40;
           point[i][j].x=n1;
           point[i][j].y=m1;
        }
    }
}


void init_B(char img_bucket[][COL])
{
    int i=0;
    int j=0;

    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            img_bucket[i][j]=2;
        }
    }
}


void add_Max()
{
    int i=0;
    int j=0;

    for(i=0;i<60;i++)
    {
        for(j=0;j<80;j++)
        {
           if(point[i][j].x!=i || point[i][j].y!=j)
           {
               if(point[i][j].x>max[0]) max[0]=point[i][j].x;
               if(point[i][j].y>max[1]) max[1]=point[i][j].y;
               if(point[i][j].x<min[0]) min[0]=point[i][j].x;
               if(point[i][j].y<min[1]) min[1]=point[i][j].y;
               //printf("%d %d %d %d\n",i,j,point[i][j].x,point[i][j].y);
           }
        }
    }
    for(i=0;i<60;i++)
    {
        for(j=0;j<80;j++)
        {
           point[i][j].x-=min[0];
           point[i][j].y-=min[1];
           OB_rivise[point[i][j].x][point[i][j].y].x=i;
           OB_rivise[point[i][j].x][point[i][j].y].y=j;
        }
    }
}

void tran_O_B(char img_origin[][80],char img_bucket[][COL])
{
    int i=0;
    int j=0;
    int count=0;
    double m,n;
    int n1,m1;

    for(i=0;i<60;i++)
    {
        for(j=0;j<80;j++)
        {
            img_bucket[point[i][j].x][point[i][j].y]=img_origin[i][j]-'0';
        }
    }
    count=0;
    for(i=0;i<ROW;i++)
        for(j=0;j<COL;j++)
            if(2==img_bucket[i][j])
            {
                printf("%4d,",i);
                count++;
                if(0==count%10) printf("\n");
            }
//    for(i=0;i<ROW;i++)
//    {
//        for(j=0;j<COL;j++)
//        {
//            if(2==img_bucket[i][j])
//            {
//                printf("%4d,",i);
//                count++;
//                if(0==count%10) printf("\n");
////                n=i-30;
////                m=j-40;
////                n1=30+round(n*(1-(k1-0.00001)*n*n-(k2-0.00007)*m*m))+min[0];
////                m1=40+round(m*(1-(k1-0.00001)*n*n-(k2-0.00007)*m*m))+min[1];
////                if(n1<0 || n1>=60 || m1<0 || m1>=80) img_bucket[i][j]=0;
////                else
////                    img_bucket[i][j]=img_origin[n1][m1]-'0';
//            }
//        }
//    }
//    printf("\n\n\n");
//    count=0;
//    for(i=0;i<ROW;i++)
//        for(j=0;j<COL;j++)
//            if(2==img_bucket[i][j])
//            {
//                printf("%4d,",j);
//                count++;
//                if(0==count%10) printf("\n");
//            }


}

void show_B()
{
    int i=0;
    int j=0;

    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            if(img_bucket[i][j]==0 || img_bucket[i][j]==2)
            {
                printf(" ");
            }
            else
                printf("%d",img_bucket[i][j]);
        }
        printf("\n");
    }
}

void copy_Point(Point *a,Point *b)
{
    (*a).x=(*b).x;
    (*a).y=(*b).y;
}

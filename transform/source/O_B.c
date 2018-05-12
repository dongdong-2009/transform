#include "include.h"


double k1=0.000096;
double k2=0.000096;
char img_origin[60][80];
char img_bucket[ROW][COL];
int max[2]={0,0};
int min[2]={110,110};
Point point[60][80];

Point OB_rivise[ROW][COL];   //桶形校正表
Point BO_rivise[60][80];     //桶形反校正表
// Point add_rivise[]=
// {

// }


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
           n1=round(n*(1+k1*n*n+k2*m*m));
           m1=round(m*(1+k1*n*n+k2*m*m));

           n1+=30;
           m1+=40;
           point[i][j].x=n1;
           point[i][j].y=m1;
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
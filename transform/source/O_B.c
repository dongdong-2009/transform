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
Point add_rivise[2357];


int tran_O_B(char img_origin[][80],char img_bucket[][COL])
{
    int i=0;
    int j=0;
    int count=0;
    int bad=0;
    double m=0,n;
    int n1,m1;
    char filename[]="E:\\github\\transform\\transform\\data\\add_rivise.txt";

    FILE *fp=fopen(filename,"r");

    if(!fp)
    {
        printf("Can't open file\n");
        return 0;
    }
//    if(img_origin[1][4]==49)
//    {
//        1+2;
//    }
    for(i=0;i<60;i++)
    {
        for(j=0;j<80;j++)
        {
            if(0==img_origin[1][4])
            {
                m=100;
                1+2;

            }
            img_bucket[point[i][j].x][point[i][j].y]=img_origin[i][j]-'0';
        }
    }

    for(i=0;i<2357;i++)
    {
        fscanf(fp,"%d",&add_rivise[i].x);
        fscanf(fp,"%d",&add_rivise[i].y);
    }
    fclose(fp);
    for(i=0;i<2357;i++)
    {
        add_rivise[i].x+=min[0];
        add_rivise[i].y+=min[1];
    }
    // for(i=0;i<2357;i++)
    // {
    //     printf("%3d",add_rivise[i].x);
    //     printf("%3d ",add_rivise[i].y);
    // }
    count=0;
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            if(2==img_bucket[i][j])
            {
//                if(i==6&&j==11)
//                {
//                    i=6;
//                }
                if(add_rivise[count].x<0) add_rivise[count].x=0;
                if(add_rivise[count].x>59) add_rivise[count].x=59;
                if(add_rivise[count].y<0) add_rivise[count].y=0;
                if(add_rivise[count].x>79) add_rivise[count].x=79;
                copy_Point(&OB_rivise[i][j],&add_rivise[count]);
                img_bucket[i][j]=img_origin[OB_rivise[i][j].x][OB_rivise[i][j].y]-'0';
                count++;
            }
        }
    }


    // count=0;
    // for(i=0;i<ROW;i++)
    //     for(j=0;j<COL;j++)
    //         if(2==img_bucket[i][j])
    //         {
    //             printf("%4d,",i);
    //             count++;
    //             if(0==count%10) printf("\n");
    //         }
//    for(i=0;i<ROW;i++)
//    {
//        for(j=0;j<COL;j++)
//        {
//            if(2==img_bucket[i][j])
//            {
//                printf("%4d,",i);
//                count++;
//                if(0==count%10) printf("\n");
// //                n=i-30;
// //                m=j-40;
// //                n1=30+round(n*(1-(k1-0.00001)*n*n-(k2-0.00007)*m*m))+min[0];
// //                m1=40+round(m*(1-(k1-0.00001)*n*n-(k2-0.00007)*m*m))+min[1];
// //                if(n1<0 || n1>=60 || m1<0 || m1>=80) img_bucket[i][j]=0;
// //                else
// //                    img_bucket[i][j]=img_origin[n1][m1]-'0';
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
    //printf("\n\n\n\n%d\n\n\n\n",bad);
    return 1;
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
            // if(-48==img_bucket[i][j])
            // {
            //     max[0]=i;
            //     max[1]=j;
            // }
            if(img_bucket[i][j]==0)
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

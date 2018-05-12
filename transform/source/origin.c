#include "include.h"


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
    printf("Read picture succeed!\n");
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

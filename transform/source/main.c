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

    read_flie("./data/511.txt",img_origin);    //��ȡͼƬ
    show_Img(img_origin);               //��ʾԭͼ
    get_B_Tran(img_origin,point);       //��ת����ϵ,����������������
    add_Max();                          //������������Ӧ��λ����

    init_B(img_bucket);                 //��ʼ�����ܾ���

    tran_O_B(img_origin,img_bucket);    //��ɾ����ת��

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




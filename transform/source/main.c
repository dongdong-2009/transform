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

//     read_flie("./data/511.txt",img_origin);    //��ȡͼƬ
//     show_Img(img_origin);               //��ʾԭͼ
//     get_B_Tran(img_origin,point);       //��ת����ϵ,����������������
//     add_Max();                          //������������Ӧ��λ����

//     init_B(img_bucket);                 //��ʼ�����ܾ���

//     tran_O_B(img_origin,img_bucket);    //��ɾ����ת��

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

    read_flie("./data/511.txt",img_origin);    //��ȡͼƬ
    show_Img(img_origin);               //��ʾԭͼ
    //get_B_Tran(img_origin,point);       //��ת����ϵ,����������������
    //add_Max();                          //������������Ӧ��λ����
    init_B(img_bucket);                 //��ʼ�����ܾ���
    tran_O_B(img_origin,img_bucket);    //��ɾ����ת��
    show_B();

    printf("\n%d %d %d %d",min[0],max[0],min[1],max[1]);
    getchar();

    return 1;
}




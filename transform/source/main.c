#include "include.h"


void copy_Point(Point *a,Point *b);

int main()
{
    int i=0;
    int j=0;

    read_flie("./data/511.txt",img_origin);    //��ȡͼƬ
    show_Img(img_origin);               //��ʾԭͼ
    get_B_Tran(img_origin,point);       //��ת����ϵ
    add_Max();
    init_B(img_bucket);                 //��ʼ�����ܾ���
    tran_O_B(img_origin,img_bucket);    //��ɾ����ת��
    //show_B();


    printf("\n%d %d %d %d",min[0],max[0],min[1],max[1]);
    getchar();

    return 1;
}


void copy_Point(Point *a,Point *b)
{
    (*a).x=(*b).x;
    (*a).y=(*b).y;
}
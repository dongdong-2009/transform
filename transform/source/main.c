#include "include.h"


int main()
{
    read_flie("./data/511.txt",img_origin);    //��ȡͼƬ
    show_Img(img_origin);               //��ʾԭͼ
    get_B_Tran(img_origin,point);       //��ת����ϵ,����������������
    add_Max();                          //������������Ӧ��λ����

    init_B(img_bucket);                 //��ʼ�����ܾ���
    if(img_origin[1][4]==49)
    {
        1+2;
    }
    tran_O_B(img_origin,img_bucket);    //��ɾ����ת��
    show_B();

    printf("\n%d %d %d %d",min[0],max[0],min[1],max[1]);
    getchar();

    return 1;
}




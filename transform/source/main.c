#include "include.h"



int main()
{
    int i=0;
    int j=0;
    int flag=0;

    read_flie("./data/511.txt",img_origin);    //��ȡͼƬ
    show_Img(img_origin);               //��ʾԭͼ
    //get_B_Tran(img_origin,point);       //��ת����ϵ,����������������
    //add_Max();                          //������������Ӧ��λ����
    init_B(img_bucket);                 //��ʼ�����ܾ���
    tran_O_B(img_origin,img_bucket);    //��ɾ����ת��
    //show_B();
    //tran_B_P();
    //show_P();
    init_P();
    tran_B_P();
    show_P();

    printf("\n%d %d %d %d %d",min[0],max[0],min[1],max[1],sss);
    getchar();

    return 1;
}




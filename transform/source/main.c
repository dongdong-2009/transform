#include "include.h"

int is_PT(int i,int j);

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
    for(i=0;i<175;i++)
    {
        flag=0;
        for(j=0;j<205;j++)
        {
            if(0==flag)
            {
                if(is_PT(i,j))
                {
                    P_T[i][0]=j-1;
                    flag++;
                }
            }
            else
            {
                if(!is_PT(i,j))
                {
                    P_T[i][1]=j;
                    flag++;
                    break;
                }
            }
        }
        if(flag==0)
        {
            P_T[i][0]=-1;
            P_T[i][1]=205;
        }
        else if(1==flag)
        {
            P_T[i][1]=205;
        }
    }
    printf("\n");
    for(i=0;i<175;i++)
    {
        printf("{%3d,%3d} ",P_T[i][0],P_T[i][1]);
        if(i<174) printf(",");
        printf("\n");
    }

    printf("\n%d %d %d %d",min[0],max[0],min[1],max[1]);
    getchar();

    return 1;
}

int is_PT(int i,int j)
{
    if(BP_rivise[i][j].x>=0 && BP_rivise[i][j].x<=66 && BP_rivise[i][j].y>=0 && BP_rivise[i][j].y<=88)
        return 1;
    else return 0;

}


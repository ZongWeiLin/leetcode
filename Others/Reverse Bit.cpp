#include <stdio.h>
#include <stdlib.h>

typedef unsigned long  uint32_t;

//���//
//�o�D�O�z�L�N�쥻���Ʀr�P1��and//
//�ݨC��bit�O�_��1�A�O���ܱN���઺�Ʀr���̫�@��A�z�LOR�ߦ�1//
//�j��̫�A�|�N��J�Ʀr�ѥ��ܥkshift�A����Ʀr�ѥk�ܥ�shift//
uint32_t reverseBits(uint32_t n) 
{

    uint32_t rev_num=0;
    
    for(int i=0;i<31;i++)
    {
        //�ݳ̫�@��O�_��1�A�O���ܱN����Ʀr�̫�@��ߦ�1//
        if(n&1)
            rev_num|=1;
        
        //��J�Ʀr�ѳ̧C���̰ܳ���Traversal�A�ҥH�ѥ����kshift//
        n>>=1;
        //�ѩ�O����Ʀr�A�ҥH�O�ѥk�ܥ�shift//
        rev_num<<=1;
    }
    
    //�̫�ݳѤU���̫�@��O�_��1//
    if(n&1)
        rev_num|=1;

    return rev_num;
}


int main(void)
{

    system("pause");
    return 0;
}
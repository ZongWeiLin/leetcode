#include <stdio.h>
#include <stdlib.h>

int hammingWeight(int n) 
{   
    int count=0;
    
    //�N�C�@��Ƴ��P1��and�A�p�G�̫ᵲ�G�O�u�A�N���e��Ƭ�1//
    //�C��J���Ƭ�1���줸�Acount�N�[1//
    while(n>0)
    {
        if(n&1)
            count++;
        //��e�줸��粒�A����U�@��i����//
        n>>=1;
    }

    return count;
}

int main(void)
{
    int a=0x008;

    int val=hammingWeight(a);

    printf("%d\n",val);

    system("pause");
    return 0;
}
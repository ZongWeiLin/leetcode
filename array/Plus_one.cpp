#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize)
{
    int *ret=(int*)malloc((digitsSize+1)*sizeof(int));
    int i;
    int value;
    //����̫�@�쪺�Ʀr�[1//
    digits[digitsSize-1]+=1;
    
    //�ѳ̫�@�쩹�e�ݡA�ݦ��j��9���N�]���A�ñN�e�@�쪺�Ʀr�[1//
    for(i=digitsSize-1;i>=0;i--)
    {
        if(digits[i]>9&&i!=0)//���F�קKunderflow�ҥH�o�̭n�]�mi!=0�ɡA�~���g�e�@�쪺��
        {
            digits[i]=0;
            digits[i-1]+=1;
        }
        else
            break;
    }
    
    //�̫�o�ӬO�P�_�̫e���O�_���i��//
    int j=0;
    if(digits[0]>9)
    {
            ret[0]=digits[0]/10;
            ret[1]=digits[0]%10;
            j+=2;
    }
    else
    {
        ret[0]=digits[0];
        j++;
    }

    //�ѩ�̰���ڭ̤w�g�B�z���F�A�᭱�u�ݭn��ѤU���Ʀr�h�i�Ө�l�}�C����m//
    i=1;
    while(i<digitsSize)
    {
        ret[j]=digits[i];
        i++;j++;
    }


    return ret;

}


int main(void)
{

    int arr[6]={9,9,9,9,8,9};

    int *ptr=plusOne(arr,6);

    for(int i=0;i<7;i++)
    {
        printf("%d\n",ptr[i]);
    }

    system("pause");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//�o��O�z�L��10���l�ƪ��覡�A�Ӷi��Ʀr����//
int reverse(int x)
{   
    int rev=0;
    int mod;
    while(x!=0)
    {
        //�ΨӧP�_�O�_��overflow��//
        if(rev>INT_MAX/10||rev<INT_MIN/10)
        return 0;
        
        //�ѩ�᭱�|��10�A�ҥH�boverflow��t�ɭn�T�{�Ӧ�ƪ��Ʀr�A�O�_�^�y��overflow//
        else if (rev==INT_MAX/10||rev==INT_MIN/10)
        {
            if(x%10>7||x%10<-8)
            return 0;    
        }
        
        
        mod=x%10;
        rev=rev*10+mod;
        x=x/10;
    }

    return rev;
}

int main(void)
{
    int val=-123;

    int rev=reverse(val);
    printf("%d\n",rev);
    system("pause");
    return 0;
}
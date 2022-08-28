#include <stdio.h>
#include <stdlib.h>

int rob(int* nums, int numsSize)
{
    //�ΨӦs�����n���Фl�ɯఽ���̤j��//
    int max[numsSize];
    int i;
    for(i=0;i<numsSize;i++)
    {
        switch(i)
        {
            //�]���u������Ĥ@���A�ҥH�u���Ĥ@���ఽ
            case 0:
                max[i]=nums[i];
                break;
            //�ѩ�n�j�ɰ��A�ҥH�u���Ĥ@���βĤG���Фl��//
            //�ҥH�N�n�ݭ�������h�e�N������//
            case 1:
                max[i]=nums[i]>max[i-1]?nums[i]:max[i-1];
                break;
            //�ѩ�n�j�ɰ��A�ҥH�ثe�o���n�����ܡA�u��ĥΤW�W�����̤j��//
            //�M��򨫨�n-1�����̤j�Ȥ���A�p�G�S������j���ܡA�N�N��o���S�����N�q//
            default:
                max[i]=(nums[i]+max[i-2])>max[i-1]?nums[i]+max[i-2]:max[i-1];
                break;
        }
    }
    
    return max[numsSize-1];
}

int main(void)
{
    int val[5]={2,7,9,3,1};
    int max=rob(val,5);

    printf("%d\n",max);
    
    system("pause");
    return 0;
}
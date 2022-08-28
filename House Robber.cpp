#include <stdio.h>
#include <stdlib.h>

int rob(int* nums, int numsSize)
{
    //用來存走到第n間房子時能偷的最大值//
    int max[numsSize];
    int i;
    for(i=0;i<numsSize;i++)
    {
        switch(i)
        {
            //因為只有走到第一間，所以只有第一間能偷
            case 0:
                max[i]=nums[i];
                break;
            //由於要隔棟偷，所以只能選第一間或第二間房子偷//
            //所以就要看哪間比較多前就偷哪間//
            case 1:
                max[i]=nums[i]>max[i-1]?nums[i]:max[i-1];
                break;
            //由於要隔棟偷，所以目前這間要偷的話，只能採用上上間的最大值//
            //然後跟走到n-1間的最大值比較，如果沒有比較大的話，就代表這間沒偷的意義//
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
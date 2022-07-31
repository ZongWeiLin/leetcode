#include <stdio.h>
#include <stdlib.h>

int arr[4]={11,15,2,7};

int* twoSum(int* nums, int numsSize, int target)
{
    int i,j;
    int *reslut=(int*)malloc(sizeof(int)*2); 
    for(i=0;i<numsSize;i++)
    {
        for(j=i+1;j<numsSize;j++)
        {
            if(target==nums[i]+nums[j])
            {
                reslut[0]=i;
                reslut[1]=j;
                return reslut;
            }
            
        }    
    }
    
    return reslut;
}


int main(void)
{
    int *ret;
    int *size_ret;
    ret=twoSum(arr,4,9);
    printf("[%d,%d]\n",ret[0],ret[1]);
    free(ret);
    system("pause");
    return 0;
}



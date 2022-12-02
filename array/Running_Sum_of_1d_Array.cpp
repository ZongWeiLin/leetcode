#include <stdio.h>
#include <stdlib.h>

int* runningSum(int* nums, int numsSize, int* returnSize)
{
    int *ret_arr=(int*)malloc(sizeof(int)*numsSize);

    ret_arr[0]=nums[0];

    for(int i=1;i<numsSize;i++)
    {
        ret_arr[i]=nums[i]+ret_arr[i-1];
    }

    *returnSize=numsSize;

    return ret_arr;
}


int main(void)
{

    system("pause");
    return 0;
}
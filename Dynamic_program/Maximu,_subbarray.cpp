#include <stdio.h>
#include <stdlib.h>

int maxSubArray(int* nums, int numsSize)
{
    int max=nums[0];
    int max_to_far=0;
    for(int i=0;i<numsSize;i++)
    {
        max_to_far+=nums[i];
        if(max_to_far>max)max=max_to_far;
        if(max_to_far<0)max_to_far=0;
    }

    return max;
}

int main(void)
{
    int arr[9]={-2,1,-3,4,-1,2,1,-5,4};

    int val=maxSubArray(arr,9);

    printf("%d\n",val);
    
    system("pause");
    return 0;
}
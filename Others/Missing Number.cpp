#include <stdio.h>
#include <stdlib.h>

int missingNumber(int* nums, int numsSize)
{
    
    int sum=0;
    for(int i=0;i<=numsSize;i++)
    {
        sum+=i;
    }
    
    for (int i = 0; i < numsSize; i++)
    {
        sum-=nums[i];
    }
    
    return sum;
}

int main(void)
{
    int arr[5]={1,3,4,5,0};
    int val=missingNumber(arr,5);

    printf("%d\n",val);

    system("pause");
    return 0;
}
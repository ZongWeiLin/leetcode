#include <stdio.h>
#include <stdlib.h>
#define swap(x,y){int tmp;tmp=x;x=y;y=tmp;}

void moveZeroes(int* nums, int numsSize)
{
    int last=0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]!=0)
        {
            swap(nums[i],nums[last]);
            last++;
        }
    }   
}

int main(void)
{
    int arr[5]={0,1,0,3,12};

    moveZeroes(arr,5);

    for(int i=0;i<5;i++)
    {
        printf("%d\n",arr[i]);
    }

    system("pause");
    return 0;
}
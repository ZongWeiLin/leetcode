#include <stdio.h>
#include <stdlib.h>

#define SWAP(x,y) {int t;t=x;x=y;y=t;}

//先加index在比較的//
void quik_sort(int *nums,int left, int right)
{   
    if(left<right)
    {
        int mid=(left+right)/2;
        int pivot=nums[mid];

        //由於會先加和減index後，才進行比較//
        //所以這裡i會先-1，j會先+1//
        int i=left-1,j=right+1;
        
        while(i<j)
        {
            while(nums[++i]<pivot);
            
            while(nums[--j]>pivot);
            
            if(i<j)
            SWAP(nums[i],nums[j]);
        }

        quik_sort(nums,left,j);
        quik_sort(nums,j+1,right);
    }


}

int arrayPairSum(int* nums, int numsSize)
{
    //先把進來的陣列做quick sort//
    //之後再把鄰近兩個做比較找最小值//
    quik_sort(nums,0,numsSize-1);
    //紀錄最大值總和//
    int sum=0;
    //用來記錄兩兩陣列的最小值//
    int min;


    for(int i=1;i<numsSize;i+=2)
    {   
        if(nums[i-1]<nums[i])
            min=nums[i-1];
        else
            min=nums[i];
        
        sum+=min;
    }

    return sum;
}

int main(void)
{
    int arr[4]={1,4,3,2};
    int max=arrayPairSum(arr,4);

    printf("%d\n",max);

    system("pause");
    return 0;
}
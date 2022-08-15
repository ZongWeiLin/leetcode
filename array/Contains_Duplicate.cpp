#include <stdio.h>
#include <stdlib.h>
#define swap(x,y){int tmp;tmp=x;x=y;y=tmp;}

void quick_sort(int *arr,int left,int right)
{
    if(left<right)
    {
        int mid=(left+right)/2;
        int pivot=arr[mid];

        int i=left-1;
        int j=right+1;
        while (i<j)
        {
            while(arr[++i]<pivot);

            while(arr[--j]>pivot);

            if(i<j)
            swap(arr[i],arr[j]);
        }

        
        quick_sort(arr,left,j);
        quick_sort(arr,j+1,right);
    }
}

//method1//
//先排序好在看有沒有重複的//
bool containsDuplicate(int* nums, int numsSize)
{
    quick_sort(nums,0,numsSize-1);
    for (int i=1; i <numsSize; i++)
    {
        if(nums[i-1]==nums[i])
        return true;
    }
    
    return false;
}


//method2//
//用hash的方式//
// bool containsDuplicate(int* nums, int numsSize)
// {
//    int max=0;
//    for (int i=0; i <numsSize; i++)
//    {
//         if(nums[i]>max)max=nums[i];
//    }

//    int *arr=(int *)calloc(max,sizeof(int));

//    for(int i=0;i<numsSize;i++)
//    {
//         arr[nums[i]]+=1;
//    }

//    for (int i = 0; i <max; i++)
//    {
//         if(arr[i]>1)return true;
//    }
   
//    return false;
// }

int main(void)
{
    int arr[5]={1,3,2,5,1};

    int val=containsDuplicate(arr,5);

    printf("%d\n",val); 
    system("pause");
    return 0;
}
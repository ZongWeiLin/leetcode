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

int* findDisappearedNumbers(int* nums, int numsSize)
{
    quik_sort(nums,0,numsSize-1);
    int count=0;
    int *ptr=(int*)malloc(count*sizeof(int));
    int i=0,k=0,j=0;
    int max=numsSize+1;

    int lastindex=0;
    for(int i=1;i<numsSize;i++)
    {
        if(nums[i]!=nums[lastindex])
        {
            nums[lastindex+1]=nums[i];
            lastindex++;
        }
    }

    for(i=1;i<max;i++)
    {
        if(nums[j]==i)
            j++;
        else
        {
            count++;
            ptr=(int*)realloc(ptr,count*sizeof(int));
            ptr[k]=i;
            k++;
        }
    }

    return ptr;
}



int main(void)
{
    int arr1[8]={4,3,2,7,8,2,3,1};

    int *ptr=findDisappearedNumbers(arr1,8);

    for(int i=0;i<2;i++)
    {
        printf("%d\n",ptr[i]);
    }
    system("pause");
    return 0;
}
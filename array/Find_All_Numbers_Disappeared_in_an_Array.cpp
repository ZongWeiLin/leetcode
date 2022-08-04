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

//method1//
//先把陣列排序好之後，之後把重複的element移除並將剩餘的往前擺//
//最後在由1至陣列大小n找陣列裡面沒有出現的數字//

// int* findDisappearedNumbers(int* nums, int numsSize)
// {
//     quik_sort(nums,0,numsSize-1);
//     int count=0;
//     int *ptr=(int*)malloc(count*sizeof(int));
//     int i=0,k=0,j=0;
//     int max=numsSize+1;

//     int lastindex=0;
//     for(int i=1;i<numsSize;i++)
//     {
//         if(nums[i]!=nums[lastindex])
//         {
//             nums[lastindex+1]=nums[i];
//             lastindex++;
//         }
//     }

//     for(i=1;i<max;i++)
//     {
//         if(nums[j]==i)
//             j++;
//         else
//         {
//             count++;
//             ptr=(int*)realloc(ptr,count*sizeof(int));
//             ptr[k]=i;
//             k++;
//         }
//     }

//     return ptr;
// }

int* findDisappearedNumbers(int* nums, int numsSize)
{
    
    int *ptr=(int*)malloc(numsSize*sizeof(int));
    int *record_arr=(int*)calloc(numsSize+1,sizeof(int));
    //用來記錄array裡面有哪些數字，有出現的對應的index值+1//
    
    int index;
    for(int i=0;i<numsSize;i++)
    {
        index=nums[i];
        record_arr[index]+=1;
    }

    int k=0;
    
    for(int i=1;i<(numsSize+1);i++)
    {
        if(record_arr[i]==0)
        {
            ptr[k]=i;
            k++;
        }    
    }
    
    free(record_arr);
    
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
#include <stdio.h>
#include <stdlib.h>

#define SWAP(x,y) {int t;t=x;x=y;y=t;}

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

// int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size,int *returnSize)
// {
//     int i,j,k;
//     int counter=0;
//     int previous;
//     int *arr;
//     returnSize=(int*)calloc(nums1Size,sizeof(int));
//     k=0;
//     for(i=0;i<nums1Size;i++)
//     {
//         for(j=0;j<nums2Size;j++)
//         {
//             if(nums1[i]==nums2[j]&&nums2[j]!=previous)
//             {
//                 returnSize[k]=nums1[i];
//                 previous=nums1[i];
//                 k++;
//             }
//         }
//     }
//     arr=returnSize;

//     return arr;
// }

void quickSort(int number[], int left, int right) { 
    if(left < right) { 
        int s = number[(left+right)/2]; 
        int i = left - 1; 
        int j = right + 1; 

        while(i<j) { 
            while(number[++i] < s) ;  // 向右找 
            while(number[--j] > s) ;  // 向左找 
            if(i >= j) 
                break; 
            SWAP(number[i], number[j]); 
        } 

        quickSort(number, left, i-1);   // 對左邊進行遞迴 
        quickSort(number, j+1, right);  // 對右邊進行遞迴 
    } 
} 

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size,int *returnSize)
{
    quickSort(nums1,0,nums1Size-1);
    quickSort(nums2,0,nums2Size-1);

    int LastIndex1=0,LastIndex2=0;
    for(int i=1;i<nums1Size;i++)
    {
        if(nums1[LastIndex1]!=nums1[i])
        {
            nums1[LastIndex1+1]=nums1[i];
            LastIndex1++;
        }
    }

    for(int i=1;i<nums2Size;i++)
    {
        if(nums2[LastIndex2]!=nums2[i])
        {
            nums2[LastIndex2+1]=nums2[i];
            LastIndex2++;
        }
    }

    int *ptr;
    if(LastIndex1>LastIndex2)ptr=(int *)calloc((LastIndex2+1),sizeof(int*));
    else ptr=(int *)calloc((LastIndex1+1),sizeof(int*));

    int i=0,j=0,k=0;
    while (i<(LastIndex1+1)&&j<(LastIndex2+1))
    {
        if(nums1[i]==nums2[j])
        {
            ptr[k]=nums1[i];
            k++;i++;j++;
        }
        else if(nums1[i]<nums2[j])
        {
            i++;
        }
        else
             j++;
    }

    
    return ptr;
}



int main(void)
{
    int arr1[4]={1,4,2,1};
    int arr2[2]={4,2};
    int *ptr;
    int *returnsize;

    ptr=intersection(arr1,4,arr2,2,returnsize);

    for(int i=0;i<4;i++)
    printf("%d",arr1[i]);

    printf("\n");

    for(int i=0;i<2;i++)
    printf("%d",arr2[i]);

    printf("\n");

    for(int i=0;i<2;i++)
    printf("%d",ptr[i]);

    printf("\n");

    system("pause");
    return 0;
}
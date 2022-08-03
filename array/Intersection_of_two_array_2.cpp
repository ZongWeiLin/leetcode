#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y) {int t=x;x=y;y=t;}

void quick_sort (int *arr,int left,int right)
{
    if(left<right)
    {
        int i=left-1;
        int j;
        for(j=left;j<right;j++)
        {
            if(arr[j]<arr[right])
            {
                i++;
                SWAP(arr[i],arr[j]);
            }
        }
        i++;
        SWAP(arr[i],arr[right]);
        quick_sort(arr,left,i-1);
        quick_sort(arr,i+1,right);
    }
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    //先做排序//
    quick_sort(nums1,0,nums1Size-1);
    quick_sort(nums2,0,nums2Size-1);   

    int i=0,j=0,k=0;
    int size=0;
    int *ptr=(int*)calloc(nums1Size,sizeof(int*));

    while(i<nums1Size&&j<nums2Size)
    {
        if(nums1[i]==nums2[j])
        {
            ptr[k]=nums1[i];
            i++;j++;k++;
        }
        else if(nums1[i]<nums2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return ptr;
}

int main(void)
{
    int arr1[3]={4,9,4};
    int arr2[5]={9,4,9,8,4};
    int *ptr;
    ptr=intersect(arr1,3,arr2,5);

    for(int i=0;i<3;i++)
        printf("%d",arr1[i]);
    printf("\n");
     for(int i=0;i<3;i++)
        printf("%d",ptr[i]);
    printf("\n");
    system("pause");
    return 0;
}
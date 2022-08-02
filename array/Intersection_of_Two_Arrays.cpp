#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size,int *returnSize)
{
    int i,j,k;
    int counter=0;
    int previous;
    int *arr;
    returnSize=(int*)calloc(nums1Size,sizeof(int));
    k=0;
    for(i=0;i<nums1Size;i++)
    {
        for(j=0;j<nums2Size;j++)
        {
            if(nums1[i]==nums2[j]&&nums2[j]!=previous)
            {
                returnSize[k]=nums1[i];
                previous=nums1[i];
                k++;
            }
        }
    }
    arr=returnSize;

    return arr;
}

int main(void)
{
    int arr1[4]={1,2,2,1};
    int arr2[2]={2,2};
    int *ptr;

    qsort(arr1,4,sizeof(int),compare);
    for(int i=0;i<4;i++)
        printf("%d\n",arr1[i]);

    system("pause");
    return 0;
}
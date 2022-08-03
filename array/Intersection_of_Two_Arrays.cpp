#include <stdio.h>
#include <stdlib.h>

#define SWAP(x,y) {int t;t=x;x=y;y=t;}

void insertion_sort(int *num,int numSize)
{
    int index;//用來存數值最小的index
    for(int i=0;i<numSize;i++)
    {
        for(int j=i;j<numSize;j++)
        {
            if(i==j)index=i;//初始化讓index指到最左邊

            if(num[j]<num[index])index=j;//有比較大的就取代
        }
        SWAP(num[i],num[index]);
    }

}



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
    //先將進來的array做排序//
    //這邊使用快速排序//
    quickSort(nums1,0,nums1Size-1);
    quickSort(nums2,0,nums2Size-1);

    //移除array1和2複數值的element，並將其由小至大進行排序//
    //lastindex是紀錄非重複的數值有幾個//
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

    //比較兩個array Last Index//
    //根據比較小的Last Index索取記憶體空間//
    int *ptr;
    if(LastIndex1>LastIndex2)ptr=(int *)calloc((LastIndex2+1),sizeof(int*));
    else ptr=(int *)calloc((LastIndex1+1),sizeof(int*));

    //從頭開始找兩個array中有重複的部分//
    //兩個array都是由小至大進行排序//
    //i是用來traversal array1//
    //j是用來traversal array2//
    //k是用來紀錄輸出array的index//
    int i=0,j=0,k=0;
    while (i<(LastIndex1+1)&&j<(LastIndex2+1))
    {
        if(nums1[i]==nums2[j])//兩個array有相同的數值，就把它存到要回傳的array
        {
            ptr[k]=nums1[i];
            k++;i++;j++;//兩邊都往下找，k指向下一個存取點
        }
        else if(nums1[i]<nums2[j])
        {
            i++;//如果array 1的值小於array 2代表，array 1往後移找看看更大的
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
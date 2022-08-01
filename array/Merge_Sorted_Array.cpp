#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    //從尾巴開始比大小//
    int i=m-1,j=n-1,k=nums1Size-1;
    
    //當兩個array有其中一個走到底時退出//
    while(i>=0&&j>=0)
    {
        
        if(nums2[j]>nums1[i])
        {
            nums1[k]=nums2[j];
            k--;j--;
        }
        else
        {
          nums1[k]=nums1[i];
          k--;i--;
        }
    }

    //如果array2還有剩下，則把array2放上去剩下沒放的地方//
    //如果是array1由於原本就照順序排好了，所以就不用處理//
    while(k>=0&&j>=0)
    {
            nums1[k]=nums2[j];
            k--;j--;
    }
}

int main(void)
{
    int nums1[6]={1,5,6,0,0,0};
    int nums2[3]={1,2,3};
    merge(nums1,6,3,nums2,3,3);

    for (int i = 0; i <6; i++)
    {
        printf("%d\n",nums1[i]);
    }
        
    

    system("pause");
    return 0;
}
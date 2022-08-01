#include <stdio.h>
#include <stdlib.h>

//method1//
// int removeDuplicates(int* nums, int numsSize)
// {
    
//     if(numsSize==1)
//         return 1;
//     else if(numsSize==0)
//         return 0;

//     int i=0,previous,j;
//     for(i=0;i<numsSize;i++)
//     {
//         if(i!=0)
//         {
//             if(nums[i]==previous)
//                 nums[i]=1234;
//             else
//                 previous=nums[i];
//         }
//         else
//             previous=nums[i];
//     }

//     //把1234的部分往後平移//
//     j=0;//紀錄當前數值與前一個數值之間有幾個1234//
//     i=0;//紀錄當前arr移動到的位子
//     while (i<numsSize)
//     {
//         if(nums[i]==1234)
//         {
//           j++;
//         }

//         else
//         {
//           if(j!=0)
//           {
//             nums[i-j]=nums[i];
//             nums[i]=1234;
//             i=i-j;
//             j=0;
//           }
//         }
//         i++;
//     }

//     i=0;//重置counter//
//     //算除了1234以外的數字有幾個//
//     for(i=0;i<numsSize&&nums[i]!=1234;i++);
  
//     return i;
// }

//method2//
int removeDuplicates(int* nums, int numsSize)
{
    int lastIndex = 0;

    for (int i = 1; i < numsSize; i += 1)
    {
        //與前一個index數值比較//
        //如果不相同的話就將它，排在它後面//
        if (nums[lastIndex] != nums[i])
        {
            nums[lastIndex + 1] = nums[i];
            lastIndex += 1;
        }
    }

    return lastIndex + 1;
}

int main(void)
{
    int arr[8]={1,2,3,4,5,5,6,6};

    int nums=removeDuplicates(arr,8);

    for(int i=0;i<8;i++)
    {
        printf("%d\n",arr[i]);
    }
    printf("arr nums:%d\n",nums);

    system("pause");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>


//方法1//
//比較最初的方向與當前的方向//
//如果不同就代表不是Monotonic//
// bool isMonotonic(int* nums, int numsSize)
// {
//     if(numsSize<=1)
//         return true;


//     //mono_flag是用來存最開始的方向//
//     int mono_flag;
//     if (nums[0]<nums[1])mono_flag=1;//單調遞增
//     else if(nums[0]==nums[1])mono_flag=0;//如果是0就代表還沒辦法判斷是遞增還是遞減
//     else mono_flag=-1;//單調遞減
    
//     int state;//代表目前數字的方向

//     for(int i=1;i<numsSize;i++)
//     {
//         if(nums[i-1]<nums[i])
//         {
//             if(mono_flag==0)
//             mono_flag=1;
//             state=1;
//         }
//         else if(nums[i-1]==nums[i])
//             state=mono_flag;
//         else
//         {
//             if(mono_flag==0)
//             mono_flag=-1;
//             state=-1;
//         }
            
//         if(state!=mono_flag)
//             return false;
//     }

//     return true;
    
// }

//方法2//
//先預設兩個方向都是True//
bool isMonotonic(int* nums, int numsSize)
{
    bool in = true;//代表遞增
    bool de = true;//代表遞減
    for (int i = 0; i < numsSize - 1; i++){
        if (nums[i] > nums[i+1]) in = false;
        if (nums[i] < nums[i+1]) de = false;
    }
    return in || de; //如果是單調函數，裡面會有其中一個是True。
    
}

int main(void)
{
    int arr[1]={1};

    int val=isMonotonic(arr,1);

    printf("%d\n",val);
    system("pause");
    return 0;
}
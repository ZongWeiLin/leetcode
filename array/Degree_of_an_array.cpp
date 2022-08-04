#include <stdio.h>
#include <stdlib.h>

//紀錄arr資訊的結構//
struct arr_inform
{
    /* data */
    int count;
    int first;
    int length;
};


int findShortestSubArray(int* nums, int numsSize)
{
    
    //找array裡面最大的值//
    //根據這個值來開陣列//
    int max=0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]>max)
            max=nums[i];
    }

    //開一個struct的array，來記錄陣列內各個數字出現頻率//
    //下面這個是用來記錄各個數字出現次數,最先出現位置和最後出現位置//
    struct arr_inform *arr2=(struct arr_inform*)calloc(max+1,sizeof(struct arr_inform));
    int index;
    for(int i=0;i<numsSize;i++)
    {
        index=nums[i];
        arr2[index].count+=1;
        if(arr2[index].first==0)arr2[index].first=i+1;
        arr2[index].length=i+1-arr2[index].first;
    }

    int most_freq_num=0;
    int most_freq_length=0;

    //開始找出現最多的數字，並記錄它前後的長度差//
    for(int i=0;i<max+1;i++)
    {
        if(arr2[i].count>most_freq_num)
        {
                most_freq_num=arr2[i].count;
                most_freq_length=arr2[i].length;
        }
        //如果出現次數相同的話，那就看哪個長度差比較短//
        else if(arr2[i].count==most_freq_num)
        {
            if(arr2[i].length<most_freq_length)
                most_freq_length=arr2[i].length;
        }
    }

    //最後輸出的會是，出現次數最多長度差最短的//
    return most_freq_length+1;
}

int main(void)
{
    int arr[2]={0,0};

    int value=findShortestSubArray(arr,2);

    printf("%d\n",value);
    system("pause");
    return 0;
}
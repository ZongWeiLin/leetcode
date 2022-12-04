#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void insertion_sort(int *arr,int len)
{
    for(int i=1;i<len;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(arr[j-1]>arr[j])
                swap(&arr[j],&arr[j-1]);
            else
                break;
        }
    }
}


void max_heap(int *arr,int mid,int len)
{
    int left=mid*2+1;
    int right=mid*2+2;
    int largest=mid;

    if(left<len&&arr[mid]<arr[left])
        largest=left;
        
    if(right<len&&arr[largest]<arr[right])
        largest=right;

    if(largest!=mid)
    {
        swap(&arr[largest],&arr[mid]);
        max_heap(arr,largest,len);
    }
}

void build_heap(int *arr,int mid,int len)
{
    for (int i=mid-1;i>=0; i--)
    {
        max_heap(arr,i,len);
    }
}

void heap_sort(int *arr,int len)
{
    int mid=len/2;
    int i;
    build_heap(arr,mid,len);

    for(i=len-1;i>=0;i--)
    {
        //跟最後的element交換//
        swap(&arr[0],&arr[i]);
        //把最後一個元素斷開，之後reheap//
        max_heap(arr,0,i);
    }

}


int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    
    //先將陣列排序好//
    //這邊用heap sort是因為quick sort會導致heapoverflow//
    heap_sort(nums,numsSize);

    int total=64;//二維陣列行的初始值，這邊給64是因為如果一直realloc會導致時間超過
    *returnSize=0;
    int counter=0;

    *returnColumnSizes=(int*)malloc(sizeof(int)*total);//紀錄每一行的column size
    int **ret_arr=(int**)malloc(sizeof(int*)*total);
    
    int i,j,k;
    int target;
    int sum;

    for(i=0;i<numsSize-2;i++)
    {
        j=i+1,k=numsSize-1;
        target=-nums[i];//把最左邊的數字，乘上負號就是我們要找的值
        
        //如果最左邊的大於0，怎麼加也不會是0，所以可以停掉//
        //然後最左邊三個元素相加大於0也是可以直接停
        if(nums[i]>0||(nums[i]+nums[i+1]+nums[i+2])>0)
                break;
        
        if(i>0&&nums[i]==nums[i-1])//如果左指標數字跟前一個一樣，不用再走一遍，因為前面已經走過了
            continue;
        
        while(j<k)
        {
            sum=nums[j]+nums[k];//計算中間、右邊指的數子總和
            if(sum==target)
            {                
                //如果與目標數字相同的話，就要3個int大小的array 
                (*returnColumnSizes)[counter]=3;

                //把左中右的數值進行紀錄
                ret_arr[counter]=(int*)malloc(sizeof(int)*3);
                ret_arr[counter][0]=nums[i];
                ret_arr[counter][1]=nums[j++];
                ret_arr[counter][2]=nums[k--];
                
                (*returnSize)++;//回傳的row size也要+
                counter++;
                
                while(j<k&&nums[j-1]==nums[j])j++;//移除掉重複的部分(左往右)
                while(j<k&&nums[k]==nums[k+1])k--;//也是移除掉重複的部分(右往左)
            
                //如果row的大小大於之前預設則擴大
                 if(counter>=total)
                {
                    total*=2;
                    *returnColumnSizes=(int*)realloc(*returnColumnSizes,sizeof(int)*total);
                    ret_arr=(int**)realloc(ret_arr,sizeof(int*)*(total));
                }
            }
            else if(sum<target)
                j++;
            else
                k--;
            
        }
    }

    return ret_arr;
}

void print_arr(int *arr,int len)
{
    for(int i=0;i<len;i++)
    {
        printf("[%d] ",arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int arr[5]={1,3,4,2,3};
    print_arr(arr,5);



    system("pause");
    return 0;
}
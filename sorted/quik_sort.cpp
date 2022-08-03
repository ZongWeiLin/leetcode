#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y) {int t;t=x;x=y;y=t;}


//先比較的在加index的//
// void quik_sort(int *nums,int left, int right)
// {   
//     if(left<right)
//     {
//         int mid=(left+right)/2;
//         int pivot=nums[mid];
//         int i=left,j=right;
        
//         while(i<j)
//         {
//             //i從前面開始traversal//
//             while(nums[i]<=pivot)
//             {
//                 i++;
//             }
            
//             //j從後面開始traversal//
//             while(nums[j]>pivot)
//             {
//                 j--;
//             }
            
//             if(i<j)
//             SWAP(nums[i],nums[j]);
//         }
        
//         //最後把j指到的位置跟目前設的中間值替換//
//         SWAP(nums[mid],nums[j]);

//         quik_sort(nums,left,j-1);
//         quik_sort(nums,j+1,right);
//     }


// }


//先加index在比較的//
// void quik_sort(int *nums,int left, int right)
// {   
//     if(left<right)
//     {
//         int mid=(left+right)/2;
//         int pivot=nums[mid];

//         //由於會先加和減index後，才進行比較//
//         //所以這裡i會先-1，j會先+1//
//         int i=left-1,j=right+1;
        
//         while(i<j)
//         {
//             while(nums[++i]<pivot);
            
//             while(nums[--j]>pivot);
            
//             if(i<j)
//             SWAP(nums[i],nums[j]);
//         }

//         quik_sort(nums,left,j);
//         quik_sort(nums,j+1,right);
//     }


// }


//基準值在左邊//
void quik_sort(int *nums,int left, int right)
{   
    if(left<right)
    {
        int pivot=nums[left];

        //由於會先加和減index後，才進行比較//
        //所以這裡i會先-1，j會先+1//
        int i=left,j=right+1;
        
        while(i<j)
        {
            while(nums[++i]<pivot);
            
            while(nums[--j]>pivot);
            
            if(i<j)
            SWAP(nums[i],nums[j]);
        }
        SWAP(nums[left],nums[j]);

        quik_sort(nums,left,j-1);
        quik_sort(nums,j+1,right);
    }


}



int main(void)
{
    int arr1[5]={5,1,4,1,3};
    quik_sort(arr1,0,4);

    for(int i=0;i<5;i++)
    printf("arr[%d]:%d\n",i,arr1[i]);

    system("pause");
    return 0;
}
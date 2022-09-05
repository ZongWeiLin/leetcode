#include <stdio.h>
#include <stdlib.h>
#define swap_m(x,y){int t;t=x;x=y;y=t;}

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
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
        swap_m(arr[largest],arr[mid]);
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

// void heap_sort(int *arr,int len)
// {
//     int mid;
//     int i;

//     for(i=len-1;i>=0;i--)
//     {
//         mid=(i+1)/2;
//         //做max heapify 找出最大值放在root(arr[0])//
//         build_heap(arr,mid,i+1);
//         //跟最後的element交換//
//         swap(&arr[0],&arr[i]);
//     }
// }

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


int main(void)
{
    int arr[5]={4,3,2,6,5};

    heap_sort(arr,5);

    for (int i = 0; i <5; i++)
    {
        printf("%d",arr[i]);
    }    
    
    printf("\n"); 


    system("pause");
    return 0;
}
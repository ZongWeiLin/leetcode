#include <stdio.h>
#include <stdlib.h>


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
        swap(&arr[largest],&arr[mid]);
        max_heap(arr,largest,len);
    }
}


int main(void)
{
    int arr[5]={4,3,2,6,5};

    int mid=5/2;

    for (int i=mid-1;i>=0; i--)
    {
        max_heap(arr,i,5);
    }
    
    max_heap(arr,0,5);

    for (int i = 0; i <5; i++)
    {
        printf("%d",arr[i]);
    }    
    
    printf("\n"); 


    system("pause");
    return 0;
}
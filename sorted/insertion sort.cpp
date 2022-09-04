#include <stdio.h>
#include <stdlib.h>
#define swap(x,y){int t;t=x;x=y;y=t;}


void insertion_sort(int *arr,int len)
{
    int i,j,key;
    for(i=1;i<len;i++)
    {
        j=i-1;

        while(j>=0&&arr[j]>arr[j+1])
        {
            swap(arr[j],arr[j+1]);
            j--;
        }
    }
}

int main(void)
{
    int arr[4]={3,2,4,1};
    insertion_sort(arr,4);
    for (int i = 0; i < 4; i++)
    {
        printf("%d",arr[i]);
    }

    printf("\n");
    system("pause");
    return 0;
}
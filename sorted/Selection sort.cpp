#include <stdio.h>
#include <stdlib.h>
#define swap(x,y){int t;t=x;x=y;y=t;}

void selection_sort(int *arr,int len)
{
    int min_index=0;
    for(int i=0;i<len;i++)
    {
        for(int j=i;j<len;j++)
        {
            if(j==i)min_index=i;
            if(arr[j]<arr[min_index])
            min_index=j;    
        }

        swap(arr[i],arr[min_index]);
    }
}

int main(void)
{
    int arr[4]={3,2,1,4};

    selection_sort(arr,4);

    for(int i=0;i<4;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}
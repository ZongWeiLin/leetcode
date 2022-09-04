#include <stdio.h>
#include <stdlib.h>

void merge(int *arr,int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    int i,j,k;

    //存取基準點左邊資料//
    for (i =0; i <n1; i++)
    {
        L[i]=arr[l+i];
    }

    //存基準點右邊的資料//
    for (j=0 ; j<n2; j++)
    {
        R[j]=arr[m+1+j];
    }

    k=l;
    i=0;j=0;
    
    //當左邊或者右邊陣列走完時，跳出迴圈//
    while (i<n1&&j<n2)
    {
        //比較基準點左邊和右邊的陣列，看哪個值比較小//
        //放到排序好的陣列//
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }

        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    
    //把剩下的放到後面去//
    while (i<n1)
    {
        arr[k]=L[i];
        i++;k++;
    }

    while (j<n2)
    {
        arr[k]=R[j];
        j++;k++;
    }
    
}


void merge_sort(int *arr,int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);

        merge(arr,l,m,r);
    }
}

int main(void)
{   
    int arr[7]={3,4,1,2,1,2,3};
    merge_sort(arr,0,6);

    for(int i=0;i<7;i++)
    {
        printf("%d",arr[i]);
    }

    printf("\n");
    system("pause");
    return 0;
}
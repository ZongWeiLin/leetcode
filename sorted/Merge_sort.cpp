#include <stdio.h>
#include <stdlib.h>

void merge(int *arr,int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    int i,j,k;

    //�s������I������//
    for (i =0; i <n1; i++)
    {
        L[i]=arr[l+i];
    }

    //�s����I�k�䪺���//
    for (j=0 ; j<n2; j++)
    {
        R[j]=arr[m+1+j];
    }

    k=l;
    i=0;j=0;
    
    //����Ϊ̥k��}�C�����ɡA���X�j��//
    while (i<n1&&j<n2)
    {
        //�������I����M�k�䪺�}�C�A�ݭ��ӭȤ���p//
        //���ƧǦn���}�C//
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
    
    //��ѤU�����᭱�h//
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
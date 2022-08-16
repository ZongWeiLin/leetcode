#include <stdio.h>
#include <stdlib.h>
#define  swap(x,y){int tmp;tmp=x;x=y;y=tmp;}


//以斜對角線的方式，去做array旋轉//
void rotate(int* matrix[], int matrixSize, int* matrixColSize)
{   
    int n=matrixSize;
    //以右上至左下之對角線為基準軸，將基準軸左右數字做交換//
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            swap(matrix[i][j],matrix[n-j-1][n-i-1]);
        }
    }

    //以二微陣列中間那排row為x軸，進行上下翻轉//
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n;j++)
        {
            swap(matrix[i][j],matrix[n-i-1][j]);
        }
    }

}

//以斜對角線的方式，去做array旋轉//
void rotate_left(int* matrix[], int matrixSize, int* matrixColSize)
{   
    int n=matrixSize;
    //以右上至左下之對角線為基準軸，將基準軸左右數字做交換//
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            swap(matrix[i][j],matrix[n-j-1][n-i-1]);
        }
    }

    //以二微陣列中間那排column為y軸，進行前後翻轉//
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n;j++)
        {
            swap(matrix[j][i],matrix[j][n-i-1]);
        }
    }

}


int main(void)
{
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int *p[3]={arr[0],arr[1],arr[2]};
    int *ptr;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        printf("%d",arr[i][j]);

        printf("\n");
    }

    printf("\n");

    rotate_left(p,3,ptr);

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        printf("%d",arr[i][j]);

        printf("\n");
    }

    printf("\n");
    system("pause");
    return 0;
}
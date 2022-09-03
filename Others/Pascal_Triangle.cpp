#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows)
{
    //根據三角形有幾層，決定二維陣列有幾層row//
    int **arr=(int**)malloc(sizeof(int*)*numRows);

    // *returnSize=numRows;
    // *returnColumnSizes=(int*)malloc(sizeof(int*)*numRows);
    //三角形每個row大小，由上至下每層遞增1//
    for(int i=0;i<numRows;i++)
    {   
        arr[i]=(int*)malloc(sizeof(int)*(i+1));
        // (*returnColumnSizes)[i]=i+1;

        //每個row的頭尾都設1//
        arr[i][0]=1;arr[i][i]=1;
        
        for(int j=1;j<i;j++)
        {
            //當前數字為上一個row這個col+上一個row前一個col所構成
            if(i>0)
            arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
        }

    }

    return arr;
}

int main(void)
{
    int **arr=generate(5);

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<=i;j++)
        {
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }

    system("pause");
    return 0;
}
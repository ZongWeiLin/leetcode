#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows)
{
    //�ھڤT���Φ��X�h�A�M�w�G���}�C���X�hrow//
    int **arr=(int**)malloc(sizeof(int*)*numRows);

    // *returnSize=numRows;
    // *returnColumnSizes=(int*)malloc(sizeof(int*)*numRows);
    //�T���ΨC��row�j�p�A�ѤW�ܤU�C�h���W1//
    for(int i=0;i<numRows;i++)
    {   
        arr[i]=(int*)malloc(sizeof(int)*(i+1));
        // (*returnColumnSizes)[i]=i+1;

        //�C��row���Y�����]1//
        arr[i][0]=1;arr[i][i]=1;
        
        for(int j=1;j<i;j++)
        {
            //��e�Ʀr���W�@��row�o��col+�W�@��row�e�@��col�Һc��
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
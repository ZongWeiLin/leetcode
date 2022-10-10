#include <stdio.h>
#include <stdlib.h>
#define swap(x,y){int t;t=x;x=y;y=t;}


void duplicateZeros(int* arr, int arrSize)
{
    int buf[arrSize];
    int i,j=0;
    
    for(i=0;i<arrSize&&j<arrSize;i++)
    {
        buf[j]=arr[i];//把arr的數值紀錄到buf
        
        if(arr[i]==0)//出現0的話buf要重複0的部分
        {
            j++;//往右移一格，寫入0
            if(j==arrSize)
            break;
            buf[j]=0;
        }
       
        j++;//移至下一個寫入點
    }
    
    for(i=0;i<arrSize;i++)
    {
        arr[i]=buf[i];
    }

}


int main(void)
{
    
    system("pause");
    return 0;
}
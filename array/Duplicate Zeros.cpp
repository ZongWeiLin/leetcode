#include <stdio.h>
#include <stdlib.h>
#define swap(x,y){int t;t=x;x=y;y=t;}


void duplicateZeros(int* arr, int arrSize)
{
    int buf[arrSize];
    int i,j=0;
    
    for(i=0;i<arrSize&&j<arrSize;i++)
    {
        buf[j]=arr[i];//��arr���ƭȬ�����buf
        
        if(arr[i]==0)//�X�{0����buf�n����0������
        {
            j++;//���k���@��A�g�J0
            if(j==arrSize)
            break;
            buf[j]=0;
        }
       
        j++;//���ܤU�@�Ӽg�J�I
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
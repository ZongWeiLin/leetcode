#include <stdio.h>
#include <stdlib.h>

int hammingDistance(int x, int y)
{
    //��XOR�⭫�ƪ������R��//
    int out=x^y;
    int counter=0;
    while (out!=0)
    {
        //�D���ƪ������A������bit�|�O1
        if(out&1)
            counter++;
        
        //�N�Ʀr������ traversal�Ҧ�bit
        out>>=1;
    }
    return counter;
}

int main(void)
{

    system("pause");
    return 0;
}
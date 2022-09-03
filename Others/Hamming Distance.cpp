#include <stdio.h>
#include <stdlib.h>

int hammingDistance(int x, int y)
{
    //用XOR把重複的部分刪掉//
    int out=x^y;
    int counter=0;
    while (out!=0)
    {
        //非重複的部分，對應的bit會是1
        if(out&1)
            counter++;
        
        //將數字左移來 traversal所有bit
        out>>=1;
    }
    return counter;
}

int main(void)
{

    system("pause");
    return 0;
}
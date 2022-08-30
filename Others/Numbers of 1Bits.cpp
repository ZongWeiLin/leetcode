#include <stdio.h>
#include <stdlib.h>

int hammingWeight(int n) 
{   
    int count=0;
    
    while(n>0)
    {
        if(n&1)
            count++;
        n>>=1;
    }

    return count;
}

int main(void)
{
    int a=0x008;

    int val=hammingWeight(a);

    printf("%d\n",val);

    system("pause");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int hammingWeight(int n) 
{   
    int count=0;
    
    //盢–计常籔1and狦程挡狦琌痷讽玡计1//
    //–讽笿计1じcount碞1//
    while(n>0)
    {
        if(n&1)
            count++;
        //讽玡じゑ癸Ч传秈︽ゑ癸//
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
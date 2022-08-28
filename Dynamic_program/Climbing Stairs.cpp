#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n)
{
    int next;
    int previous=1;
    int current=2;
    for(int i=2;i<n;i++)
    {
        next=previous+current;
        previous=current;
        current=next;
    }

    return next;
}

int main(void)
{
    int val=climbStairs(5);

    printf("%d\n",val);

    system("pause");
    return 0;
}
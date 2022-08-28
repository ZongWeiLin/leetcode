#include <stdio.h>
#include <stdlib.h>

bool isBadVersion(int n)
{
    if(n==4) return true;
    else return false;
}

int firstBadVersion(int n) 
{
    long end=n;
    long front=1;
    long mid;
    while(end>front)
    {
        mid=(front+end)/2;
        
        if(isBadVersion(mid))
        {
            end=mid;
        }
        else
        {
            front=mid+1;
        }
    }
    
    return front;
}

int main(void)
{
    int val=firstBadVersion(5);

    printf("%d\n",val);

    system("pause");
    return 0;
}
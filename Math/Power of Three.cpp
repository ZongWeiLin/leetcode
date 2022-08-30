#include <stdio.h>
#include <stdlib.h>


bool isPowerOfThree(int n)
{
    if(n<=0)
        return false;
    
    //另i為輸入的數字//
    int i=n;

    while(i>1)
    {
        //如果對3取餘數不為0，代表非3的次方//
        //回傳false//
        if(i%3!=0)
            return false;

        else
        {
        //如果是的話就除3//
            i=i/3;
        }
    }

    return true;
}

int main(void)
{
    int val=isPowerOfThree(387420489);

    printf("%d\n",val);

    system("pause");
    return 0;
}
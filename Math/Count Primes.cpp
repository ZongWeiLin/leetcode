#include <stdio.h>
#include <stdlib.h>

bool is_prime(int x)
{
    if(x<2)return 0;

    //透過試除法來判斷是否為質數//
    //只需要走道根號n即可//
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0) return false;//出現取餘數為0代表非質數
    }

    return true;//走完都還沒回傳，代表是質數
}


int countPrimes(int n)
{
    int count=0;
    if(n>2)count++;

    for(int i=3;i<n;i+=2)
    {
        if(is_prime(i)) count++;
    } 

    return count;
}


int main(void)
{
    int val=countPrimes(10);

    printf("%d\n",val);  
    system("pause");
    return 0;
}
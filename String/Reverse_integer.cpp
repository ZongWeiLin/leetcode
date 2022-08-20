#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//硂娩琌硓筁癸10緇计よΑㄓ秈︽计は锣//
int reverse(int x)
{   
    int rev=0;
    int mod;
    while(x!=0)
    {
        //ノㄓ耞琌overflow//
        if(rev>INT_MAX/10||rev<INT_MIN/10)
        return 0;
        
        //パ穦10┮overflow娩絫璶絋粄计计琌硑Θoverflow//
        else if (rev==INT_MAX/10||rev==INT_MIN/10)
        {
            if(x%10>7||x%10<-8)
            return 0;    
        }
        
        
        mod=x%10;
        rev=rev*10+mod;
        x=x/10;
    }

    return rev;
}

int main(void)
{
    int val=-123;

    int rev=reverse(val);
    printf("%d\n",rev);
    system("pause");
    return 0;
}
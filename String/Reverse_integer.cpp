#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//這邊是透過對10取餘數的方式，來進行數字反轉//
int reverse(int x)
{   
    int rev=0;
    int mod;
    while(x!=0)
    {
        //用來判斷是否為overflow的//
        if(rev>INT_MAX/10||rev<INT_MIN/10)
        return 0;
        
        //由於後面會乘10，所以在overflow邊緣時要確認個位數的數字，是否回造成overflow//
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
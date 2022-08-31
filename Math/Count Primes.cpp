#include <stdio.h>
#include <stdlib.h>


//method1//
//用試除法來確認每個數字是不是質數//
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


//method2//
//用埃拉托斯特尼篩法//
//透過把質數的倍數的數值剔除掉，來更快的篩取質數//
//用hash table來記錄//

int count_Primes_v2(int n)
{
    int count=0;
    char *hash=(char*)calloc(n+1,sizeof(char));
    int i,j;
    
    if(n>2)count++;

    //如果數字大於2的話，代表偶數的部分都可以篩掉了//
    //所以從3開始之後只需要考慮基數的部分//
    for(i=3;i<n;i+=2)
    {
        if(hash[i]!=true)
        {
            count++;
            for(j=i;j<n;j+=i)
            {
                hash[j]=true;
            }
        }
    }

    return count;
}

int main(void)
{
    int val=count_Primes_v2(3);

    printf("%d\n",val);  
    system("pause");
    return 0;
}
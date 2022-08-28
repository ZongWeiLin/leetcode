#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize)
{
    if(prices==NULL)
    return 0;
    
    int profit=0;
    int min=prices[0];
    for(int i=0;i<pricesSize;i++)
    {
        //用來找當前最小的值//
        if(prices[i]<min)
        min=prices[i];

        //計算
        if(prices[i]-min>profit)
        profit=prices[i]-min;
    }    

    return profit;
}

int main(void)
{
    int arr[6]={7,6,4,3,2,3};
    int val=maxProfit(arr,6);
    
    printf("%d\n",val);
    system("pause");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize)
{
    if(prices==NULL)return 0;

    int sum=0;
    for(int i=0;i<pricesSize-1;i++)
    {
        //比較隔天和當天的價格//
        //如果隔天價格大於當天就買入//
        if(prices[i]<prices[i+1])
        {
            sum+=prices[i+1]-prices[i];//計算隔天賣掉的獲利
        }
    }

    return sum;
}

int main(void)
{
    int arr[6]={1,2,1,4,5,6};

    int val=maxProfit(arr,6);

    printf("%d\n",val);

    system("pause");
    return 0;
}
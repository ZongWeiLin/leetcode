#include <stdio.h>
#include <stdlib.h>

int maxArea(int* height, int heightSize)
{
    int min_high=0;//紀錄左右指標哪個高度比較低
    int len;//紀錄左右index長度差
    int max_index=heightSize-1,min_index=0;//紀錄左右位置
    int max_area=0;


    //這題思路適用sliding window，加上動態規劃來解//
    //sliding window判斷方式是，看哪個比高度比較低，移動比較低的那個index//
    while(min_index<max_index)
    {
        min_high=(height[min_index]>height[max_index])?height[min_index]:height[max_index];
        
        len=max_index-min_index;
        max_area=((min_high*len)>max_area)?(min_high*len):max_area;

        if(height[min_index]<height[max_index])
            min_index++;
        else
            max_index--;
    }

    return max_area;
}


int main(void)
{

    system("pause");
    return 0;
}
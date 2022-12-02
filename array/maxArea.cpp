#include <stdio.h>
#include <stdlib.h>

int maxArea(int* height, int heightSize)
{
    int min_high=0;//�������k���Э��Ӱ��פ���C
    int len;//�������kindex���׮t
    int max_index=heightSize-1,min_index=0;//�������k��m
    int max_area=0;


    //�o�D����A��sliding window�A�[�W�ʺA�W���Ӹ�//
    //sliding window�P�_�覡�O�A�ݭ��Ӥ񰪫פ���C�A���ʤ���C������index//
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
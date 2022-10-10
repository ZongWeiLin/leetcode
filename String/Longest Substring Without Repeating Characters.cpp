#include <stdio.h>
#include <stdlib.h>


int lengthOfLongestSubstring(char * s)
{
    int max=0;
    char *start=s,*end=s;
    int letter_table[128]={0};//用來記錄那些字母有出現過(對應ASIC CODE)

    while (*end)
    {
        if(letter_table[*end])
        {
            max=((end-start)>max)?end-start:max;

            while (*start!=*end)//由於要移到下一個起點，所以要把之前出現字母的清掉//
            {
                letter_table[*start]=0;
                start++;
            }
            //移到下一個起點//
            end++;
            start++;
        }
        else//沒掃描到重複的狀況
        {
            letter_table[*end]=1;
            end++;
        }
    }

    return ((end-start)>max)?end-start:max;
}

int main(void)
{

    system("pause");
    return 0;
}
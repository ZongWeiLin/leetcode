#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//用來比較兩個字串是否相同*//
//只要有發現不相同的單字，馬上return false//
bool str_cmp(char *str1,char *str2)
{
    while (*str2)
    {
        if(*str1!=*str2)return false;
        str1++;
        str2++;
    }

    return true;
}


int strStr(char * haystack, char * needle)
{   
    int i;
    int hlen=strlen(haystack),nlen=strlen(needle);

  //haystack從頭開始跟needle比較，如果不相同換到下個位置繼續開始從頭比//     
    for(i=0;(i+nlen)<=hlen;i++)
    {
        if(str_cmp(haystack+i,needle))
            return i;
    }
    
    return -1;
}

int main(void)
{
    char *str1="aaaaa",*str2="bba";
    int val=strStr(str1,str2);

    printf("%d\n",val);

    system("pause");
    return 0;
}
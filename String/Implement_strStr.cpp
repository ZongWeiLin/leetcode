#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�ΨӤ����Ӧr��O�_�ۦP*//
//�u�n���o�{���ۦP����r�A���Wreturn false//
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

  //haystack�q�Y�}�l��needle����A�p�G���ۦP����U�Ӧ�m�~��}�l�q�Y��//     
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
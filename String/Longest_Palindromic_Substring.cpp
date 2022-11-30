#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* longestPalindrome(char * s)
{
    char *start,*end;
    char *p=s,*substring=s;
    int maxlen=1;

    while(*p)
    {
        start=p,end=p;

        while(*(end+1)&&(*end)==*(end+1))
        {
            end++;//移除重複的部分
        }

        p=end+1;

        //由中間往兩邊比對//
        while(*(end+1)&&start>s&&*(end+1)==*(start-1))
        {
            start--;
            end++;
        }

        if(end-start+1>maxlen)
        {
            substring=start;
            maxlen=end-start+1;
        }
    }

    char *ret_string=(char*)calloc(maxlen+1,sizeof(char));
    memcpy(ret_string,substring,maxlen);

    return ret_string;
}


int main(void)
{

    system("pause");
    return 0;
}
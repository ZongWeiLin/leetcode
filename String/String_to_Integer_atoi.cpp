#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<limits.h>

int myAtoi(char * s)
{ 
    int i=0;
    long long val=0;
    int sign_flag=1;
    int temp;
    
    
    //簿﹃獶场だ//
    while (s[i]==' ')
    {
        i++;
    }
    
    //耞钡ㄓ计タ璽腹//
    if (s[i]=='-')
    {
        i++;
        sign_flag=-1;
    }
    else if (s[i]=='+')
    {
        i++;
        sign_flag=1;
    }
    

    //狦钡ㄓ琌计璶秨﹍璸衡或计//
    while (s[i]>='0'&&s[i]<='9')
    {
        temp=s[i]-'0';
        val=val*10+temp;
         i++;
    
        if(val*sign_flag>=INT_MAX)
        {
            val=INT_MAX;
            break;
        }
        
        if(val*sign_flag<=INT_MIN)
        {
            val=INT_MIN;
            break;
        }
            
    }

    //程沮タ璽腹∕﹚return计タ璽//
    return val*sign_flag;
}

int main(void)
{
    char *str="words and 987";

    int val=myAtoi(str);

    printf("%d\n",val);

    system("pause");
    return 0;
}
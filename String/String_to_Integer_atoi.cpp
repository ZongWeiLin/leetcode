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
    
    
    //������r��D�Ů檺����//
    while (s[i]==' ')
    {
        i++;
    }
    
    //�P�_���U�ӼƦr�����t��//
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
    

    //�p�G���U�ӬO�Ʀr�A�n�}�l�p��᭱�N��ƻ�Ʀr//
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

    //�̫�ھڥ��t���A�M�wreturn�Ʀr�����t//
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
#include <stdio.h>
#include <stdlib.h>

char * longestCommonPrefix(char **strs, int strsSize)
{
    
    //�p�G�u���@�Ӧr��A�N��^�Ȧ������Ӧr��//
    if(strsSize==1)return strs[0];
    
    int i,j;
    char *ret_str=(char*)calloc(201,sizeof(char));
    char pre_char;


    for(j=0;;j++)
    {
        //�s���Ĥ@�Ӧr�ꪺ��j�Ӧr��//       
        pre_char=strs[0][j];

        for(i=1;i<strsSize;i++)
        {
            //�u�n�r�ꤤ���@�Ӥ��ۦP�A�N�N���ƪ������̪��N��o//
            if(strs[i][j]!=pre_char||strs[i][j]=='\0')
            return ret_str;
        }

        //�W���j�鳣�������ܡA�N��Ҧ��r���j�Ӧr���ҬۦP//
        ret_str[j]=pre_char;
    }    
}



int main(void)
{
    char *str[3]={"flower","flow","flight"};

    char *ret_str=longestCommonPrefix(str,3);

    printf("%s\n",ret_str);

    system("pause");
    return 0;
}
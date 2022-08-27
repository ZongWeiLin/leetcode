#include <stdio.h>
#include <stdlib.h>

char * longestCommonPrefix(char **strs, int strsSize)
{
    
    //如果只有一個字串，就返回僅有的那個字串//
    if(strsSize==1)return strs[0];
    
    int i,j;
    char *ret_str=(char*)calloc(201,sizeof(char));
    char pre_char;


    for(j=0;;j++)
    {
        //存取第一個字串的第j個字元//       
        pre_char=strs[0][j];

        for(i=1;i<strsSize;i++)
        {
            //只要字串中有一個不相同，就代表重複的部分最長就到這//
            if(strs[i][j]!=pre_char||strs[i][j]=='\0')
            return ret_str;
        }

        //上面迴圈都走完的話，代表所有字串第j個字元皆相同//
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
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

bool isAnagram(char * s, char * t)
{
    int hash_s[26]={0};
    int hash_t[26]={0};

    int i=0;
    //紀錄兩個string各個單字出現次數//
    while(s[i]!='\0')
    {
        hash_s[s[i]-'a']++;
        i++;
    }

    i=0;
    while(t[i]!='\0')
    {
        hash_t[t[i]-'a']++;
        i++;
    }

    //比較兩個string的hash table，各個單字出現次數//
    //如果有一個不同，代表兩個字串構成單字是不同的//
    for(i=0;i<26;i++)
    {
        if(hash_s[i]!=hash_t[i])
        return false;
    }

    return true;

}

int main(void)
{
    char *str1="rat";
    char *str2="tar";

    int val=isAnagram(str1,str2);

    printf("%d\n",val);

    system("pause");
    return 0;
}
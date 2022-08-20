#include <stdio.h>
#include <stdlib.h>
#include<string.h>

bool isAnagram(char * s, char * t)
{
    int hash_s[26]={0};
    int hash_t[26]={0};

    int i=0;
    //�������string�U�ӳ�r�X�{����//
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

    //������string��hash table�A�U�ӳ�r�X�{����//
    //�p�G���@�Ӥ��P�A�N���Ӧr��c����r�O���P��//
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
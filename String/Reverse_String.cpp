#include <stdio.h>
#include <stdlib.h>
#define swap(x,y){char temp;temp=x;x=y;y=temp;}

//����2����䤤���I�A�H�����I����ǡA�e��}�C�����i��swap//
int reverseString(char* s, int sSize)
{
    int mid=sSize/2;
    int remainder=sSize%2;
    //�̷Ӧr����ׯण��P2�㰣�A�����2��case//
    
    //��㰣���A�ѩ󬰥��������k���@��A�ҥH�bswap�ɷ|�h�@�檺bias//
    if(remainder==0)
    {
        for(int i=0;i<mid;i++)
        {
        swap(s[mid+i],s[mid-i-1]);
        }
    }
    
    //����㰣���A��n�n�������I�A�̷ӥ������I�ⰼ�i��洫�Y�i//
    if(remainder==1)
    {
        for(int i=0;i<=mid;i++)
        {
            swap(s[mid+i],s[mid-i]);
        }
    }

    return mid;
}

int main(void)
{
    char string[5]={'H','e','l','l'};

    int val=reverseString(string,4);

    printf("%s\n",string);
    printf("%d\n",val);
    system("pause");
    return 0;
}
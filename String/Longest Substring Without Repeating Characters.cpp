#include <stdio.h>
#include <stdlib.h>


int lengthOfLongestSubstring(char * s)
{
    int max=0;
    char *start=s,*end=s;
    int letter_table[128]={0};//�ΨӰO�����Ǧr�����X�{�L(����ASIC CODE)

    while (*end)
    {
        if(letter_table[*end])
        {
            max=((end-start)>max)?end-start:max;

            while (*start!=*end)//�ѩ�n����U�@�Ӱ_�I�A�ҥH�n�⤧�e�X�{�r�����M��//
            {
                letter_table[*start]=0;
                start++;
            }
            //����U�@�Ӱ_�I//
            end++;
            start++;
        }
        else//�S���y�쭫�ƪ����p
        {
            letter_table[*end]=1;
            end++;
        }
    }

    return ((end-start)>max)?end-start:max;
}

int main(void)
{

    system("pause");
    return 0;
}
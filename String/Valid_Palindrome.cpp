#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�n�T�{���S���^��A�z�L�e��U�]�m�@�ӫ���//
//����z�L�e����Ы��V���e���A�ݬO�_�ۦP�o�˨ӽT�{���L�^��//
bool isPalindrome(char *s)
{
    int len=strlen(s),i=0,j=len-1;
    int temp1,temp2;

    if(len==1||len==0)
    return true;
    
    while(i<j)
    {
        //�p�G�O�j�p�g��rA~Z�A�μƦr1~9�~����//
        if(s[i]>='A'&&s[i]<='Z'||s[i]>='a'&&s[i]<='z'||s[i]>='0'&&s[i]<='9')
        {
            temp1=s[i];

            if(s[i]>='A'&&s[i]<='Z')
            temp1+=32;
        }
        else
        {
            //���O���ܩ�array���U�@��
            i++;
            continue;//�����o��N�����o���j��
        }

        if(s[j]>='A'&&s[j]<='Z'||s[j]>='a'&&s[j]<='z'||s[j]>='0'&&s[j]<='9')
        {
            temp2=s[j];
            if(s[j]>='A'&&s[j]<='Z')
            temp2+=32;
        }
        else
        {
            j--;
            continue;//�����o��N�����o���j��
        }

        //����e�᪺�r��//
        if(temp1!=temp2)return false;

        i++;
        j--;
    }

    return true;
}

int main(void)
{   
    char *str="abcd";

    int val=isPalindrome(str);

    printf("%d\n",val);

    system("pause");
    return 0;
}
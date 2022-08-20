#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//要確認有沒有回文，透過前後各設置一個指標//
//之後透過前後指標指向內容比對，看是否相同這樣來確認有無回文//
bool isPalindrome(char *s)
{
    int len=strlen(s),i=0,j=len-1;
    int temp1,temp2;

    if(len==1||len==0)
    return true;
    
    while(i<j)
    {
        //如果是大小寫單字A~Z，或數字1~9才紀錄//
        if(s[i]>='A'&&s[i]<='Z'||s[i]>='a'&&s[i]<='z'||s[i]>='0'&&s[i]<='9')
        {
            temp1=s[i];

            if(s[i]>='A'&&s[i]<='Z')
            temp1+=32;
        }
        else
        {
            //不是的話往array的下一格
            i++;
            continue;//執行到這邊就結束這次迴圈
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
            continue;//執行到這邊就結束這次迴圈
        }

        //表較前後的字母//
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
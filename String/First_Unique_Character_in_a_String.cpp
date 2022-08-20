#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//這邊是用hash的方式去紀錄各個字母出現的位置//
int firstUniqChar(char * s)
{
    int i=0;
    int record[26];//用來記錄26個字母出現的位置//
    memset(record,-1,sizeof(int)*26);//將記錄位置初始化數值都設-1//
    
    int index;
    
    while(s[i]!='\0')
    {
        index=s[i]-'a';
        
        //如果這個字母已經出現過，對應index數字會大於0//
        //把它設成-2代表有重複出現過了//
        if(record[index]>=0)
            record[index]=-2;
        
        //如果對應字母對應index為-1，代表還沒出現過//
        if(record[index]==-1)
        record[index]=i;
        
        i++;
    }


    index=i;
    for(int j=0;j<26;j++)
    {
        //找記錄各個字母出現位置大於0，並且又是最小的//
        if(record[j]>=0&&record[j]<index)
        {
            index=record[j];
        }
    }

    if(index==i)return -1;

    return index;

}


int main(void)
{
    char *str="itwqbtcdprfsuprkrjkausiterybzncbmdvkgljxuekizvaivszowqtmrttiihervpncztuoljftlxybpgwnjb";
    int val=firstUniqChar(str);
    printf("%d\n",val);
    system("pause");
    return 0;
}
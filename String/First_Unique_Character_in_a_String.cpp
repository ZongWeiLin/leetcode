#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//�o��O��hash���覡�h�����U�Ӧr���X�{����m//
int firstUniqChar(char * s)
{
    int i=0;
    int record[26];//�ΨӰO��26�Ӧr���X�{����m//
    memset(record,-1,sizeof(int)*26);//�N�O����m��l�Ƽƭȳ��]-1//
    
    int index;
    
    while(s[i]!='\0')
    {
        index=s[i]-'a';
        
        //�p�G�o�Ӧr���w�g�X�{�L�A����index�Ʀr�|�j��0//
        //�⥦�]��-2�N�����ƥX�{�L�F//
        if(record[index]>=0)
            record[index]=-2;
        
        //�p�G�����r������index��-1�A�N���٨S�X�{�L//
        if(record[index]==-1)
        record[index]=i;
        
        i++;
    }


    index=i;
    for(int j=0;j<26;j++)
    {
        //��O���U�Ӧr���X�{��m�j��0�A�åB�S�O�̤p��//
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
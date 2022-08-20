#include <stdio.h>
#include <stdlib.h>
#define swap(x,y){char temp;temp=x;x=y;y=temp;}

//先除2之後找中間點，以中間點為基準，前後陣列元素進行swap//
int reverseString(char* s, int sSize)
{
    int mid=sSize/2;
    int remainder=sSize%2;
    //依照字串長度能不能與2整除，能分成2個case//
    
    //能整除的，由於為正中間往右偏一格，所以在swap時會多一格的bias//
    if(remainder==0)
    {
        for(int i=0;i<mid;i++)
        {
        swap(s[mid+i],s[mid-i-1]);
        }
    }
    
    //不能整除的，剛好要正中間點，依照正中間點兩側進行交換即可//
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
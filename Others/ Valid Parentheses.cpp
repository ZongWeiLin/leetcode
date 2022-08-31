#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//這題是透過Stack//
//當是左括號時，就把括號丟到stack裡面//
//當是右括號時，就確認stack最上面的字元，看是不是對應的右括號//
//判斷方式可以通過ASCII CODE可以知道，右括號會比左括號大1或2//
//最後確認stack是否是空的，可以知道是否是每個括號都成對//
bool isValid(char * s)
{
    int i=0;
    int len=strlen(s);
    int top=0;
    char *stack=(char*)calloc(len,sizeof(char));
    
    while(s[i]!='\0')
    {
       if(s[i]=='{'||s[i]=='['||s[i]=='(')
        {
            stack[top]=s[i];
            top++;
        }
        else if(top>0)
        {
            if(s[i]-stack[top-1]==1||s[i]-stack[top-1]==2)//從ASCII CODE可以知道，左括號和右括號只有前後差1或2//
                top--;
            else 
                return false;//當出現不對稱的，就直接回傳 false。
        }
        else if(top==0)
            return false;//當一個括號就是右括號，回傳false。
        i++;
    }

    if(top!=0) return false;
    else return true;
}


int main(void)
{
    char *str={"{()}"};

    int val=isValid(str);
    printf("%d\n",val);
    system("pause");
    return 0;
}